package conflictdetection

import (
	"fmt"
)

type avx512statistics struct {
	total  uint64
	active uint64
}

func (a *avx512statistics) Reset() {
	a.total = 0
	a.active = 0
}

func (a *avx512statistics) Print() {
	coef := float64(a.active) * 100.0 / float64(a.total)
	fmt.Printf("\tall elements    = %d\n", a.total)
	fmt.Printf("\tactive elements = %d (%0.2f)\n", a.active, coef)
}

var AVX512Statistics *avx512statistics = &avx512statistics{}
