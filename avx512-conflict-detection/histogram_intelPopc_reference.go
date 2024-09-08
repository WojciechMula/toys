package conflictdetection

func HistogramIntelPopcReference(indices []uint32, output []uint32) {
	mem := output

	for len(indices) > 0 {
		chunk := vec_load(indices)
		conflicts := vec_popcnt(vec_conflicts(chunk))

		increment := vec_set1(1)

		oldValues := vec_gather(mem, chunk)
		newValues := vec_add(vec_add(oldValues, increment), conflicts)
		vec_scatter(newValues, mem, chunk)

		indices = indices[16:]
	}
}
