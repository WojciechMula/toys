package conflictdetection

import (
	"fmt"
	"math/rand"
	"sort"
	"testing"
)

const KB = 1024

func TestHistogramV2Reference(t *testing.T) {
	testHistogramFunction(t, HistogramV2Reference)
}

func TestHistogramIntelReference(t *testing.T) {
	testHistogramFunction(t, HistogramIntelReference)
}

func testHistogramFunction(t *testing.T, histogramFunc func(input, output []uint32)) {
	t.Helper()
	for i := 1; i < 21; i++ {
		sorted := i > 10
		var size int
		if sorted {
			size = i - 10
		} else {
			size = i
		}

		data := testRandomData(16*3, 256)
		name := fmt.Sprintf("%dKB", size)
		if sorted {
			testSort(data)
			name = fmt.Sprintf("%s-sorted", name)
		}

		want := make([]uint32, 256*16)
		histogramReference(data, want)
		t.Run(name, func(t *testing.T) {
			got := make([]uint32, 256*16)
			histogramFunc(data, got)
			testCompareHistograms(t, want, got)
		})
	}
}

func testCompareHistograms(t *testing.T, want, got []uint32) {
	t.Helper()

	for i := 0; i < 256; i++ {
		if want[i] != got[i] {
			t.Errorf("%d: want=%d, got=%d", i, want[i], got[i])
		}
	}
}

func testRandomData(size int, maxval int) []uint32 {
	if size%16 != 0 {
		panic("size has to be multiply of 16")
	}

	s := rand.NewSource(42)
	r := rand.New(s)

	res := make([]uint32, size)
	for i := 0; i < size; i++ {
		res[i] = uint32(r.Intn(maxval)) & 0xff
		res[i] = 1
	}

	return res
}

func testSort(arr []uint32) []uint32 {
	sort.Slice(arr, func(i, j int) bool {
		return arr[i] < arr[j]
	})

	return arr
}
