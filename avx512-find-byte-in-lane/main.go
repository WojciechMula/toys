package main

import (
	"fmt"
)

type context struct {
	word uint32
	char uint32
	pos  int32
}

// go:noescape
// go:nosplit
func procedure(ctx *context)

func main() {
	char := uint32(0xaa)

	ctx := &context{}
	ctx.char = 0x01010101 * char

	ok := true
	for p := 0; p < 16; p++ {
		ctx.word = 0
		pos := 4
		for i := 0; i < 4; i++ {
			if (p & (1 << i)) != 0 {
				ctx.word |= uint32(char) << (8 * i)
				if pos == 4 {
					pos = i
				}
			} else {
				ctx.word |= uint32(0xff) << (8 * i)
			}
		}

		procedure(ctx)

		if int32(pos) != ctx.pos {
			fmt.Printf("%04b => %08x\n", p, ctx.word)
			fmt.Printf("got:  %d\n", ctx.pos)
			fmt.Printf("want: %d\n", pos)
			ok = false
		}
	}

	if ok {
		fmt.Printf("All OK\n")
	}
}
