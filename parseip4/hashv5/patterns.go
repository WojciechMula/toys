package main

type Pattern struct {
	codeword uint16
	inputlen uint16
}

func generatePatterns() []Pattern {
	var result []Pattern
	for code := uint(0); code < 256; code++ {
		len0 := (code >> (0 * 2)) & 0x3
		len1 := (code >> (1 * 2)) & 0x3
		len2 := (code >> (2 * 2)) & 0x3
		len3 := (code >> (3 * 2)) & 0x3
		if len0 == 0 || len1 == 0 || len2 == 0 || len3 == 0 {
			continue
		}

		inputlen := uint16(len0 + len1 + len2 + len3 + 3)
		codeword := uint16(0)
		n := len0
		codeword |= 1 << n
		n += len1 + 1
		codeword |= 1 << n
		n += len2 + 1
		codeword |= 1 << n

		result = append(result, Pattern{
			codeword: codeword,
			inputlen: inputlen,
		})
	}

	return result
}
