package main

import (
	"fmt"
	"runtime"
	"sync"
)

func main() {
	var patterns []Pattern
	var operations []Operation
	var transforms []Transform

	{
		var wg sync.WaitGroup
		wg.Add(3)
		go func() {
			patterns = generatePatterns()
			wg.Done()
		}()

		go func() {
			operations = generateOperations()
			wg.Done()
		}()

		go func() {
			transforms = generateTransformations()
			wg.Done()
		}()

		wg.Wait()
		fmt.Printf("%d\n", len(patterns))
		fmt.Printf("%d\n", len(operations))
		fmt.Printf("%d\n", len(transforms))
	}

	k := runtime.GOMAXPROCS(0)
	var wg sync.WaitGroup
	wg.Add(k)
	slice := len(operations) / k

	var ops []Operation
	for i := 0; i < k; i++ {
		if i == k-1 {
			ops = operations
		} else {
			ops = operations[:slice]
			operations = operations[slice:]
		}

		go func(patterns []Pattern, transforms []Transform, ops []Operation) {
			defer wg.Done()
			checkAll(patterns, transforms, ops)
		}(patterns, transforms, ops)
	}

	wg.Wait()
}

func checkAll(patterns []Pattern, transforms []Transform, ops []Operation) {
	max := uint16(0xffff)
	var h HashFunction
	for i := range ops {
		h.op = &ops[i]
		for ti0 := range transforms {
			h.t0 = &transforms[ti0]
			for ti1 := range transforms {
				h.t1 = &transforms[ti1]
				for ti2 := range transforms {
					h.t2 = &transforms[ti2]
					for ti3 := range transforms {
						h.t3 = &transforms[ti3]
						newmax, ok := check(patterns, &h)
						if ok && newmax <= max {
							fmt.Printf("%d: %s\n", max, &h)
							max = newmax
						}
					}
				}
			}
		}
	}
}

func check(patterns []Pattern, h *HashFunction) (uint16, bool) {
	m := make(map[uint16]struct{})
	max := uint16(0)
	for i := range patterns {
		hashcode := h.eval(patterns[i].codeword, patterns[i].inputlen)
		_, ok := m[hashcode]
		if ok {
			return 0, false
		}

		m[hashcode] = struct{}{}
		if hashcode > max {
			max = hashcode
		}
	}

	return max, true
}

type HashFunction struct {
	t0, t1, t2, t3 *Transform
	op             *Operation
}

func (h *HashFunction) eval(code, length uint16) uint16 {
	w0 := h.t0.transform(length)
	w1 := h.t1.transform(code)
	w2 := h.t2.transform(code)
	w3 := h.t3.transform(code)

	return h.op.eval(w0, w1, w2, w3)
}

func (h *HashFunction) String() string {
	return fmt.Sprintf("(((%s %s %s) %s %s) %s %s)",
		h.t0.text("len"),
		h.op.f1,
		h.t1.text("code"),
		h.op.f2,
		h.t2.text("code"),
		h.op.f3,
		h.t3.text("code"),
	)
}
