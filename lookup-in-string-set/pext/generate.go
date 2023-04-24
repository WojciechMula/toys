package main

import (
	"bytes"
	"fmt"
	"strings"
)

type Program interface {
	write(ctx *generateContext)
	lookupSize() int
	evaluate([]byte) uint64
}

func compile(mask []byte) Program {
	count := func() int {
		k := 0
		for _, b := range mask {
			if b != 0 {
				k++
			}
		}
		return k
	}

	load := func(idx, size int) int {
		k := 0
		for i := 0; i < size; i++ {
			if mask[idx+i] != 0 {
				k++
			}
		}

		return k
	}

	commit := func(idx, size int) {
		for i := 0; i < size; i++ {
			mask[idx+i] = 0
		}
	}

	loadSizes := []int{8, 4, 2, 1}
	var loads []*Load
	for {
		active := count()
		if active == 0 {
			break
		}

		if active == 1 {
			for i, b := range mask {
				if b != 0 {
					loads = append(loads, &Load{
						index: i,
						size:  1,
						mask:  uint64(b),
					})
					break
				}
			}
			break
		}

		for _, size := range loadSizes {
			if size > len(mask) {
				continue
			}

			bestCount := 0
			bestIdx := 0
			for i := 0; i < len(mask)-size+1; i++ {
				if k := load(i, size); k > bestCount {
					bestCount = k
					bestIdx = i
				}
			}

			if bestCount > 0 {
				l := &Load{
					index: bestIdx,
					size:  size,
				}
				for i := 0; i < size; i++ {
					l.mask |= uint64(mask[bestIdx+i]) << (i * 8)
				}

				loads = append(loads, l)
				commit(bestIdx, size)
				break
			}
		}
	}

	switch {
	case len(loads) == 1:
		for {
			l := loads[0].trim()
			if l == nil {
				break
			}

			loads[0] = l
		}

		return loads[0]

	case len(loads) == 2:
		first := loads[0]
		second := loads[1]

		var m *Merge

		trimmed := first
		for trimmed != nil {
			tmp := newMerge(trimmed, second)
			if tmp != nil {
				m = tmp
			}

			trimmed = trimmed.trim()
		}

		if m != nil {
			return m
		}
	}

	return newCombine(loads)
}

type generateCpp struct {
	programs map[int]Program
	lookups  map[int]*Lookup
	ctx      generateContext
}

type generateContext struct {
	basename string
	argname  string
	defval   string
	valtype  string
	idx      int

	indent int
	output *bytes.Buffer
}

func (g *generateCpp) write() {
	max := 0
	for size := range g.programs {
		if size > max {
			max = size
		}
	}

	g.ctx.writeln("#include <cstdint>")
	g.ctx.writeln("#include <cstring>")
	g.ctx.writeln("#include <string_view>")
	g.ctx.writeln("#include <immintrin.h>")
	g.ctx.writeln("//lookup: name=%s, dataset=%s", g.ctx.lookupName(), g.ctx.basename)
	g.ctx.writeln("%s {", g.ctx.lookupSignature())
	g.ctx.indent += 4
	{
		g.ctx.writeln("switch (%s.size()) {", g.ctx.argname)
		g.ctx.indent += 4
		for size := 0; size <= max; size++ {
			prog, ok := g.programs[size]
			if !ok {
				continue
			}

			g.ctx.writeln("case %d: {", size)
			g.ctx.indent += 4
			g.lookups[size].write(&g.ctx)
			prog.write(&g.ctx)
			g.ctx.indent -= 4
			g.ctx.writeln("}")
		}
		g.ctx.indent -= 4
		g.ctx.writeln("}")
		g.ctx.writeln("return %s;", g.ctx.defval)
	}
	g.ctx.indent -= 4
	g.ctx.writeln("}")

	g.ctx.writeln("")

	g.ctx.writeln("#include <cassert>")
	g.ctx.writeln("//check: name=%s, dataset=%s", g.ctx.checkName(), g.ctx.basename)
	g.ctx.writeln("%s ) {", g.ctx.checkSignature())
	g.ctx.indent += 4
	{
		for _, lookup := range g.lookups {
			for _, kw := range lookup.words {
				g.ctx.writeln("assert(lookup_%s(%q) == %s);", g.ctx.basename, kw.word, kw.value)
			}
		}
	}
	g.ctx.indent -= 4
	g.ctx.writeln("}")

	g.ctx.writeln("")
}

func (c *generateContext) lookupName() string {
	return fmt.Sprintf("lookup_%s", strings.ReplaceAll(c.basename, "-", "_"))
}

func (c *generateContext) checkName() string {
	return fmt.Sprintf("check_%s", strings.ReplaceAll(c.basename, "-", "_"))
}

func (c *generateContext) lookupSignature() string {
	return fmt.Sprintf("%s %s(std::string_view %s)", c.valtype, c.lookupName(), c.argname)
}

func (c *generateContext) checkSignature() string {
	return fmt.Sprintf("void %s()", c.checkName())
}

func (c *generateContext) writeln(format string, args ...any) {
	c.output.WriteString(strings.Repeat(" ", c.indent))
	fmt.Fprintf(c.output, format, args...)
	c.output.WriteRune('\n')
}

func (c *generateContext) cast(args ...int) int {
	max := 1
	for _, size := range args {
		switch size {
		case 8:
			return 8
		case 1, 2, 4:
			if max < size {
				max = size
			}
		default:
			panic(fmt.Sprintf("wrong size = %d", size))
		}
	}

	return max
}

func (c *generateContext) typ(size int) string {
	switch size {
	case 8:
		return "uint64_t"
	case 4:
		return "uint32_t"
	case 2:
		return "uint16_t"
	case 1:
		return "uint8_t"
	}

	panic(fmt.Sprintf("wrong size = %d", size))
}

func (c *generateContext) variable(size int) (string, string) {
	v := fmt.Sprintf("w%d", c.idx)
	c.idx++
	return c.typ(size), v
}
