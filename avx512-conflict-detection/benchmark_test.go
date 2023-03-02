package conflictdetection

import (
	"fmt"
	"math/rand"
	"testing"
)

func BenchmarkHistogram(b *testing.B) {
	s := rand.NewSource(42)
	r := rand.New(s)

	const K = 1024
	const M = K * K

	for _, size := range []int{1 * K, 5 * K, 10 * K, 100 * K, 500 * K, 1 * M, 2 * M, 5 * M, 10 * M} {
		for j := range functions {
			tc := functions[j]
			name := fmt.Sprintf("%s/%d", tc.name, size)
			b.Run(name, func(b *testing.B) {
				benchmarkHistogram(b, r, tc.fn, size)
			})
		}
	}
}

func benchmarkHistogram(b *testing.B, r *rand.Rand, fn func([]uint32, []uint32), size int) {
	input := make([]uint32, size)
	output := make([]uint32, bins*16)

	b.SetBytes(int64(len(input)))
	for i := range input {
		input[i] = uint32(r.Intn(256))
	}

	b.ResetTimer()
	for i := 0; i < b.N; i++ {
		fn(input, output)
	}
}
