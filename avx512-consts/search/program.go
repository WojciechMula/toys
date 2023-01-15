package main

import (
	"fmt"
	"strconv"
	"strings"

	"golang.org/x/exp/slices"
)

type Program struct {
	name  string // unique name of instruction (might be empty)
	value uint32 // what value this program produces
	args  []any  // uint32 or int
}

func (p *Program) AppendToString(b *strings.Builder) {
	b.WriteString(fmt.Sprintf("0x%08x=", p.value))
	b.WriteString(p.name)
	b.WriteString(" ")
	for i, arg := range p.args {
		if i > 0 {
			b.WriteString(" ")
		}
		switch v := arg.(type) {
		case int:
			b.WriteString(fmt.Sprintf("%d", v))
		case uint32:
			b.WriteString(fmt.Sprintf("0x%08x", v))
		case string:
			b.WriteString(v)
		default:
			panic(fmt.Sprintf("unsupported type %T", arg))
		}
	}
}

func (p *Program) String() string {
	var b strings.Builder
	p.AppendToString(&b)
	return b.String()
}

func (p *Program) cost() int {
	return 1
}

func (p *Program) clone() *Program {
	return &Program{
		value: p.value,
		name:  p.name,
		args:  slices.Clone(p.args),
	}
}

func (p *Program) serialize() string {
	return p.String()
}

func deserialize(s string) (*Program, error) {
	p := new(Program)
	value, rest, ok := strings.Cut(s, "=")
	if !ok {
		return nil, fmt.Errorf("wrong syntax: missing '='")
	}

	if u32, ok := parseu32(value); ok {
		p.value = u32
	} else {
		return nil, fmt.Errorf("wrong syntax: first field has to be an uint32")
	}

	args := strings.Split(rest, " ")
	p.name = args[0]
	p.args = make([]any, len(args)-1)
	args = args[1:]
	for i := range args {
		u32, ok := parseu32(args[i])
		if ok {
			p.args[i] = u32
		} else {
			p.args[i] = args[i]
		}
	}

	return p, nil
}

func parseu32(s string) (uint32, bool) {
	if len(s) != 10 {
		return 0, false
	}

	if !strings.HasPrefix(s, "0x") {
		return 0, false
	}

	u64, err := strconv.ParseUint(s[2:], 16, 32)
	if err != nil {
		return 0, false
	}

	return uint32(u64), true
}
