.SUFFIXES:
.PHONY: all clean
FILES=hexprint hexprint_aligned branchless_hex
SH=/bin/bash

FLAGS=-O3 -Wall -pedantic -Werror -std=c99 -m32
TIME=/usr/bin/time -f "%E"

all: hexprint.log hexprint_aligned.log branchless_hex

hexprint: hexprint.c
	gcc $(FLAGS) $^ -o $@

hexprint_aligned: hexprint.c
	gcc $(FLAGS) -DALIGN_BUFFER $^ -o $@

branchless_hex: branchless_hex.c
	gcc $(FLAGS) $^ -o $@

hexprint.log: hexprint
	$(SH) measure.sh $^

hexprint_aligned.log: hexprint_aligned
	$(SH) measure.sh $^

clean:
	rm -f $(FILES)
