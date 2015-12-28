CC=gcc
FLAGS=-Wall -Wextra -std=c99 -O3

run: demo
	./demo

demo: demo.c movmask.c
	$(CC) $(FLAGS) $< -o $@

clean:
	rm -f demo
