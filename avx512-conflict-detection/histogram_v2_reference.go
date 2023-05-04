package conflictdetection

func HistogramV2Reference(indices []uint32, output []uint32) {
	mem := output

	for len(indices) > 0 {
		chunk := vec_load(indices)
		conflicts := vec_conflicts(chunk)

		subbuckets := vec_lzcnt(conflicts)
		subbuckets = vec_sub(vec_set1(32), subbuckets)

		offsets := vec_sll(chunk, 4)
		offsets = vec_add(offsets, subbuckets) // 16 * index + subbucket

		oldValues := vec_gather(mem, offsets)
		newValues := vec_add(oldValues, vec_set1(1))
		vec_scatter(newValues, mem, offsets)

		indices = indices[16:]
	}

	// finalize
	for i := 0; i < bins; i++ {
		pos := i * 16
		sum := uint32(0)
		for j := 0; j < 16; j++ {
			sum += output[pos+j]
		}

		output[i] = sum
	}
}
