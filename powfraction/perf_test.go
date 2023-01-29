package powfraction

import (
	"fmt"
	"math"
	"testing"
)

func TestPowFract(t *testing.T) {
	f := 781.45
	exponents := []int{2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 100}
	for _, exponent := range exponents {
		powfrac(f, float64(1)/float64(exponent))
	}
}

func BenchmarkPowStd(b *testing.B) {
	f := 781.45
	exponents := []int{2, 3, 4, 8, 16, 32, 64, 128, 256}
	for _, exponent := range exponents {
		exponent := exponent
		b.Run(fmt.Sprintf("1-over-%d", exponent), func(b *testing.B) {
			e := float64(1) / float64(exponent)
			b.ResetTimer()
			for i := 0; i < b.N; i++ {
				_ = math.Pow(f, e)
			}
		})
	}
}

func BenchmarkPowFract(b *testing.B) {
	f := 781.45
	exponents := []int{2, 3, 4, 8, 16, 32, 64, 128, 256}
	for _, exponent := range exponents {
		exponent := exponent
		b.Run(fmt.Sprintf("1-over-%d", exponent), func(b *testing.B) {
			e := float64(1) / float64(exponent)
			b.ResetTimer()
			for i := 0; i < b.N; i++ {
				_ = powfrac(f, e)
			}
		})
	}
}
