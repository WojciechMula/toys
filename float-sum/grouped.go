package floatsum

import (
	"math"
)

func Grouped(vals []float64) float64 {
	var sums [1 << 11]float64

	for i := range vals {
		x := vals[i]
		exp := float64exp(x)
		for {
			sum := sums[exp] + x

			exp2 := float64exp(sum)
			if exp2 == exp {
				sums[exp] = sum
				break
			}

			sums[exp] = 0.0
			x = sum
			exp = exp2
		}
	}

	return Naive(sums[:])
}

func float64exp(x float64) uint64 {
	bin := math.Float64bits(x)
	return (bin >> 52) & ((1 << 11) - 1)
}
