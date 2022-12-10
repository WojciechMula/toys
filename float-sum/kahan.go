package floatsum

import ()

func Kahan(vals []float64) float64 {
	sum := float64(0.0)
	c := float64(0.0)

	for i := range vals {
		y := vals[i] - c
		t := sum + y

		c = (t - sum) - y

		sum = t
	}

	return sum
}
