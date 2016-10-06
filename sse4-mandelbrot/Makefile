# Note: flag ``mfpmath=387`` is very important, because in 32-bit version
#       I mixed floating points calculations with asm statements.
FLAGS=-std=c99 -Wall -Wextra -pedantic -O3
FORCEFPU=-mfpmath=387

MAIN=main.c
DEPS=$(MAIN) fpu-proc.c
ALL=fractal32sse2 \
    fractal32sse4 \
    fractal64sse4 \
    fractal32sse2fpu \
    fractal32sse4fpu \
    fractal64sse4fpu \
    fractal64avx2 \
    fractal64avx512f \
    fractal64avx512bw

all: $(ALL)

fractal32sse2: $(DEPS) sse4-proc-32-bit.c
	$(CC) $(FLAGS) -DSSE2 -DVERSION32BIT $(MAIN) -o $@

fractal32sse4: $(DEPS) sse4-proc-32-bit.c
	$(CC) $(FLAGS) -DVERSION32BIT $(MAIN) -o $@

fractal64sse4: $(DEPS) sse4-proc-64-bit.c
	$(CC) $(FLAGS) -DVERSION64BIT $(MAIN) -o $@

fractal32sse2fpu: $(DEPS) sse4-proc-32-bit.c
	$(CC) $(FLAGS) $(FORCEFPU) -DSSE2 -DVERSION32BIT $(MAIN) -o $@

fractal32sse4fpu: $(DEPS) sse4-proc-32-bit.c
	$(CC) $(FLAGS) $(FORCEFPU) -DVERSION32BIT $(MAIN) -o $@

fractal64sse4fpu: $(DEPS) sse4-proc-64-bit.c
	$(CC) $(FLAGS) $(FORCEFPU) -DVERSION64BIT $(MAIN) -o $@

fractal64avx2: $(DEPS) avx2-proc-64-bit.c
	$(CC) $(FLAGS) -mavx2 -DVERSION64BIT -DAVX2 $(MAIN) -o $@

AVX512F_DEPS=avx512-proc-64-bit.c avx512-fma-proc-64-bit.c

fractal64avx512f: $(DEPS) $(AVX512F_DEPS)
	$(CC) $(FLAGS) -mavx512f -DVERSION64BIT -DAVX2 -DAVX512F $(MAIN) -o $@

fractal64avx512bw: $(DEPS) $(AVX512F_DEPS) avx512bw-proc-64-bit.c
	$(CC) $(FLAGS) -mavx512bw -mavx512vl -DVERSION64BIT -DAVX2 -DAVX512F -DAVX512BW $(MAIN) -o $@

clean:
	rm -f $(ALL)
