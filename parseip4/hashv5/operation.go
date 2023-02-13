package main

type Function int

const (
	add Function = iota
	sub
	xor
)

func (f Function) eval(a, b uint16) uint16 {
	switch f {
	case add:
		return a + b

	case sub:
		return a - b

	case xor:
		return a ^ b
	}

	panic("wrong operation")
}

func (f Function) String() string {
	switch f {
	case add:
		return "+"

	case sub:
		return "-"

	case xor:
		return "^"
	}

	return "?"
}

type Operation struct {
	f1, f2, f3 Function
}

func (op *Operation) eval(a, b, c, d uint16) uint16 {
	v := op.f1.eval(a, b)
	v = op.f2.eval(v, c)
	v = op.f3.eval(v, d)

	return v
}

var allFuncs = []Function{add, sub, xor}

func generateOperations() []Operation {
	var result []Operation
	for _, f1 := range allFuncs {
		for _, f2 := range allFuncs {
			for _, f3 := range allFuncs {
				result = append(result, Operation{
					f1: f1,
					f2: f2,
					f3: f3,
				})
			}
		}
	}

	return result
}
