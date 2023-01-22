package main

import (
	"fmt"
)

type context struct {
	in  uint32
	bfs uint32
}

// go:noescape
// go:nosplit
func procedure(ctx *context)

func main() {
	ctx := &context{}

	ok := true
	for shift := 0; shift < 64; shift++ {
		for nibble := uint32(0); nibble < 16; nibble++ {
			ctx.in = nibble << shift

			procedure(ctx)

			got := ctx.bfs
			want := bfs(ctx.in)

			if got != want {
				fmt.Printf("word: %08x\n", ctx.in)
				fmt.Printf("got : %d\n", got)
				fmt.Printf("want: %d\n", want)
				ok = false
			}
		}
	}

	if ok {
		fmt.Printf("All OK\n")
	}
}

func bfs(x uint32) uint32 {
	res := uint32(0)
	for i := 0; i < 32; i++ {
		if (x & 1) == 1 {
			break
		}

		res += 1
		x >>= 1
	}

	return res
}
