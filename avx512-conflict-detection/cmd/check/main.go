package main

import (
	"conflictdetection"
	"fmt"
)

func main() {
	output := make([]uint32, 256)
	input := []uint32{
		1, 1, 1,
		22, 22, 22, 22,
		1, 1,
		33, 33, 1, 33,
		1,
		22, 22,
	}

	conflictdetection.HistogramIntelReference(input, output)

	count := 0
	for i, freq := range output {
		if freq != 0 {
			fmt.Printf("%2d: %d\n", i, freq)
			count += int(freq)
		}
	}

	if count != len(input) {
		panic("wrong histogram")
	}
}
