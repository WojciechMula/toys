package conflictdetection

const valueBits = 8
const bins = 1 << valueBits

// Procedure implements histogram schema showed in "Intel 64 and IA-32 Architectures
// Optimization Reference Manual", section "Example 18-19. Scatter Implementation
// Alternatives". Document revision: January 2023 (046A).

// go:noescape
// go:nosplit
func histogramIntelAsm(ptr *uint32, count uint64, output *uint32)

func histogramIntel(input []uint32, output []uint32) {
	histogramIntelAsm(&input[0], uint64(len(input)), &output[0])
}

// Procedure implements histogram schema using vpconflictd and vpopcntd
// as inspired by the generation from the icx compiler

// go:noescape
// go:nosplit
func histogramIntelPopcAsm(ptr *uint32, count uint64, output *uint32)

func histogramIntelPopc(input []uint32, output []uint32) {
	histogramIntelPopcAsm(&input[0], uint64(len(input)), &output[0])
}

// Procedure implements alternative histogram algorithm

// go:noescape
// go:nosplit
func histogramV2Asm(ptr *uint32, count uint64, output *uint32)

func histogramV2(input []uint32, output []uint32) {
	histogramV2Asm(&input[0], uint64(len(input)), &output[0])
	if cap(output) != bins*16 {
		panic("wrong output size")
	}

	// the final step
	for i := 0; i < bins; i++ {
		pos := i * 16
		sum := uint32(0)
		for j := 0; j < 16; j++ {
			sum += output[pos+j]
		}

		output[i] = sum
	}
}

// Procedure implements alternative histogram algorithm without vpconflictd

// go:noescape
// go:nosplit
func histogramV3Asm(ptr *uint32, ptr2 *uint32, count uint64, output *uint32)

func histogramV3(input []uint32, output []uint32) {
	id := []uint32{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}
	histogramV3Asm(&input[0], &id[0], uint64(len(input)), &output[0])
	if cap(output) != bins*16 {
		panic("wrong output size")
	}

	// the final step
	for i := 0; i < bins; i++ {
		pos := i * 16
		sum := uint32(0)
		for j := 0; j < 16; j++ {
			sum += output[pos+j]
		}

		output[i] = sum
	}
}

func histogramReference(input []uint32, output []uint32) {
	for _, idx := range input {
		output[idx] += 1
	}
}
