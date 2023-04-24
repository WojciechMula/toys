package main

// pext is software implemntation of x86 PEXT instruction
func pext(w, m uint64) uint64 {
	res := uint64(0)
	bit := uint64(1)
	for w != 0 {
		if m&1 == 1 {
			if w&1 == 1 {
				res |= bit
			}

			bit <<= 1
		}

		w >>= 1
		m >>= 1
	}

	return res
}
