package main

import (
	"math/bits"
)

// Bitmask indicating the position of four dots;
// The last one is a past-end helper to determine
// the input string length.
type Code uint32

func (c Code) pos() (int, int, int, int) {
	tmp := uint16(c)

	l0 := bits.TrailingZeros16(tmp)
	tmp = tmp & (tmp - 1)

	l1 := bits.TrailingZeros16(tmp)
	tmp = tmp & (tmp - 1)

	l2 := bits.TrailingZeros16(tmp)
	tmp = tmp & (tmp - 1)

	l3 := bits.TrailingZeros16(tmp)

	return l0, l1, l2, l3
}

func (c Code) lengths() (int, int, int, int) {
	l0, l1, l2, l3 := c.pos()

	return l0, l1 - (l0 + 1), l2 - (l1 + 1), l3 - (l2 + 1)
}

func (c Code) valid() bool {
	l0, l1, l2, l3 := c.lengths()

	return l0 > 0 && l1 > 0 && l2 > 0 && l3 > 0 &&
		l0 <= 3 && l1 <= 3 && l2 <= 3 && l3 <= 3
}

func possibleInputs() []Code {
	var result []Code
	for i := 0; i < 16; i++ {
		for j := i + 1; j < 16; j++ {
			for k := j + 1; k < 16; k++ {
				for l := k + 1; l < 16; l++ {
					w := uint16((1 << i) | (1 << j) | (1 << k) | (1 << l))
					if bits.OnesCount16(w) == 4 {
						result = append(result, Code(w))
					}
				}
			}
		}
	}

	return result
}
