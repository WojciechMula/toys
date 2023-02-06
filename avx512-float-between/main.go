package main

import (
	"fmt"
	"math/rand"
)

type context struct {
	x, a, b float64
	inrange bool
}

// go:noescape
// go:nosplit
func procedure1(ctx *context)

// go:noescape
// go:nosplit
func procedure2(ctx *context)

const min = 2.0
const max = 5.5

func main() {
	ctx := &context{}

	ok := true

	rand.Seed(42)
	const tries = 100
	for i := 0; i < tries; i++ {
		x := rand.Float64() * 10.0
		want := reference(x)

		ctx.a = (min + max) * 0.5 // the average of bounds
		ctx.b = (max - min) * 0.5 // the half of range width
		ctx.x = x
		procedure1(ctx)
		got1 := ctx.inrange

		ctx.a = min
		ctx.b = max
		ctx.x = x
		procedure2(ctx)
		got2 := ctx.inrange

		if want != got1 || want != got2 {
			fmt.Printf("x   : %f\n", x)
			fmt.Printf("got1: %v\n", got1)
			fmt.Printf("got2: %v\n", got2)
			fmt.Printf("want: %v\n", want)
			ok = false
		}
	}

	if ok {
		print("All OK\n")
	}
}

func reference(x float64) bool {
	return x >= min && x <= max
}
