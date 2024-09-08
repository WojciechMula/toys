package conflictdetection

import (
	"fmt"
	"math/rand"
	"reflect"
	"testing"
)

var functions = []struct {
	name string
	fn   func(input []uint32, output []uint32)
}{
	{
		name: "scalar",
		fn:   HistogramScalarReference,
	},
	{
		name: "Intel",
		fn:   histogramIntel,
	},
	{
		name: "IntelPopc",
		fn:   histogramIntelPopc,
	},
	{
		name: "V2",
		fn:   histogramV2,
	},
	{
		name: "V3",
		fn:   histogramV3,
	},
}

func TestHistogram(t *testing.T) {
	const size = 256
	input := make([]uint32, size)
	output := make([]uint32, bins*16)
	outputref := make([]uint32, bins)

	s := rand.NewSource(42)
	r := rand.New(s)
	const count = 1000
	for i := 0; i < count; i++ {
		reset(outputref)
		histogramReference(input, outputref)

		for j := range functions {
			tc := functions[j]
			name := fmt.Sprintf("%s/case-%d", tc.name, i)
			t.Run(name, func(t *testing.T) {
				reset(output)
				testHistogram(t, input, output, outputref, tc.fn)
			})
		}

		for j := range input {
			input[j] = uint32(r.Intn(256))
		}
	}
}

func reset(t []uint32) {
	for i := range t {
		t[i] = 0
	}
}

func testHistogram(t *testing.T, input, output, outputref []uint32, fn func([]uint32, []uint32)) {
	fn(input, output)
	if !reflect.DeepEqual(output[:bins], outputref) {
		t.Logf("got : %v", output[:bins])
		t.Logf("want: %v", outputref)
		t.Errorf("wrong result")
	}
}
