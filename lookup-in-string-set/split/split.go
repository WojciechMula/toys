package main

// findSplitByPosition takes a set of same-size keywords
// and tries to find the character position which splits
// the keywords into the greates possible numbers of
// subsets.
//
// In the best key it will find a char that fully
// distinguishes the keyword set.
func findSplitByPosition(words []Keyword, usedPositions []int) int {
	cost := len(words)
	position := -1
	n := len(words[0].word)

	used := func(pos int) bool {
		for _, p := range usedPositions {
			if p == pos {
				return true
			}
		}

		return false
	}

	for i := 0; i < n; i++ {
		if used(i) {
			continue
		}
		c := findSplitByPositionAux(words, i)
		if c < cost {
			position = i
			cost = c
			if cost == 0 {
				break
			}
		}
	}

	return position
}

func findSplitByPositionAux(words []Keyword, position int) int {
	m := make(map[byte]int)
	for i := range words {
		c := words[i].word[position]
		m[c] += 1
	}

	// The "cost" is the total number of collisions.
	// Singletons do not contribute to the cost, thus
	// the cost for the best case is 0.
	cost := 0
	for _, count := range m {
		if count > 1 {
			cost += count
		}
	}

	return cost
}

type splitBySubset struct {
	chr   byte
	words []Keyword
}

func (s *splitBySubset) append(kw Keyword) {
	s.words = append(s.words, kw)
}

func splitBy(words []Keyword, position int) []splitBySubset {
	var subsets []splitBySubset

	find := func(chr byte) int {
		for i := range subsets {
			if subsets[i].chr == chr {
				return i
			}
		}

		return -1
	}

	for i := range words {
		chr := words[i].word[position]
		idx := find(chr)
		if idx == -1 {
			subsets = append(subsets, splitBySubset{
				chr:   chr,
				words: []Keyword{words[i]},
			})
		} else {
			subsets[idx].append(words[i])
		}
	}

	return subsets
}
