package main

import (
	"fmt"
	"math/bits"
)

type Transform struct {
	rotl int
	shr  int
	and  uint16
	mul  uint16
}

func (t *Transform) transform(code uint16) uint16 {
	if t.rotl != 0 {
		code = bits.RotateLeft16(code, t.rotl)
	}

	if t.shr != 0 {
		code >>= t.shr
	}

	if t.and != 0 {
		code &= t.and
	}

	return t.mul * code
}

func (t *Transform) text(val string) string {
	parentheses := false
	if t.rotl != 0 {
		val = fmt.Sprintf("rotl(%s, %d)", val, t.rotl)
	}

	if t.shr != 0 {
		val = fmt.Sprintf("%s >> %d", val, t.shr)
		parentheses = true
	}

	if t.and != 0 {
		if parentheses {
			val = fmt.Sprintf("(%s)", val)
		}

		val = fmt.Sprintf("%s & 0x%02x", val, t.and)
		parentheses = true
	}

	if parentheses {
		val = fmt.Sprintf("(%s)", val)
	}

	return fmt.Sprintf("(%d * %s)", t.mul, val)
}

var multipliers = []uint16{
	1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59,
	61, 67, 71, 73, 79, 83, 89, 97, 101,
}

var andList = []uint16{0x0f, 0x1f, 0x3f, 0x7f, 0xff}

func generateTransformations() []Transform {
	var result []Transform
	for _, mul := range multipliers {
		for rotl := 0; rotl < 1; rotl++ {
			for shr := 0; shr < 15; shr++ {
				for _, and := range andList {
					result = append(result, Transform{
						rotl: rotl,
						shr:  shr,
						and:  and,
						mul:  mul,
					})
				}
			}
		}
	}

	return result
}
