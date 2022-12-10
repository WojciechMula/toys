package floatsum

import (
	"fmt"
	"math/rand"
	"testing"
)

func TestSmoke(t *testing.T) {

	//sizes := []int{100, 1000, 10000, 100_000, 1_000_000}
	sizes := []int{1_000_000}

	for _, size := range sizes {
		size := size
		t.Run(fmt.Sprintf("case-%d", size), func(t *testing.T) {
			vals := randomFloats(size, 42)

			sorted := Sorted(vals)
			const shuffles = 100
			for i := 0; i < shuffles; i++ {
				naive := Naive(vals)
				grouped := Grouped(vals)
				kahan := Kahan(vals)

				t.Logf("run %d", i)
				t.Logf("sorted  = %0.10f", sorted)
				t.Logf("naive   = %0.10f (diff: %0.10f)", naive, naive-sorted)
				t.Logf("kahan   = %0.10f (diff: %0.10f)", kahan, kahan-sorted)
				t.Logf("grouped = %0.10f (diff: %0.10f)", grouped, grouped-sorted)

				rand.Shuffle(size, func(i, j int) {
					vals[i], vals[j] = vals[j], vals[i]
				})
			}
		})
	}
}

func BenchmarkNaive(b *testing.B) {
	size := 1_000
	reference := randomFloats(size, 42)
	vals := make([]float64, size)

	b.ResetTimer()
	b.SetBytes(int64(8 * size))
	for i := 0; i < b.N; i++ {
		copy(vals, reference)
		_ = Naive(vals)
	}
}

func BenchmarkSorted(b *testing.B) {
	size := 1_000
	reference := randomFloats(size, 42)
	vals := make([]float64, size)

	b.ResetTimer()
	b.SetBytes(int64(8 * size))
	for i := 0; i < b.N; i++ {
		copy(vals, reference)
		_ = Sorted(vals)
	}
}

func BenchmarkGrouped(b *testing.B) {
	size := 1_000
	reference := randomFloats(size, 42)
	vals := make([]float64, size)

	b.ResetTimer()
	b.SetBytes(int64(8 * size))
	for i := 0; i < b.N; i++ {
		copy(vals, reference)
		_ = Grouped(vals)
	}
}

func BenchmarkKahan(b *testing.B) {
	size := 1_000
	reference := randomFloats(size, 42)
	vals := make([]float64, size)

	b.ResetTimer()
	b.SetBytes(int64(8 * size))
	for i := 0; i < b.N; i++ {
		copy(vals, reference)
		_ = Kahan(vals)
	}
}

func randomFloats(size int, seed int64) []float64 {
	rand.Seed(seed)
	vals := make([]float64, size)
	for i := 0; i < size; i++ {
		vals[i] = randPosFloat64()
		//vals[i] = math.Float64frombits(uint64(rand.Intn((1 << 10) - 1)) << 52)
	}

	return vals
}

func randPosFloat64() float64 {
	for {
		x := rand.Float64()
		if x >= 0 {
			return x
		}
	}
}
