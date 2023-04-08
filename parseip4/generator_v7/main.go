package main

import (
	"fmt"
	"io"
	"log"
	"math/bits"
	"os"
)

func main() {
	if len(os.Args) != 2 {
		fmt.Printf("Usage %s <path>\n", os.Args[0])
		os.Exit(1)
	}

	path := os.Args[1]
	f, err := os.Create(path)
	check(err)
	defer f.Close()

	generate(f, hash_v3)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func generate(f io.Writer, hash func(uint16) uint16) {
	patterns := generatePatterns()
	maxHash := uint16(0)
	maxId := 0
	byHash := make(map[uint16]int)
	byId := make(map[int]*Pattern)
	for i := range patterns {
		p := &patterns[i]
		if !p.valid() {
			panic("codeword has to be valid")
		}

		h := hash(p.codeword)
		if h > maxHash {
			maxHash = h
		}
		id := p.id()
		if id > maxId {
			maxId = id
		}

		byHash[h] = id
		byId[id] = p
	}

	byId[maxId+1] = &Pattern{
		codeword: 0xffff,
	}

	write := func(s string, args ...any) {
		fmt.Fprintf(f, s, args...)
		fmt.Fprintf(f, "\n")
	}

	write("/* Code generated automatically; DO NOT EDIT */")
	write("")
	write("// lookup #1")
	write("const int max_hash = %d;", maxHash)
	write("static const uint8_t patterns_id[%d] = {", maxHash+1)
	for h := uint16(0); h <= maxHash; h++ {
		id, ok := byHash[h]
		if !ok {
			id = maxId + 1
		}

		fmt.Fprintf(f, "\t/* hash: %08x */ %d", h, id)
		last := (h == maxHash)
		if !last {
			fmt.Fprintf(f, ",\n")
		} else {
			fmt.Fprintf(f, "\n")
		}
	}
	write("};")
	write("")
	write("// lookup #2")

	write("static const uint8_t patterns[%d][20] = {", maxId+2)
	var pshufb [20]byte
	for id := 0; id <= maxId+1; id++ {
		p, ok := byId[id]
		if !ok {
			fmt.Printf("id = %d\n", id)
			panic("id not found")
		}

		for i, b := range p.pshufb() {
			pshufb[i] = b
		}
		pshufb[16] = byte((p.codeword >> 0) & 0xff)
		pshufb[17] = byte((p.codeword >> 8) & 0xff)
		pshufb[18] = byte(p.maxlen())

		fmt.Fprintf(f, "\t/* id: %d, hash: %08x */ {", id, p.codeword)
		for i, b := range pshufb {
			if i > 0 {
				fmt.Fprintf(f, ", ")
			}
			fmt.Fprintf(f, "%d", b)
		}
		fmt.Fprintf(f, "}")
		if id != maxId+1 {
			fmt.Fprintf(f, ",\n")
		}
	}
	write("};")
}

func lookforparams() {
	patterns := generatePatterns()
	f := patterns[0].codeword
	min := f
	max := f

	for _, p := range patterns {
		if p.codeword < min {
			min = p.codeword
		} else if p.codeword > max {
			max = p.codeword
		}
	}

	fmt.Printf("total = %d, min = %d, max = %d\n", len(patterns), min, max)
	checkAll(patterns)
}

// max value: 1228
func hash_v3(x uint16) uint16 {
	const shift = 5
	const mask = 0x03ff

	return (x >> shift) ^ (x & mask)
}

// max value: 7099
func hash_v4(x uint16) uint16 {
	// max = 7099: mul=13312 (00003400), shift=16
	// max = 7099: mul=872415232 (34000000), shift=32
	const mul = 0x34000000
	const shift = 32

	x0 := uint64(x)
	x0 *= mul
	x0 >>= shift

	return uint16(x0)
}

// max value: 3648
func hash_v5(x uint16) uint16 {
	const mul = 5761
	const shift = 16

	x0 := (uint64(x*4) + uint64(bits.LeadingZeros16(x)))
	x0 *= mul
	x0 >>= shift

	return uint16(x0)
}

func checkAll(patterns []Pattern) {
	var b Bitmap
	max := uint16(0xffff)
	for shift := 0; shift < 16; shift++ {
		for j := 0; j < 16; j++ {
			for i := 0; i < 16; i++ {
				mask := uint16(0xffff) >> i
				m, ok := checkPatterns(patterns, &b, max, func(x uint16) uint16 {
					return (x >> shift) ^ (x & mask)
				})

				if ok && m <= max {
					max = m
					fmt.Printf("shift = %d, mask = %04x [i=%d] max = %d\n", shift, mask, i, max)
				}
			}
		}
	}
}

func checkPatterns(patterns []Pattern, b *Bitmap, globalmax uint16, h func(uint16) uint16) (uint16, bool) {
	b.reset()
	max := uint16(0)
	for i := range patterns {
		hashed := h(patterns[i].codeword)
		if !b.add(hashed) {
			return 0, false
		}

		if hashed > globalmax {
			return 0, false
		}

		if hashed > max {
			max = hashed
		}
	}

	return max, true
}
