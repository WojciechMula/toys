package powfraction

import (
	"math"
	"math/bits"
)

func powfrac(x, exponent float64) float64 {
	u64 := math.Float64bits(exponent)
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
	fraction >>= -exp
	fraction <<= 1

	n := bits.TrailingZeros64(fraction)
	if n > 50 {
		return powfracaux(x, fraction)
	}

	return math.Pow(x, exponent)

}

func powfracaux(x float64, fraction uint64) float64 {
	res := 1.0
	sq := x
	for fraction != 0 {
		sq = math.Sqrt(sq)
		if sq == 1.0 {
			break
		}
		if int64(fraction) < 0 {
			prev := res
			res *= sq
			if prev == res {
				break
			}
		}

		fraction <<= 1
	}

	return res
}
