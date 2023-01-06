package main

import (
	"fmt"
	"math/rand"
)

type context struct {
	input  uint64
	output [16]uint64
}

func reference(nibbles uint64) (count [16]uint64) {
	for i := 0; i < 16; i++ {
		n := nibbles & 0xf
		nibbles >>= 4

		count[n] += 1
	}

	return
}

func equals(a, b [16]uint64) bool {
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}

	return true
}

// go:noescape
// go:nosplit
func procedure(ctx *context)

func main() {
	const rounds = 10000

	rand.Seed(42)
	var ctx context
	ok := true
	for i := 0; i < rounds; i++ {
		ctx.input = rand.Uint64()
		want := reference(ctx.input)

		procedure(&ctx)
		if !equals(want, ctx.output) {
			ok = false
			fmt.Printf("input  = %016x\n", ctx.input)
			fmt.Printf("result = %x\n", ctx.output)
			fmt.Printf("want   = %x\n", want)
		}
	}

	if ok {
		fmt.Printf("All %d tests pass\n", rounds)
	}
}
