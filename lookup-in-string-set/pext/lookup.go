package main

import (
	"bytes"
	"fmt"
)

func generatePdepGroupBy(buf *bytes.Buffer, basename string, words []Keyword) error {
	bylen := make(map[int]*[]Keyword)
	for i := range words {
		n := len(words[i].word)
		list, ok := bylen[n]
		if !ok {
			list = new([]Keyword)
			bylen[n] = list
		}

		*list = append(*list, words[i])
	}

	a := generateCpp{}
	a.programs = make(map[int]Program)
	a.lookups = make(map[int]*Lookup)
	a.ctx.output = buf
	a.ctx.argname = "s"
	a.ctx.defval = "-1"
	a.ctx.basename = basename
	a.ctx.signature = fmt.Sprintf("int lookup_%s(std::string_view s)", basename)
	for n, list := range bylen {
		mask, err := samesize(*list)
		if err != nil {
			return err
		}
		prog := compile(mask)
		a.programs[n] = prog
		a.lookups[n] = &Lookup{
			indices: pdepLookup(prog, *list),
			words:   *list,
		}
	}

	a.write()

	return nil
}

func checksamesize(words []Keyword, mask []byte) bool {
	M := make(map[string]struct{})
	word := make([]byte, len(mask))
	for i := range words {
		for j := range mask {
			word[j] = words[i].word[j] & mask[j]
		}

		s := string(word)
		_, ok := M[s]
		if ok {
			return false
		}
		M[s] = struct{}{}
	}

	return true
}

func samesize(words []Keyword) (mask []byte, err error) {
	max := 0
	for _, w := range words {
		if n := len(w.word); n > max {
			max = n
		}
	}

	mask = make([]byte, max)
	for i := range mask {
		mask[i] = 0xff
	}

	ok := checksamesize(words, mask)
	if !ok {
		err = fmt.Errorf("set of words is not unique")
		return
	}

	for byteIdx := 0; byteIdx < max; byteIdx++ {
		for bitIdx := 0; bitIdx < 8; bitIdx++ {
			old := mask[byteIdx]
			mask[byteIdx] &= ^(1 << bitIdx)
			if !checksamesize(words, mask) {
				mask[byteIdx] = old
			}
		}
	}

	return
}

func pdepLookup(prog Program, words []Keyword) []int {
	result := make([]int, 1<<prog.lookupSize())
	for i := range result {
		result[i] = -1
	}

	for i := range words {
		val := prog.evaluate(words[i].word)
		result[val] = i
	}

	return result
}
