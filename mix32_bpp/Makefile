.SUFFIXES:
.PHONY: all clean

FLAGS=-O3 -Wall -pedantic -std=c99

all: measure

measure: mix
	./mix measure x86 100
	./mix measure SSE4 100
	./mix measure SSE4-2 100

mix: mix_32bpp.c
	gcc $(FLAGS) -m32 mix_32bpp.c -o mix

clean:
	rm mix
