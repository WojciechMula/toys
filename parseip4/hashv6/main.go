package main

import (
	"fmt"
	"runtime"
	"sync"
	"sync/atomic"
)

func main() {
	codes := possibleInputs()
	m := make([]Metainfo, 0, len(codes))
	fmt.Printf("codes having exactly four bits set: %d\n", len(codes))
	for _, code := range codes {
		p0, p1, p2, p3 := code.pos()
		m = append(m, Metainfo{
			p0: uint16(p0),
			p1: uint16(p1),
			p2: uint16(p2),
			p3: uint16(p3),
			ok: code.valid(),
		})
	}

	k := runtime.GOMAXPROCS(0)
	var wg sync.WaitGroup
	wg.Add(k)
	slice := len(multipliers) / k

	tmp := multipliers[:]

	var multipliers0 []uint16
	for i := 0; i < k; i++ {
		if i == k-1 {
			multipliers0 = tmp
		} else {
			multipliers0 = tmp[:slice]
			tmp = tmp[slice:]
		}

		go func(multipliers0, multipliers123 []uint16) {
			defer wg.Done()
			checkAll(m, multipliers0, multipliers123, multipliers123, multipliers123)
		}(multipliers0, multipliers)
	}

	wg.Wait()
}

type Metainfo struct {
	p0, p1, p2, p3 uint16
	ok             bool
}

func checkAll(m []Metainfo, multipliers0, multipliers1, multipliers2, multipliers3 []uint16) {
	bi := new(Bitmap)
	var max uint64
	for _, a := range multipliers0 {
		for _, b := range multipliers1 {
			for _, c := range multipliers2 {
				for _, d := range multipliers3 {
					max = atomic.LoadUint64(&globalmax)

					bi.reset()
					newmax, ok := check(bi, m, a, b, c, d, uint16(max))
					if ok && newmax <= max {
						globalmutex.Lock()
						notworse := newmax <= globalmax
						if newmax < globalmax {
							globalmax = newmax
						}
						globalmutex.Unlock()
						if notworse {
							fmt.Printf("%d: %d*p0 + %d*p1 + %d*p2 + %d*p3\n", max, a, b, c, d)
						}
					}
				}
			}
		}
	}
}

var globalmax = uint64(0xffff)
var globalmutex sync.Mutex

func check(bi *Bitmap, m []Metainfo, a, b, c, d uint16, currentmax uint16) (uint64, bool) {
	max := uint16(0)
	for i, _ := range m {
		hashcode := a*m[i].p0 + b*m[i].p1 + c*m[i].p2 + d*m[i].p3
		if !bi.add(hashcode) {
			return 0, false
		}

		if hashcode > currentmax {
			return 0, false
		}

		if hashcode > max {
			max = hashcode
		}
	}

	return uint64(max), true
}

var multipliers = []uint16{
	0, 1, 2, 4, 8, 16, 32, 64, 128, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997,
}
