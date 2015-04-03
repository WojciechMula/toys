FLAGS=-std=c99 -Wall -Wextra -pedantic -O3
CC=gcc
MAIN=main.c
DEPS=main.c fpu-proc.c

all: fractal32sse2 fractal32sse4 fractal64sse4

fractal32sse2: $(DEPS) sse4-proc-32-bit.c
	$(CC) $(FLAGS) -DSSE2 -DVERSION32BIT $(MAIN) -o $@

fractal32sse4: $(DEPS) sse4-proc-32-bit.c
	$(CC) $(FLAGS) -DVERSION32BIT $(MAIN) -o $@

fractal64sse4: $(DEPS) sse4-proc-64-bit.c
	$(CC) $(FLAGS) -DVERSION64BIT $(MAIN) -o $@

clean:
	rm -f fractal32sse2 fractal32sse4 fractal64sse4
