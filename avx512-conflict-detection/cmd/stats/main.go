package main

import (
	"conflictdetection"
	"fmt"
)

func main() {
	statistics()
}

func statistics() {
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
			maxint: 256,
			sorted: true,
		},
	}

	output := make([]uint32, 256)
	for i := range testcases {
		tc := &testcases[i]
		for _, size := range []int{10 * K} {
			input := conflictdetection.RandomData(size, tc.maxint)
			if tc.sorted {
				conflictdetection.Sort(input)
			}

			conflictdetection.AVX512Statistics.Reset()
			conflictdetection.HistogramIntelReference(input, output)

			fmt.Printf("size=%d, maxint=%d, sorted=%t\n", size, tc.maxint, tc.sorted)
			conflictdetection.AVX512Statistics.Print()
		}
	}
}
