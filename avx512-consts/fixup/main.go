package main

import (
	"fmt"
)

type context struct {
	in  uint32
	f32 float32
	u32 uint32
}

// go:noescape
// go:nosplit
func procedure(ctx *context)

var tokenresponse [16]string = [16]string{
	7:  "-0",
	8:  "+0",
	9:  "-1",
	10: "+1",
	11: "1/2",
	12: "90.0",
	13: "pi/2",
	14: "MAX_FLOAT",
	15: "MIN_FLOAT",
}

func main() {
	ctx := &context{}

	for token, name := range tokenresponse {
		if name == "" {
			continue
		}

		ctx.in = uint32(token) * 0x100
		procedure(ctx)

		fmt.Printf("token: %x (%s)\n", token, name)
		fmt.Printf("\tf32: %f\n", ctx.f32)
		fmt.Printf("\tu32: 0x%08x\n", ctx.u32)
	}
}
