.SUFFIXES:
.PHONY: all clean

FLAGS=-O3 -Wall -pedantic -std=c99
ITERATIONS=10000

measure: blend
	time -p ./blend measure x86    $(ITERATIONS)
	time -p ./blend measure ssse3  $(ITERATIONS)
	time -p ./blend measure sse4   $(ITERATIONS)
	time -p ./blend measure sse4-2 $(ITERATIONS)

blend: blend_32bpp.c
	gcc $(FLAGS) -m32 blend_32bpp.c -o blend

clean:
	rm blend

