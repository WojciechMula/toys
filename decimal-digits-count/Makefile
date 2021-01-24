CC=gcc
FLAGS=-Wall -Wextra -pedantic -std=c99

.SUFFIXES:

demo: *.c
	$(CC) $(FLAGS) demo.c -o $@

demo_avx512: *.c
	$(CC) $(FLAGS) -DAVX512 -mavx512f demo.c -o $@

ARGUMENTS=0 1 22 333 4444 55555 666666 7777777 88888888 999999999 1010101010

test: demo
	./demo $(ARGUMENTS)

test_avx512: demo_avx512
	./demo_avx512 $(ARGUMENTS)

clean:
	rm -f demo
