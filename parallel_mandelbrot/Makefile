.SUFFIXES:
.PHONY: clean

CC=gcc
FLAGS=-std=c99 -Wall -pedantic -lpthread -O3
ALL=mandelbrot parallel_mandelbrot4 parallel_mandelbrot8 parallel_mandelbrot16 parallel_mandelbrot32

all: $(ALL)

parallel_mandelbrot4: parallel_mandelbrot.c
	$(CC) $(FLAGS) -DTHREAD_NUM=4 $^ -o $@

parallel_mandelbrot8: parallel_mandelbrot.c
	$(CC) $(FLAGS) -DTHREAD_NUM=8 $^ -o $@

parallel_mandelbrot16: parallel_mandelbrot.c
	$(CC) $(FLAGS) -DTHREAD_NUM=16 $^ -o $@

parallel_mandelbrot32: parallel_mandelbrot.c
	$(CC) $(FLAGS) -DTHREAD_NUM=32 $^ -o $@

mandelbrot: parallel_mandelbrot.c
	$(CC) $(FLAGS) -DTHREAD_NUM=1 $^ -o $@

clean:
	rm -f $(ALL)
