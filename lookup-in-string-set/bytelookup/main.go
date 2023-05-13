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

	used := make([]bool, max)
	for i := range used {
		used[i] = true
	}

	for i := range used {
		used[i] = false
		if !checkWordsDiscard(words, max, used) {
			used[i] = true
		}
	}

	usedBytes := 0
	fmt.Printf("used bytes: [")
	for i, u := range used {
		if !u {
			continue
		}

		usedBytes += 1
		if i > 0 {
			fmt.Printf(", ")
		}

		fmt.Printf("%d", i)
	}

	fmt.Printf("]\n")

	lookups := make([]*Lookup, max)
	for i := range lookups {
		lookups[i] = new(Lookup)
		lookups[i].init()
	}

	try := func(lookup *Lookup) {
		for i := range *lookup {
			old := (*lookup)[i]
			found := false
			for j := byte(0); j < old; j++ {
				lookup[i] = j
				if checkWords(words, max, lookups, used) {
					found = true
					break
				}
			}

			if found {
				//fmt.Printf("changed %d: %d -> %d\n", i, old, lookup[i])
			} else {
				(*lookup)[i] = old
			}
		}
	}

	for i := range lookups {
		if !used[i] {
			continue
		}
		try(lookups[i])
	}

	total := 0
	for i := range lookups {
		if used[i] {
			fmt.Printf("lookup[%d]: %d\n", i, lookups[i].max())
			total += int(lookups[i].max())
		}
	}
	fmt.Printf("used bytes: %d\n", usedBytes)
	fmt.Printf("total sum:  %d\n", total)
}

func checkWordsDiscard(words []Keyword, n int, used []bool) bool {
	w := make([]byte, n)
	m := make(map[string]struct{})

	transform := func(word []byte) {
		for i := range word {
			w[i] = 0
		}

		j := 0
		for i, b := range word {
			if used[i] {
				w[j] = b
				j += 1
			}
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

func checkWords(words []Keyword, n int, lookups []*Lookup, used []bool) bool {
	w := make([]byte, n)
	m := make(map[string]struct{})

	transform := func(word []byte) {
		j := 0
		for i, b := range word {
			if used[i] {
				w[j] = (*lookups[i])[b]
				j += 1
			}
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
