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

	testcases := []struct {
		sorted bool
		maxint int
	}{
		{
			maxint: 1,
			sorted: false,
		},
	}

	for i := range testcases {
		tc := &testcases[i]
		for _, size := range []int{1 * K, 5 * K, 10 * K, 100 * K, 500 * K, 1 * M, 2 * M, 5 * M, 10 * M} {
			spec := fmt.Sprintf("%s/%d-%s-%t", size, tc.maxint, sorted)
			input := testRandomData(size, tc.maxval)
			if tc.sorted {
				testSort(input)
			}
			for j := range functions {
				tc := functions[j]
				name := fmt.Sprintf("%s/%d", tc.name, size)
				b.Run(name, func(b *testing.B) {
					benchmarkHistogram(b, r, tc.fn, size)
				})
			}
		}
	}
}

func benchmarkHistogram(b *testing.B, input []uint32, fn func([]uint32, []uint32)) {
	output := make([]uint32, bins*16)

	b.SetBytes(int64(len(input)))

	b.ResetTimer()
	for i := 0; i < b.N; i++ {
		fn(input, output)
	}
}
