package conflictdetection

import (
	"fmt"
	"math/bits"
	"strings"
)

type vector [16]uint32
type kreg uint16

const maskFull kreg = 0xffff

func vec_load(mem []uint32) (v vector) {
	for i := range v {
		v[i] = mem[i]
	}
	return
}

func vec_gather(mem []uint32, indices vector) (v vector) {
	for i := range indices {
		v[i] = mem[indices[i]]
	}
	return
}

func vec_scatter(values vector, mem []uint32, indices vector) {
	for i := range indices {
		mem[indices[i]] = values[i]
	}
}

func vec_set1(x uint32) (v vector) {
	for i := range v {
		v[i] = x
	}
	return
}

func vec_equals(v1, v2 vector) kreg {
	var mask kreg
	for i := range v1 {
		if v1[i] == v2[i] {
			mask |= (kreg(1) << i)
		}
	}
	return mask
}

func vec_not_equals(v1, v2 vector) kreg {
	mask := vec_equals(v1, v2)
	return ^mask
}

func vec_lzcnt(v vector) (res vector) {
	for i, x := range v {
		res[i] = uint32(bits.LeadingZeros32(x))
	}
	return
}

func vec_add(v1, v2 vector) (res vector) {
	return vec_add_masked(v1, v2, maskFull)
}

func vec_add_masked(v1, v2 vector, mask kreg) (res vector) {
	bit := kreg(1)
	for i := range v1 {
		if mask&bit != 0 {
			res[i] = v1[i] + v2[i]
		} else {
			res[i] = v1[i]
		}
		bit <<= 1
	}
	return
}

func vec_sub(v1, v2 vector) (res vector) {
	for i := range v1 {
		res[i] = v1[i] - v2[i]
	}
	return
}

func vec_sll(v vector, n uint) (res vector) {
	for i := range v {
		res[i] = v[i] << n
	}
	return
}

func vec_conflicts(v vector) (res vector) {
	for i := 0; i < 16; i++ {
		mask := uint32(0)
		bit := uint32(1)

		x := v[i]
		for j := 0; j < i; j++ {
			if x == v[j] {
				mask |= bit
			}
			bit <<= 1
		}
		res[i] = mask
	}
	return
}

func vec_permute_masked(values, indices vector, mask kreg) (res vector) {
	bit := kreg(1)

	for i := range indices {
		if mask&bit != 0 {
			idx := indices[i] & 0xf
			res[i] = values[idx]
		} else {
			res[i] = values[i]
		}

		bit <<= 1
	}
	return
}

func vec_mask(v vector, k kreg) (res vector) {
	bit := kreg(1)
	for i := range v {
		if k&bit != 1 {
			res[i] = v[i]
		} else {
			res[i] = 0
		}

		bit <<= 1
	}

	return res
}

func (vec vector) format(f string) string {
	buf := &strings.Builder{}
	signed := (f[len(f)-1] == 'd')
	for i := 15; i >= 0; i-- {
		if i == 15 {
			buf.WriteByte('[')
		} else {
			buf.WriteByte('|')
		}

		if signed {
			fmt.Fprintf(buf, f, int32(vec[i]))
		} else {
			fmt.Fprintf(buf, f, vec[i])
		}
	}

	buf.WriteByte(']')

	return buf.String()
}
