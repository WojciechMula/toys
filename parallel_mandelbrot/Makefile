.SUFFIXES:
.PHONY: clean

CC=gcc
FLAGS=-std=c99 -Wall -pedantic -lpthread -O3

all: parallel_mandelbrot mandelbrot

parallel_mandelbrot: parallel_mandelbrot.c
	$(CC) $(FLAGS) $^ -o $@

mandelbrot: parallel_mandelbrot.c
	$(CC) $(FLAGS) -DTHREAD_NUM=1 $^ -o $@

clean:
	rm -rf parallel_mandelbrot
	rm -rf mandelbrot
