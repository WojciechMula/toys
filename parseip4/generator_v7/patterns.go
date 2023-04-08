package main

import (
	"math/bits"
)

type Pattern struct {
	len0     int
	len1     int
	len2     int
	len3     int
	codeword uint16
}

func (p *Pattern) inputlen() int {
	return p.len0 + p.len1 + p.len2 + p.len3 + 3
}

func (p *Pattern) valid() bool {
	return (p.len0 >= 1 && p.len0 <= 3) &&
		(p.len1 >= 1 && p.len1 <= 3) &&
		(p.len2 >= 1 && p.len2 <= 3) &&
		(p.len3 >= 1 && p.len3 <= 3)
}

func (p *Pattern) id() int {
	return 27*(p.len3-1) + 9*(p.len2-1) + 3*(p.len1-1) + (p.len0 - 1)
}

func (p *Pattern) maxlen() int {
	l := p.len0
	if p.len1 > l {
		l = p.len1
	}
	if p.len2 > l {
		l = p.len2
	}
	if p.len3 > l {
		l = p.len3
	}

	return l
}

func (p *Pattern) pshufb() (b [16]byte) {
	switch p.maxlen() {
	case 1:
		return p.pshufbMax1()
	case 2:
		return p.pshufbMax2()
	case 3:
		return p.pshufbMax3()
	}

	return b
}

func (p *Pattern) pshufbMax1() [16]byte {
	var b [16]byte

	for i := range b {
		b[i] = 0xff
	}

	offset := byte(0)
	for i, l := range []int{p.len0, p.len1, p.len2, p.len3} {
		idx := i
		switch l {
		case 1:
			b[idx] = offset
			offset += 2
		default:
			panic("wrong length")
		}
	}

	return b
}

func (p *Pattern) pshufbMax2() [16]byte {
	var b [16]byte

	for i := range b {
		b[i] = 0xff
	}

	offset := byte(0)
	for i, l := range []int{p.len0, p.len1, p.len2, p.len3} {
		idx := i
		switch l {
		case 1:
			b[idx+4] = offset
			offset += 2
		case 2:
			b[idx] = offset
			b[idx+4] = offset + 1
			offset += 3
		default:
			panic("wrong length")
		}
	}

	return b
}

func (p *Pattern) pshufbMax3() [16]byte {
	var b [16]byte

	for i := range b {
		b[i] = 0xff
	}

	offset := byte(0)
	for i, l := range []int{p.len0, p.len1, p.len2, p.len3} {
		idx := i
		switch l {
		case 1:
			b[2*idx+1] = offset
			offset += 2
		case 2:
			b[2*idx+0] = offset + 0
			b[2*idx+1] = offset + 1
			b[2*idx+8+1] = offset + 0
			offset += 3
		case 3:
			b[2*idx+0] = offset + 1
			b[2*idx+1] = offset + 2
			b[2*idx+8] = offset + 0
			b[2*idx+8+1] = offset + 0
			offset += 4
		}
	}

	return b
}

func generatePatterns() []Pattern {
	var result []Pattern
	for len0 := 0; len0 < 16; len0++ {
		for len1 := 0; len1 < 16; len1++ {
			for len2 := 0; len2 < 16; len2++ {
				for len3 := 0; len3 < 16; len3++ {
					p0 := len0
					p1 := p0 + 1 + len1
					p2 := p1 + 1 + len2
					p3 := p2 + 1 + len3

					codeword := uint16((1 << p0) | (1 << p1) | (1 << p2) | (1 << p3))
					if bits.OnesCount16(codeword) != 4 {
						continue
					}

					p := Pattern{
						len0:     len0,
						len1:     len1,
						len2:     len2,
						len3:     len3,
						codeword: codeword,
					}

					if p.valid() {
						result = append(result, p)
					}
				}
			}
		}
	}

	return result
}
