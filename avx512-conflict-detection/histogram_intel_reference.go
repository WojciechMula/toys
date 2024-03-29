package conflictdetection

func HistogramIntelReference(indices []uint32, output []uint32) {
	mem := output

	zeros := vec_set1(0)
	neg1 := vec_set1(0xffffffff)
	for len(indices) > 0 {
		chunk := vec_load(indices)
		conflicts := vec_conflicts(chunk)

		increment := vec_set1(1)

		anyConflict := vec_not_equals(conflicts, zeros)
		if anyConflict != 0 {
			// position[i] = 31 - leadingZeros(conflicts[i])
			position := vec_lzcnt(conflicts)
			position = vec_sub(vec_set1(31), position)

			active := anyConflict
			count := 0
			for {
				count += 1
				conflicted := vec_permute_masked(increment, position, active)
				conflicted = vec_mask(conflicted, active)

				increment = vec_add_masked(increment, conflicted, active)

				position = vec_permute_masked(position, position, active)

				active = vec_not_equals(position, neg1)
				if active == 0 {
					break
				}
			}
		}

		oldValues := vec_gather(mem, chunk)
		newValues := vec_add(oldValues, increment)
		vec_scatter(newValues, mem, chunk)

		indices = indices[16:]
	}
}
