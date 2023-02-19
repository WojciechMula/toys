package main

import (
	"fmt"
	"math/rand"
	"runtime"
	"sync"
	"sync/atomic"
	"time"
)

const knownbest = 137

var globalmax = uint64(knownbest)
var globalmutex sync.Mutex

func main() {
	var patterns []Pattern
	var operations []Operation
	var codeTransforms []Transform
	var lengthTransforms []Transform

	runAll(
		func() { patterns = generatePatterns() },
		func() { operations = generateOperations() },
		func() { codeTransforms = generateCodeTransformations() },
		func() { lengthTransforms = generateLengthTransformations() },
	)

	runAll(
		func() {
			for i := range codeTransforms {
				t := &codeTransforms[i]
				for j := range patterns {
					t.cache(patterns[j].codeword)
				}
			}

			rand.Shuffle(len(codeTransforms), func(i, j int) {
				codeTransforms[i], codeTransforms[j] = codeTransforms[j], codeTransforms[i]
			})

		},
		func() {
			for i := range lengthTransforms {
				t := &lengthTransforms[i]
				for j := range patterns {
					t.cache(patterns[j].inputlen)
				}
			}
		},
	)

	fmt.Printf("Initialized; %d patterns, %d operations, %d code transformations, %d length transformations\n",
		len(patterns), len(operations), len(codeTransforms), len(lengthTransforms))

	k := runtime.GOMAXPROCS(0)
	var wg sync.WaitGroup
	wg.Add(k)
	slice := len(operations) / k
	idshift := 0

	var ops []Operation
	for i := 0; i < k; i++ {
		if i == k-1 {
			ops = operations
		} else {
			ops = operations[:slice]
			operations = operations[slice:]
			idshift += slice
		}

		go func(idshift int, patterns []Pattern, trans0, trans1, trans2, trans3 []Transform, ops []Operation) {
			defer wg.Done()
			checkAll(idshift, patterns, trans0, trans1, trans2, trans3, ops)
		}(idshift, patterns, lengthTransforms, codeTransforms, codeTransforms, codeTransforms, ops)
	}

	wg.Wait()
}

func checkAll(idshift int, patterns []Pattern, trans0, trans1, trans2, trans3 []Transform, ops []Operation) {
	max := uint64(0xffff)
	b := new(Bitmap)
	var h HashFunction
	for i := range ops {
		opstart := time.Now()
		id := i + idshift
		h.op = &ops[i]
		for ti0 := range trans0 {
			t0start := time.Now()
			h.t0 = &trans0[ti0]
			for ti1 := range trans1 {
				t1start := time.Now()
				h.t1 = &trans1[ti1]
				for ti2 := range trans2 {
					h.t2 = &trans2[ti2]
					for ti3 := range trans3 {
						max = atomic.LoadUint64(&globalmax)

						h.t3 = &trans3[ti3]
						b.reset()
						newmax, ok := check(b, patterns, &h, uint16(max))
						if ok && newmax <= max {
							globalmutex.Lock()
							notworse := newmax <= globalmax
							if newmax < globalmax {
								globalmax = newmax
							}
							globalmutex.Unlock()
							if notworse {
								fmt.Printf("%d: %s\n", max, &h)
							}
						}
					}
				}
				fmt.Printf("Completed op=%d/t0=%d/t1=%d in %s\n", id, ti0, ti1, time.Since(t1start))
			}
			fmt.Printf("Completed op=%d/t0=%d in %s\n", id, ti0, time.Since(t0start))
		}
		fmt.Printf("Completed op=%d in %s\n", id, time.Since(opstart))
	}
}

func check(b *Bitmap, patterns []Pattern, h *HashFunction, currentmax uint16) (uint64, bool) {
	max := uint16(0)
	for i := range patterns {
		hashcode := h.evalcached(i)
		if !b.add(hashcode) {
			return 0, false
		}

		if hashcode > currentmax {
			return 0, false
		}

		if hashcode > max {
			max = hashcode
		}
	}

	return uint64(max), true
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

func (h *HashFunction) evalcached(i int) uint16 {
	w0 := h.t0.cached[i]
	w1 := h.t1.cached[i]
	w2 := h.t2.cached[i]
	w3 := h.t3.cached[i]

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
