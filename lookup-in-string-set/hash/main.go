package main

import (
	"bytes"
	"flag"
	"fmt"
	"log"
	"os"
	"path"
	"strings"
)

func main() {
	var (
		inpath  string
		outpath string
	)
	flag.StringVar(&inpath, "i", "", "input path")
	flag.StringVar(&outpath, "o", "", "output path")
	flag.Parse()
	if inpath == "" || outpath == "" {
		flag.Usage()
		os.Exit(1)
	}

	basename := path.Base(inpath)
	basename, _ = strings.CutSuffix(basename, path.Ext(basename))

	keywords, err := readList(inpath)
	check(err)

	hashes := []struct {
		name    string
		cppname string
		fn      func([]byte) uint64
	}{
		{
			name:    "(first + last) * len",
			cppname: "hash1",
			fn: func(w []byte) uint64 {
				n := uint64(len(w))
				f := uint64(w[0])
				l := uint64(w[len(w)-1])

				return (f + l) * n
			},
		},
		{
			name:    "(first * last) ^ len",
			cppname: "hash2",
			fn: func(w []byte) uint64 {
				n := uint64(len(w))
				f := uint64(w[0])
				l := uint64(w[len(w)-1])

				return (f * l) ^ n
			},
		},
		{
			name:    "first, second, last, len combined",
			cppname: "hash3",
			fn: func(w []byte) uint64 {
				n := uint64(len(w))
				f := uint64(w[0])
				s := uint64(w[1])
				l := uint64(w[len(w)-1])

				return ((f << 8) | s) + l + (n * 0x111)
			},
		},
		{
			name:    "sum of bytes from 0",
			cppname: "hash_sum0",
			fn: func(w []byte) uint64 {
				s := uint64(0)
				for _, b := range w {
					s += uint64(b)
				}
				return s
			},
		},
		{
			name:    "sum of bytes from len",
			cppname: "hash_sumN",
			fn: func(w []byte) uint64 {
				s := uint64(len(w))
				for _, b := range w {
					s += uint64(b)
				}
				return s
			},
		},
		{
			// http://www.cse.yorku.ca/~oz/hash.html
			name:    "djb2",
			cppname: "hash_djb2",
			fn: func(w []byte) uint64 {
				h := uint64(5481)
				for _, b := range w {
					h = h*33 + uint64(b)
				}
				return h
			},
		},
		{
			// http://www.cse.yorku.ca/~oz/hash.html
			name:    "sdb",
			cppname: "hash_sdb",
			fn: func(w []byte) uint64 {
				h := uint64(0)
				for _, b := range w {
					h = h*65539 + uint64(b)
				}
				return h
			},
		},
	}

	fmt.Printf("input words: %d\n", len(keywords))

	buf := bytes.NewBuffer(nil)
	for _, h := range hashes {
		fmt.Printf("Hash %-40s: ", h.name)
		size, _, collisions := computerHashParameters(keywords, h.fn)

		ctx := &generateContext{}
		ctx.output = buf
		ctx.basename = basename
		ctx.argname = "s"
		ctx.valtype = "int"
		ctx.defval = "-1"
		ctx.hashfn = h.cppname
		ctx.lookup, ctx.values = compileLookup(keywords, size, collisions, h.fn)
		ctx.collisions = collisions
		check(generateFunction(ctx))
	}

	check(os.WriteFile(outpath, buf.Bytes(), 0644))
	fmt.Printf("Created %s\n", outpath)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}
