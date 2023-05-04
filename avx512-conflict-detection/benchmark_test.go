package conflictdetection

import (
	"fmt"
	"testing"
)

func BenchmarkHistogram(b *testing.B) {
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
		{
			maxint: 4,
			sorted: false,
		},
		{
			maxint: 15,
			sorted: false,
		},
		{
			maxint: 64,
			sorted: false,
		},
		{
			maxint: 256,
			sorted: false,
		},
		{
			maxint: 1,
			sorted: true,
		},
		{
			maxint: 4,
			sorted: true,
		},
		{
			maxint: 15,
			sorted: true,
		},
		{
			maxint: 64,
			sorted: true,
		},
		{
			maxint: 256,
			sorted: true,
		},
	}

	for i := range testcases {
		tc := &testcases[i]
		for _, size := range []int{1 * K, 5 * K, 10 * K, 100 * K, 500 * K, 1 * M, 2 * M, 5 * M, 10 * M} {
			spec := fmt.Sprintf("%d-%d-%t", size, tc.maxint, tc.sorted)
			input := testRandomData(size, tc.maxint)
			if tc.sorted {
				testSort(input)
			}
			for j := range functions {
				tc := functions[j]
				name := fmt.Sprintf("%s/%s", tc.name, spec)
				b.Run(name, func(b *testing.B) {
					benchmarkHistogram(b, input, tc.fn)
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
