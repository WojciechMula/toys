CC=gcc
FLAGS=-Wall -Wextra -pedantic -std=c99

.SUFFIXES:

demo: *.c
	$(CC) $(FLAGS) demo.c -o $@

test: demo
	./demo 0 1 22 333 4444 55555 666666 7777777 88888888 999999999 1010101010

clean:
	rm -f demo
