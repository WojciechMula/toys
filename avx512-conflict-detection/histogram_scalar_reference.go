package conflictdetection

func HistogramScalarReference(indices []uint32, output []uint32) {
	for _, idx := range indices {
		output[idx] += 1
	}
}
