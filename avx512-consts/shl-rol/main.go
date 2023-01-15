package main

import (
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

var stdout io.Writer

func main() {
	stdout = os.Stdout
	args := os.Args[1:]
	for i := range args {
		val, err := strconv.ParseUint(args[i], 0, 32)
		if err != nil {
			write("skipping %q due to: %s", err)
			continue
		}

		write("Program for 0x%08x 0b%032b", val, val)
		generateAsm(uint32(val))
	}
}

func generateAsm(v uint32) {
	type instruction struct {
		asm string
		val uint32
	}

	var instructions []instruction

	z1 := uint32(0xffffffff)
	instructions = append(instructions, instruction{
		asm: "VPTERNLOGD $0xff, Z1, Z1, Z1",
		val: z1,
	})
	generate(v, func(val bool, count int) {
		if val {
			v = rol(z1, count)
			if v != z1 {
				instructions = append(instructions, instruction{
					asm: fmt.Sprintf("VPROLD $%d, Z1, Z1", count),
					val: v,
				})
			}
			z1 = v
		} else {
			z1 <<= count
			instructions = append(instructions, instruction{
				asm: fmt.Sprintf("VPSLLD $%d, Z1, Z1", count),
				val: z1,
			})
		}
	})

	maxlength := 0
	for i := range instructions {
		if l := len(instructions[i].asm); l > maxlength {
			maxlength = l
		}
	}

	for _, ins := range instructions {
		write("\t%s // %032b", pad(ins.asm, maxlength), ins.val)
	}
}

func pad(s string, n int) string {
	d := n - len(s)
	if d <= 0 {
		return s
	}

	return s + strings.Repeat(" ", d)
}

func rol(x uint32, n int) uint32 {
	for n > 0 {
		x = (x << 1) | (x >> 31)
		n -= 1
	}

	return x
}

func generate(v uint32, fn func(bool, int)) {
	length := 0
	curval := false
	first := true
	addbit := func(val bool) {
		if first {
			length = 1
			curval = val
			first = false
			return
		}

		if val == curval {
			length += 1
		} else {
			fn(curval, length)
			length = 1
			curval = val
		}
	}

	mask := uint32(0x80000000)
	for i := 31; i >= 0; i-- {
		addbit(v&mask != 0)
		mask >>= 1
	}

	addbit(!curval) // force flush last span
}

func write(s string, args ...any) {
	fmt.Fprintf(stdout, s, args...)
	fmt.Fprintf(stdout, "\n")
}
