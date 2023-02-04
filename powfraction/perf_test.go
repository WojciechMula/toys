package powfraction

import (
	"fmt"
	"math"
	"testing"
)

const bitCount = 8

func TestPowFract(t *testing.T) {
	f := 781.45

	for _, basefloat := range []float64{0.5, 0.25, 0.125, 0.0625, 0.03125} {
		img := math.Float64bits(basefloat)
		for pattern := uint64(0); pattern < (1 << bitCount); pattern++ {
			tmp := img | (pattern << (52 - bitCount))
			exponent := math.Float64frombits(tmp)
			t.Run(fmt.Sprintf("%f", exponent), func(t *testing.T) {
				got := fmt.Sprintf("%f", powfrac(f, exponent))
				want := fmt.Sprintf("%f", math.Pow(f, exponent))
				if got != want {
					t.Logf("got:  %s", got)
					t.Logf("want: %s", want)
					t.Errorf("wrong result")
				}
			})
		}
	}
}

func BenchmarkPowStd(b *testing.B) {
	f := 781.45

	for i := 1; i < 16; i++ {
		exponent := float64(1) / float64(uint64(1<<i))
		b.Run(fmt.Sprintf("2^{-%d}", i), func(b *testing.B) {
			b.ResetTimer()
			for i := 0; i < b.N; i++ {
				_ = math.Pow(f, exponent)
			}
		})
	}
}

func BenchmarkPowFract(b *testing.B) {
	f := 781.45

	for i := 1; i < 16; i++ {
		exponent := float64(1) / float64(uint64(1<<i))
		b.Run(fmt.Sprintf("2^{-%d}", i), func(b *testing.B) {
			b.ResetTimer()
			for i := 0; i < b.N; i++ {
				_ = powfrac(f, exponent)
			}
		})
	}
}
