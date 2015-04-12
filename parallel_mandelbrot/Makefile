.SUFFIXES:
.PHONY: clean

CC=gcc
FLAGS=-std=c99 -Wall -pedantic -lpthread -O3
ALL=parallel_mandelbrot mandelbrot

all: $(ALL)

parallel_mandelbrot: parallel_mandelbrot.c
	$(CC) $(FLAGS) $^ -o $@

mandelbrot: parallel_mandelbrot.c
	$(CC) $(FLAGS) -DTHREAD_NUM=1 $^ -o $@

clean:
	rm -f $(ALL)
