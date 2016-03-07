.SUFFIXES:
.PHONY: all clean

FLAGS=-O3 -Wall -Wextra -pedantic -Werror -std=c99 -m32

all: blur

blur: blur.c
	gcc $(FLAGS) $^ -o $@

clean:
	rm -f blur
