package main

type ConstantPool struct {
	vals map[uint32]*Program
}

func NewConstantPool() *ConstantPool {
	return &ConstantPool{
		vals: make(map[uint32]*Program),
	}
}

func (c *ConstantPool) reset() {
	c.vals = make(map[uint32]*Program)
}

func (c *ConstantPool) size() int {
	return len(c.vals)
}

func (c *ConstantPool) add(p *Program) {
	c.vals[p.value] = p
}

const noValueCost = 1_000_000

func (c *ConstantPool) valueCost(v uint32) int {
	prog, ok := c.vals[v]
	if !ok {
		return noValueCost
	}

	return c.programCost(prog)
}

func (c *ConstantPool) programCost(prog *Program) int {
	result := prog.cost()
	for _, arg := range prog.args {
		val, ok := arg.(uint32)
		if !ok {
			continue
		}

		result += c.valueCost(val)
	}

	return result
}
