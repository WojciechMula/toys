package main

type Function int

const (
	add Function = iota
	sub
)

func (f Function) eval(a, b uint16) uint16 {
	switch f {
	case add:
		return a + b

	case sub:
		return a - b
	}

	panic("wrong operation")
}

func (f Function) String() string {
	switch f {
	case add:
		return "+"

	case sub:
		return "-"
	}

	return "?"
}

type Operation struct {
	f1, f2, f3 Function
	eval       func(a, b, c, d uint16) uint16
}

var allFuncs = []Function{add, sub}

func eval000(a, b, c, d uint16) uint16 { return a + b + c + d }
func eval001(a, b, c, d uint16) uint16 { return a + b + c - d }
func eval010(a, b, c, d uint16) uint16 { return a + b - c + d }
func eval011(a, b, c, d uint16) uint16 { return a + b - c - d }
func eval100(a, b, c, d uint16) uint16 { return a - b + c + d }
func eval101(a, b, c, d uint16) uint16 { return a - b + c - d }
func eval110(a, b, c, d uint16) uint16 { return a - b - c + d }
func eval111(a, b, c, d uint16) uint16 { return a - b - c - d }

var evalfuncs = [8]func(a, b, c, d uint16) uint16{
	eval000,
	eval001,
	eval010,
	eval011,
	eval100,
	eval101,
	eval110,
	eval111,
}

func eval(f1, f2, f3 Function) func(a, b, c, d uint16) uint16 {
	id := 0
	if f1 == sub {
		id |= 4
	}
	if f2 == sub {
		id |= 2
	}
	if f3 == sub {
		id |= 1
	}

	return evalfuncs[id]
}

func generateOperations() []Operation {
	var result []Operation
	for _, f1 := range allFuncs {
		for _, f2 := range allFuncs {
			for _, f3 := range allFuncs {
				result = append(result, Operation{
					f1:   f1,
					f2:   f2,
					f3:   f3,
					eval: eval(f1, f2, f3),
				})
			}
		}
	}

	return result
}
