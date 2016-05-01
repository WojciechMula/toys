# Note: flag ``mfpmath=387`` is very important, because in 32-bit version
#       I mixed floating points calculations with asm statements.
CC=gcc
FLAGS=-std=c99 -Wall -Wextra -pedantic -O3
FORCEFPU=-mfpmath=387

MAIN=main.c
DEPS=$(MAIN) fpu-proc.c
ALL=fractal32sse2 fractal32sse4 fractal64sse4 fractal32sse2fpu fractal32sse4fpu fractal64sse4fpu fractal64avx2

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

clean:
	rm -f $(ALL)
