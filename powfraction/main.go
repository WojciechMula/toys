package powfraction

import (
	"math"
	"math/bits"
)

func powfrac(x, exponent float64) float64 {
	fraction := extractfraction(exponent)
	n := bits.TrailingZeros64(fraction)
	if n > 50 {
		return powfracaux(x, fraction)
	}

	return math.Pow(x, exponent)

}

func extractfraction(x float64) uint64 {
	u64 := math.Float64bits(x)
	const significand_mask = (1 << 52) - 1
	const implicit_one = 1 << 52
	const shifted_exp_mask = (1 << 11) - 1
	const exp_bias = 1023
	fraction := (u64 & significand_mask) | implicit_one
	exp := int((u64>>52)&shifted_exp_mask) - exp_bias
	if exp >= 0 {
		panic("only fraction values are supported")
	}
	fraction <<= 11
	fraction >>= -exp - 1

	return fraction
}

func powfracaux(x float64, fraction uint64) float64 {
	res := 1.0 // res = 2^0
	sq := x
	for fraction != 0 {
		sq = math.Sqrt(sq)       // sq = 1/2^i
		if int64(fraction) < 0 { // i-th bit set (MSB)
			res *= sq // update result
		}

		fraction <<= 1
	}

	return res
}
