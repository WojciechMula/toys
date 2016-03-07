.SUFFIXES:
.PHONY: all clean

FLAGS=-O3 -Wall -Wextra -pedantic -Werror -std=c99 -m32
SH=/bin/bash

all: blur.log

blur: blur.c
	gcc $(FLAGS) $^ -o $@

blur.log: blur
	$(SH) measure.sh

clean:
	rm -f blur blur.log
