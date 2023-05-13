package main

type Lookup [256]byte

func (l *Lookup) init() {
	for i := range *l {
		(*l)[i] = byte(i)
	}
}

func (l *Lookup) max() byte {
	m := byte(0)
	for _, b := range *l {
		if b > m {
			m = b
		}
	}

	return m
}
