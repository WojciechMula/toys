package main

import (
	"fmt"
)

func printprogram(v uint32, cp *ConstantPool) {
	p := programprinter{cp: cp}
	p.printprogram(v)
}

type programprinter struct {
	cp *ConstantPool
	id int
}

func (p *programprinter) allocate() int {
	res := p.id
	p.id += 1
	return res
}

func (p *programprinter) printprogram(v uint32) string {
	prog, ok := p.cp.vals[v]
	if !ok {
		panic(fmt.Sprintf("wrong data, the program for %x not found", v))
	}

	image := make([]string, 0, len(prog.args)+1)
	image = append(image, prog.name)
	for i := range prog.args {
		switch arg := prog.args[i].(type) {
		case uint32:
			image = append(image, p.printprogram(arg))
		case int:
			image = append(image, fmt.Sprintf("%d", prog.args[i]))
		case string:
			image = append(image, arg)
		default:
			panic(fmt.Sprintf("type %T not supported", prog.args[i]))
		}
	}

	fmt.Printf("/* %08x */ %s\n", prog.value, image)

	return fmt.Sprintf("ZMM%d", p.allocate())
}
