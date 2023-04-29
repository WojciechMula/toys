package main

import (
	"bytes"
	"fmt"
	"strings"
)

type generateContext struct {
	basename string
	argname  string
	valtype  string
	defval   string

	linearSearchThreshold int

	output    *bytes.Buffer
	indentval int
}

func (c *generateContext) lookupName() string {
	return fmt.Sprintf("lookup_%s_split", strings.ReplaceAll(c.basename, "-", "_"))
}

func (c *generateContext) checkName() string {
	return fmt.Sprintf("check_%s_split", strings.ReplaceAll(c.basename, "-", "_"))
}

func (c *generateContext) lookupSignature() string {
	return fmt.Sprintf("%s %s(std::string_view %s)", c.valtype, c.lookupName(), c.argname)
}

func (c *generateContext) checkSignature() string {
	return fmt.Sprintf("void %s()", c.checkName())
}

func (c *generateContext) writeln(f string, args ...any) {
	c.output.WriteString(strings.Repeat(" ", c.indentval))
	fmt.Fprintf(c.output, f, args...)
	c.output.WriteRune('\n')
}

func (c *generateContext) emptyline() {
	c.output.WriteRune('\n')
}

func (c *generateContext) indent() {
	c.indentval += 4
}

func (c *generateContext) pop() {
	c.indentval -= 4
}

func generateFunction(buf *bytes.Buffer, basename string, words []Keyword) {
	ctx := &generateContext{
		basename:              basename,
		argname:               "s",
		valtype:               "int",
		defval:                "-1",
		output:                buf,
		linearSearchThreshold: 3,
	}

	generateFunctionAux(ctx, words)
}

func generateFunctionAux(ctx *generateContext, words []Keyword) {
	bylen := make(map[int]*[]Keyword)
	for i := range words {
		n := len(words[i].word)
		list, ok := bylen[n]
		if !ok {
			list = new([]Keyword)
			bylen[n] = list
		}

		*list = append(*list, words[i])
	}

	min := 1_000_000
	max := -1
	for size := range bylen {
		if size > max {
			max = size
		}
		if size < min {
			min = size
		}
	}

	ctx.writeln("//lookup: dataset=%s, name=%s, type=split", ctx.basename, ctx.lookupName())
	ctx.writeln("%s {", ctx.lookupSignature())
	ctx.indent()
	ctx.writeln("switch (%s.size()) {", ctx.argname)
	ctx.indent()
	for size := min; size <= max; size++ {
		list := bylen[size]
		if list == nil {
			continue
		}

		ctx.writeln("case %d: {", size)
		ctx.indent()
		generateSwitch(ctx, *list, []int{})
		ctx.pop()
		ctx.writeln("}")
		ctx.writeln("break;")
	}
	ctx.pop()
	ctx.writeln("}")
	ctx.writeln("return %s;", ctx.defval)
	ctx.pop()
	ctx.writeln("}")

	ctx.emptyline()
	ctx.writeln("//check: dataset=%s, name=%s, type=split", ctx.basename, ctx.checkName())
	ctx.writeln("%s {", ctx.checkSignature())
	ctx.indent()
	{
		name := ctx.lookupName()
		for _, kw := range words {
			ctx.writeln("assert(%s(%q) == %s);", name, kw.word, kw.value)
		}
	}
	ctx.pop()
	ctx.writeln("}")
}

func generateSwitch(ctx *generateContext, words []Keyword, usedPositions []int) {
	if len(words) < ctx.linearSearchThreshold {
		for i := range words {
			ctx.writeln("if (%s == %q) {", ctx.argname, words[i].word)
			{
				ctx.indent()
				ctx.writeln("return %s;", words[i].value)
				ctx.pop()
			}
			ctx.writeln("}")
		}
		return
	}

	position := findSplitByPosition(words, usedPositions)
	if position == -1 {
		panic("cannot split words; please fill the issue")
	}

	ctx.writeln("switch (%s[%d]) {", ctx.argname, position)
	ctx.indent()
	subsets := splitBy(words, position)
	usedPositions = append(usedPositions, position)
	for i := range subsets {
		ctx.writeln("case '%c': { // 0x%02x", subsets[i].chr, subsets[i].chr)
		ctx.indent()
		generateSwitch(ctx, subsets[i].words, usedPositions)
		ctx.pop()
		ctx.writeln("}")
		ctx.writeln("break;")
	}

	ctx.pop()
	ctx.writeln("}")
}
