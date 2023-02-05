package main

import (
	"fmt"
	"math"
)

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

func ratio(fraction uint64) (uint64, uint64) {
	if fraction == 0 {
		return 0, 0
	}

	// For example:
	//
	// 0.1101000...
	//   || |
	//   || +- exp=4
	//   |+--- exp=2
	//   +---- exp=1
	//
	// We're going to calculate commond denominator for
	// the following expression:
	//
	//  1/2^1 + 1/2^2 + 1/2^4
	//
	var exponents []int
	exp := 1
	for fraction > 0 {
		if int64(fraction) < 0 {
			exponents = append(exponents, exp)
		}

		exp += 1
		fraction <<= 1
	}

	// The denominator is:
	//
	//      2^1 * 2^2 * 2^4 = 2^{1 + 2 + 4} = 2^7
	//
	// Thus the exponent is sum of positions.
	denom_exp := 0
	for _, exp := range exponents {
		denom_exp += exp
	}

	// The numerator is a sum of:
	//
	//      (2^1 * 2^4) + (2^2 * 2^4) + (2^1 * 2^2) = 2^5 + 2^6 + 2^3
	//
	// Exponent in each term is denom_exp - i-th exponent.
	min_exp := denom_exp // we need also minimum exponent
	for i := range exponents {
		exp = denom_exp - exponents[i]
		exponents[i] = exp
		if exp < min_exp {
			min_exp = exp
		}
	}

	// Now we use the minimum exponent, to reduce the fraction
	//
	//      2^5 + 2^6 + 2^3   2^3(2^2 + 2^3 + 1)
	//      --------------- = ------------------
	//            2^7             2^3 * 2^4

	numerator := uint64(0)
	for _, exp := range exponents {
		numerator |= uint64(1) << (exp - min_exp)
	}

	denominator := uint64(1) << (denom_exp - min_exp)

	return numerator, denominator
}

func main() {
	fraction := uint64(0xccf00000_00000000)

	fmt.Printf("0.%064b\n", fraction)
	num, denom := ratio(fraction)

	fmt.Printf("%d/%d\n", num, denom)

	f1 := float64(num) / float64(denom)
	f2 := float64(fraction) / float64(1<<64)
	fmt.Printf("%f\n", f1)
	fmt.Printf("%f\n", f2)
}
