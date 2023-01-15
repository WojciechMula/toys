package main

type context struct {
	input uint32

	abs_byte uint32
	abs_word uint32

	float32_to_int32 uint32
	int32_to_float32 uint32
	rcp_float32      uint32
	rcp_sqrt_float32 uint32
}

// go:noescape
// go:nosplit
func avx512(ctx *context)

func Avx512Mutate(word uint32, fn func(*Program)) {
	var ctx context

	ctx.input = word
	avx512(&ctx)

	fn(&Program{
		value: ctx.abs_byte,
		name:  "ABSB",
		args:  []any{word},
	})

	fn(&Program{
		value: ctx.abs_word,
		name:  "ABSW",
		args:  []any{word},
	})

	fn(&Program{
		value: ctx.float32_to_int32,
		name:  "f32->i32",
		args:  []any{word},
	})

	fn(&Program{
		value: ctx.int32_to_float32,
		name:  "i32->f32",
		args:  []any{word},
	})

	fn(&Program{
		value: ctx.rcp_float32,
		name:  "1/x",
		args:  []any{word},
	})

	fn(&Program{
		value: ctx.rcp_sqrt_float32,
		name:  "1/sqrt(x)",
		args:  []any{word},
	})
}
