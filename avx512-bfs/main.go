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
func procedure1(ctx *context)

// go:noescape
// go:nosplit
func procedure2(ctx *context)

// go:noescape
// go:nosplit
func procedure3(ctx *context)

// go:noescape
// go:nosplit
func procedure4(ctx *context)

// go:noescape
// go:nosplit
func procedure5(ctx *context)

// go:noescape
// go:nosplit
func procedure6(ctx *context)

// go:noescape
// go:nosplit
func procedure7(ctx *context)

// go:noescape
// go:nosplit
func procedure8(ctx *context)

func main() {

	procedures := []struct {
		fn   func(*context)
		name string
	}{
		{
			fn:   procedure1,
			name: "Procedure 1",
		},
		{
			fn:   procedure2,
			name: "Procedure 2",
		},
		{
			fn:   procedure3,
			name: "Procedure 3",
		},
		{
			fn:   procedure4,
			name: "Procedure 4",
		},
		{
			fn:   procedure5,
			name: "Procedure 5",
		},
		{
			fn:   procedure6,
			name: "Procedure 6",
		},
		{
			fn:   procedure7,
			name: "Procedure 7",
		},
		{
			fn:   procedure8,
			name: "Procedure 8",
		},
	}

	ok := true
	for i := range procedures {
		fmt.Printf("%s\n", procedures[i].name)
		res := test(procedures[i].fn)
		ok = res && ok
	}

	if ok {
		fmt.Printf("All OK\n")
	}
}

func test(procedure func(ctx *context)) bool {
	ctx := &context{}

	ok := true
	for shift := 0; shift < 64; shift++ {
		for nibble := uint32(0); nibble < 256; nibble++ {
			ctx.in = nibble << shift

			procedure(ctx)

			got := ctx.bfs
			want := bfs(ctx.in)

			if got != want {
				fmt.Printf("word: %032b\n", ctx.in)
				//fmt.Printf("got : %032b\n", got)
				fmt.Printf("got : %d\n", got)
				fmt.Printf("want: %d\n", want)
				ok = false
			}
		}
	}

	return ok
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
