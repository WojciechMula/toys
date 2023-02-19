package main

type Bitmap struct {
	m       [65536 / 64]uint64
	indices []uint16 // track which words were touched since last `reset`
}

func (b *Bitmap) add(x uint16) bool {
	idx := x / 64
	b.indices = append(b.indices, idx)
	word := b.m[idx]
	bit := uint64(1) << (x % 64)
	if word&bit == 0 {
		b.m[idx] = word | bit
		return true
	}

	return false
}

func (b *Bitmap) reset() {
	for _, idx := range b.indices {
		b.m[idx] = 0
	}

	b.indices = b.indices[:0]
}
