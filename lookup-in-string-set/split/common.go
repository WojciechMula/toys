package main

import (
	"bytes"
	"fmt"
	"os"
	"strconv"
)

type Keyword struct {
	word  []byte
	value string
}

func readList(path string) ([]Keyword, error) {
	buf, err := os.ReadFile(path)
	if err != nil {
		return nil, err
	}

	tmp := bytes.Split(buf, []byte{'\n'})
	uniq := make(map[string]struct{})
	words := make([]Keyword, 0, len(tmp))
	for _, line := range tmp {
		if len(line) == 0 || line[0] == '#' {
			continue
		}

		s := string(line)
		if _, ok := uniq[s]; ok {
			return nil, fmt.Errorf("found duplicated word %q", s)
		}

		uniq[s] = struct{}{}
		words = append(words, Keyword{
			word:  line,
			value: strconv.Itoa(len(words)),
		})
	}

	return words, nil
}
