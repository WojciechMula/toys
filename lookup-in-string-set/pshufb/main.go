package main

import (
	"flag"
	"fmt"
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

	words, err := readList(inpath)
	check(err)

	max := 0
	for i := range words {
		n := len(words[i].word)
		if n > max {
			max = n
		}
	}

	for i := range words {
		mem := make([]byte, max)
		copy(mem, words[i].word)
		words[i].word = mem
	}

	var lo, hi [16]byte
	for i := range lo {
		b := byte(i)
		lo[i] = b
		hi[i] = b
	}

	try := func(lookup *[16]byte) {
		for i := range lo {
			old := (*lookup)[i]
			found := false
			for j := byte(0); j < old; j++ {
				(*lookup)[i] = j
				if checkWords(words, max, lo, hi) {
					found = true
					break
				}
			}

			if found {
				fmt.Printf("changed %d: %d -> %d\n", i, old, (*lookup)[i])
			} else {
				(*lookup)[i] = old
			}
		}
	}

	try(&lo)
	try(&hi)

	fmt.Printf("lo: %d\n", lo)
	fmt.Printf("hi: %d\n", hi)
}

func checkWords(words []Keyword, n int, lookupLo, lookupHi [16]byte) bool {
	w := make([]byte, n)
	m := make(map[string]struct{})

	transform := func(word []byte) {
		for i := range word {
			w[i] = 0
		}
		for i, b := range word {
			lo := b & 0x0f
			hi := b >> 4

			w[i] = lookupLo[lo] | (lookupHi[hi] << 4)
		}
	}

	for i := range words {
		transform(words[i].word)
		s := string(w)
		if _, ok := m[s]; ok {
			return false
		}

		m[s] = struct{}{}
	}

	return true
}

func check(err error) {
	if err != nil {
		fmt.Printf("%s", err)
		os.Exit(2)
	}
}
