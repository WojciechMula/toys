.SUFFIXES:

CC=gcc
FLAGS=-std=c99 -Wall -Wextra -pedantic -O2

all: demo

demo: pdep_soft_emu.c
	$(CC) $(FLAGS) $^ -o $@

clean:
	rm -f demo
