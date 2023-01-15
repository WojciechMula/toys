package main

import (
	"fmt"
)

type context struct {
	in   uint32
	avgb uint32
	avgw uint32
}

// go:noescape
// go:nosplit
func procedure(ctx *context)

func main() {
	ctx := &context{}

	for i := 0; i < 8; i++ {
		ctx.in = uint32(0xffffffff) << i
		procedure(ctx)

		fmt.Printf("input: 0x%08x\n", ctx.in)
		fmt.Printf("\tAVGB: 0x%08x\n", ctx.avgb)
		fmt.Printf("\tAVGW: 0x%08x\n", ctx.avgw)
	}
}
