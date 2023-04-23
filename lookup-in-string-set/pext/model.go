package main

import (
	"encoding/binary"
	"fmt"
	"math/bits"
	"strings"
)

type Lookup struct {
	words   []Keyword // list of words of given size
	indices []int     // lookup indices (-1 means absent)
}

func (l *Lookup) write(ctx *generateContext) {
	var buf strings.Builder

	ctx.writeln("static char lookup[%d][%d] = {", len(l.indices), len(l.words[0].word))
	ctx.indent += 4
	for _, idx := range l.indices {
		if idx == -1 {
			ctx.writeln("{}, // no match")
		} else {
			buf.Reset()
			for i, b := range l.words[idx].word {
				if i > 0 {
					buf.WriteString(", ")
				}
				fmt.Fprintf(&buf, "'%c'", b)
			}
			ctx.writeln("{%s},", buf.String())
		}
	}
	ctx.indent -= 4
	ctx.writeln("};")

	ctx.writeln("static char value[%d] = {", len(l.indices))
	ctx.indent += 4
	for _, idx := range l.indices {
		if idx == -1 {
			ctx.writeln("%s,", ctx.defval)
		} else {
			ctx.writeln("%s,", l.words[idx].value)
		}
	}
	ctx.indent -= 4
	ctx.writeln("};")
}

// Load represents loading a machine word
type Load struct {
	index int
	size  int // 1, 2, 4 or 8
	mask  uint64

	// set during write
	v, t string
}

func writeResult(ctx *generateContext, varname string, mask uint64) {
	ctx.writeln("const uint64_t idx = _pext_u64(%s, 0x%x);", varname, mask)
	ctx.writeln("if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {")
	ctx.indent += 4
	ctx.writeln("return value[idx];")
	ctx.indent -= 4
	ctx.writeln("}")
}

func (l *Load) writeLoad(ctx *generateContext) {
	l.t, l.v = ctx.variable(l.size)
	if l.size == 1 {
		ctx.writeln("const %s %s = %s[%d];", l.t, l.v, ctx.argname, l.index)
	} else {
		ctx.writeln("%s %s = 0;", l.t, l.v)
		ctx.writeln("memcpy(&%s, &%s[%d], %d);", l.v, ctx.argname, l.index, l.size)
	}
}

func (l *Load) write(ctx *generateContext) {
	l.writeLoad(ctx)
	writeResult(ctx, l.v, l.mask)
}

func (l *Load) lookupSize() int {
	return bits.OnesCount64(l.mask)
}

func (l *Load) load(word []byte) uint64 {
	switch l.size {
	case 1:
		return uint64(word[l.index])
	case 2:
		return uint64(binary.LittleEndian.Uint16(word[l.index:]))
	case 4:
		return uint64(binary.LittleEndian.Uint32(word[l.index:]))
	case 8:
		return binary.LittleEndian.Uint64(word[l.index:])
	default:
		panic("wrong size")
	}
}

func (l *Load) evaluate(word []byte) uint64 {
	q := l.load(word)
	return pdep(q, l.mask)
}

func (l *Load) trim() *Load {
	switch l.size {
	case 8:
		if l.mask&0xffffffff == 0 {
			return &Load{
				index: l.index + 4,
				size:  4,
				mask:  l.mask >> 32,
			}
		}

	case 4:
		if l.mask&0xffff == 0 {
			return &Load{
				index: l.index + 2,
				size:  2,
				mask:  l.mask >> 16,
			}
		}

	case 2:
		if l.mask&0xff == 0 {
			return &Load{
				index: l.index + 1,
				size:  1,
				mask:  l.mask >> 8,
			}
		}
	}

	return nil
}

// Merge represents two loads whose masks are disjoint
type Merge struct {
	first, second *Load
}

func newMerge(l1, l2 *Load) *Merge {
	canmerge := func(l1, l2 *Load) bool {
		if l1 == nil || l2 == nil {
			return false
		}

		if l1.mask&l2.mask == 0 {
			return true
		}

		return false
	}

	if canmerge(l1, l2) {
		return &Merge{first: l1, second: l2}
	}

	return nil
}

func (m *Merge) write(ctx *generateContext) {
	ctx.writeln("// merge")
	m.first.writeLoad(ctx)
	m.second.writeLoad(ctx)

	cast := ctx.cast(m.first.size, m.second.size)
	t, v := ctx.variable(cast)

	ctx.writeln("const %s %s = (%s(%s) & 0x%x) | (%s(%s) & 0x%x);",
		t, v,
		t, m.first.v, m.first.mask,
		t, m.second.v, m.second.mask)

	writeResult(ctx, v, m.first.mask|m.second.mask)
}

func (m *Merge) lookupSize() int {
	return bits.OnesCount64(m.first.mask | m.second.mask)
}

func (m *Merge) evaluate(word []byte) uint64 {
	q0 := m.first.load(word)
	q1 := m.second.load(word)

	q0 &= m.first.mask
	q1 &= m.second.mask

	q := q0 | q1

	return pdep(q, m.first.mask|m.second.mask)
}

// Combine is a series of loads that has to form up to a 64-bit word when concatenated.
type Combine struct {
	size  int
	loads []*Load
}

func (c *Combine) write(ctx *generateContext) {
	t, v := ctx.variable(c.size)

	ctx.writeln("// combine %d loads", len(c.loads))
	ctx.writeln("%s %s;", t, v)
	shift := 0
	for i := range c.loads {
		c.loads[i].writeLoad(ctx)
		if i == 0 {
			ctx.writeln("%s = %s(%s);", v, t, c.loads[i].v)
		} else {
			ctx.writeln("%s |= (%s(%s) << %d);", v, t, c.loads[i].v, shift)
		}

		shift += 8 * c.loads[i].size
	}

	writeResult(ctx, v, c.mask())
}

func (c *Combine) lookupSize() int {
	n := 0
	for i := range c.loads {
		n += bits.OnesCount64(c.loads[i].mask)
	}
	return n
}

func (c *Combine) mask() uint64 {
	mask := uint64(0)
	shift := 0
	for _, load := range c.loads {
		mask |= load.mask << shift
		shift += 8 * load.size
	}

	return mask
}

func (c *Combine) evaluate(word []byte) uint64 {
	q := uint64(0)
	m := uint64(0)
	shift := 0
	for _, load := range c.loads {
		qi := load.load(word)
		mi := load.mask

		q |= qi << shift
		m |= mi << shift

		shift += 8 * load.size
	}

	return pdep(q, m)
}

func newCombine(loads []*Load) *Combine {
	total := 0
	for i := range loads {
		total += int(loads[i].size)
	}

	if total > 8 {
		panic(fmt.Sprintf("the program will not fit in single 64-bit word (requires %d bytes)", total))
	}

	size := 8
	if total < 4 {
		size = 4
	}

	return &Combine{
		loads: loads,
		size:  size,
	}
}
