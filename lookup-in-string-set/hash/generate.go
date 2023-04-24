package main

import (
	"bytes"
	"fmt"
	"os"
	"strings"
)

type generateContext struct {
	basename   string
	hashfn     string
	argname    string
	valtype    string
	defval     string
	lookup     [][]byte
	values     []string
	collisions int

	output *bytes.Buffer
	indent int
}

func (c *generateContext) lookupName() string {
	return fmt.Sprintf("lookup_%s_%s", strings.ReplaceAll(c.basename, "-", "_"), c.hashfn)
}

func (c *generateContext) checkName() string {
	return fmt.Sprintf("check_%s_%s", strings.ReplaceAll(c.basename, "-", "_"), c.hashfn)
}

func (c *generateContext) lookupSignature() string {
	return fmt.Sprintf("%s %s(std::string_view %s)", c.valtype, c.lookupName(), c.argname)
}

func (c *generateContext) checkSignature() string {
	return fmt.Sprintf("void %s()", c.checkName())
}

func (c *generateContext) writeln(f string, args ...any) {
	o := c.output
	o.WriteString(strings.Repeat(" ", c.indent))
	fmt.Fprintf(o, f, args...)
	o.WriteRune('\n')
}

func (c *generateContext) emptyline() {
	c.output.WriteRune('\n')
}

func generateFunction(ctx *generateContext) error {
	if len(ctx.output.Bytes()) == 0 {
		common, err := os.ReadFile("header.cpp.in")
		if err != nil {
			return err
		}
		ctx.output.Write(common)
	}

	// lookup function
	ctx.emptyline()
	ctx.writeln("//lookup: name=%s, dataset=%s, hash=%s", ctx.lookupName(), ctx.basename, ctx.hashfn)
	ctx.writeln("%s {", ctx.lookupSignature())
	ctx.indent += 4
	{
		ctx.writeln("const uint64_t idx = %s(%s) * %d;", ctx.hashfn, ctx.argname, ctx.collisions)
		ctx.writeln("static std::string_view lookup[%d] = {", len(ctx.lookup))
		ctx.indent += 4
		for _, w := range ctx.lookup {
			ctx.writeln("%q,", w)
		}
		ctx.indent -= 4
		ctx.writeln("};")

		ctx.writeln("static %s values[%d] = {", ctx.valtype, len(ctx.lookup))
		ctx.indent += 4
		for _, s := range ctx.values {
			if s != "" {
				ctx.writeln("%s,", s)
			} else {
				ctx.writeln("%s,", ctx.defval)
			}
		}
		ctx.indent -= 4
		ctx.writeln("};")

		ctx.writeln("for (int i=0; i < %d; i++) {", ctx.collisions)
		ctx.indent += 4
		{
			ctx.writeln("if (lookup[idx + i] == %s) {", ctx.argname)
			ctx.indent += 4
			{
				ctx.writeln("return values[idx + i];")
			}
			ctx.indent -= 4
			ctx.writeln("}")
		}
		ctx.indent -= 4
		ctx.writeln("}")
		ctx.writeln("return %s;", ctx.defval)
	}
	ctx.indent -= 4
	ctx.writeln("}")

	// check function
	ctx.emptyline()
	ctx.writeln("//check: name=%s, dataset=%s, hash=%s", ctx.checkName(), ctx.basename, ctx.hashfn)
	ctx.writeln("%s {", ctx.checkSignature())
	ctx.indent += 4
	{
		name := ctx.lookupName()
		for i := range ctx.lookup {
			if ctx.values[i] != "" {
				ctx.writeln("assert(%s(%q) == %d);", name, ctx.lookup[i], ctx.values[i])
			}
		}
	}
	ctx.indent -= 4
	ctx.writeln("}")

	return nil
}
