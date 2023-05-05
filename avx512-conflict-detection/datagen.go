package conflictdetection

import (
	"math/rand"
	"sort"
)

func RandomData(size int, maxval int) []uint32 {
	if size%16 != 0 {
		panic("size has to be multiply of 16")
	}

	s := rand.NewSource(42)
	r := rand.New(s)

	res := make([]uint32, size)
	for i := 0; i < size; i++ {
		res[i] = uint32(r.Intn(maxval)) & 0xff
	}

	return res
}

func Sort(arr []uint32) []uint32 {
	sort.Slice(arr, func(i, j int) bool {
		return arr[i] < arr[j]
	})

	return arr
}
