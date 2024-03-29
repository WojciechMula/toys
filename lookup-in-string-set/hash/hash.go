package main

import (
	"fmt"
)

// computerHashParameters takes list of keywords and a hash function,
// and finds the size of hashtable that minimizes collisions.
//
// It returns the size and the number of collisions.
func computerHashParameters(keywords []Keyword, hash func([]byte) uint64) (size int, collisions int) {
	collisions = 1
	hashes := make([]uint64, len(keywords))
	for i := range keywords {
		hashes[i] = hash(keywords[i].word)
	}
	for {
		size = hashtableaux(hashes, collisions)
		if size > 0 {
			fmt.Printf("size = %5d, maxcollisions = %d\n", size, collisions)
			return
		}
		collisions += 1
	}
}

func hashtableaux(hashes []uint64, maxcollisions int) int {
	n := len(hashes)
	const sizeOverhead = 10

outer:
	for N := n; N < sizeOverhead*n; N++ {
		table := make(map[uint64]int)
		for _, h := range hashes {
			idx := h % uint64(N)
			table[idx] += 1
			if table[idx] > maxcollisions {
				continue outer
			}
		}
		return N
	}

	return -1
}

type LookupEntry struct {
	word  []byte
	value string
	hash  uint64
}

func compileLookup(keywords []Keyword, size, collisions int, hash func([]byte) uint64) (lookup []LookupEntry) {
	lookup = make([]LookupEntry, size*collisions)

	for i := range keywords {
		h := hash(keywords[i].word)
		idx := (h % uint64(size)) * uint64(collisions)

		found := false
		for j := uint64(0); j < uint64(collisions); j++ {
			if lookup[idx+j].value == "" {
				lookup[idx+j].word = keywords[i].word
				lookup[idx+j].value = keywords[i].value
				lookup[idx+j].hash = h
				found = true
				break
			}
		}

		if !found {
			panic("wrong parameters for hash (didn't find a free slot)")
		}
	}

	return
}
