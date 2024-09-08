package conflictdetection

import (
	"fmt"
	"testing"
)

const KB = 1024


func TestHistogramScalarReference(t *testing.T) {
	testHistogramFunction(t, HistogramScalarReference)
}

func TestHistogramV3Reference(t *testing.T) {
	testHistogramFunction(t, HistogramV3Reference)
}

func TestHistogramV2Reference(t *testing.T) {
	testHistogramFunction(t, HistogramV2Reference)
}

func TestHistogramIntelReference(t *testing.T) {
	testHistogramFunction(t, HistogramIntelReference)
}

func TestHistogramIntelPopcReference(t *testing.T) {
	testHistogramFunction(t, HistogramIntelPopcReference)
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

		data := RandomData(16*3, 256)
		name := fmt.Sprintf("%dKB", size)
		if sorted {
			Sort(data)
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
