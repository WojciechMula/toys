package floatsum

func Naive(vals []float64) float64 {
	sum := float64(0.0)
	for i := range vals {
		sum += vals[i]
	}

	return sum
}
