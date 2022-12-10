package floatsum

import (
	"sort"
)

func Sorted(vals []float64) float64 {
	sort.Float64s(vals)

	return Naive(vals)
}
