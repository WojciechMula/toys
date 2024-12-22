package conflictdetection

func HistogramV3Reference(indices []uint32, output []uint32) {
	mem := output

	id := []uint32{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}
	vid := vec_load(id)

	for len(indices) > 0 {
		chunk := vec_load(indices)
		offsets := vec_sll(chunk, 4)
		offsets = vec_add(offsets, vid) // 16 * index + subbucket

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
