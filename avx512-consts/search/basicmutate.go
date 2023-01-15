package main

func ShiftRightLogical(word uint32, fn func(*Program)) {
	p := &Program{name: "SRL", args: []any{int(0), word}}

	for i := 1; i < 32; i++ {
		w := word >> i
		p.value = w
		p.args[0] = i
		fn(p)
	}
}

func ShiftRightArithmetic(word uint32, fn func(*Program)) {
	if int32(word) >= 0 {
		return
	}

	p := &Program{name: "SRA", args: []any{int(0), word}}

	w := word
	for i := 0; i < 32; i++ {
		w = (w >> 1) | (w & 0x80000000)
		p.value = w
		p.args[0] = i
		fn(p)
	}
}

func ShiftLeftLogical(word uint32, fn func(*Program)) {
	p := &Program{name: "SHL", args: []any{int(0), word}}

	for i := 1; i < 32; i++ {
		w := word << i
		p.value = w
		p.args[0] = i
		fn(p)
	}
}

func AbsoluteValue(word uint32, fn func(*Program)) {
	w := int32(word)
	if w < 0 {
		w = -w
		p := &Program{
			value: uint32(w),
			name:  "ABS",
			args:  []any{word},
		}

		fn(p)
	}

}

func RotateRight(word uint32, fn func(*Program)) {
	w := word
	for i := 1; i <= 32; i++ {
		w = (w >> 1) | ((w & 1) << 31)
		fn(&Program{
			value: w,
			name:  "ROR",
			args:  []any{i, word},
		})
	}
}

func LeadingZeroCount(word uint32, fn func(*Program)) {
	n := uint32(0)
	for i := 0; i < 32; i++ {
		if word&0x80000000 != 0 {
			break
		}

		n += 1
		word <<= 1
	}

	fn(&Program{
		value: n,
		name:  "LZCNT",
		args:  []any{word},
	})
}

func Negate(word uint32, fn func(*Program)) {
	w := uint32(-int32(word))
	fn(&Program{
		value: w,
		name:  "SUB",
		args:  []any{uint32(0), word},
	})
}
