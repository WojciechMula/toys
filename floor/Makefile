.SUFFIXES:
.PHONY: clean all

CC=gcc
CCFLAGS=-std=c99 -O2

all: demo print_double

demo: demo.c floor.c ieee_double.h
	$(CC) $(CCFLAGS) demo.c -o demo

print_double: print_double.c ieee_double.h
	$(CC) $(CCFLAGS) -lm print_double.c -o print_double

clean:
	rm -rf demo print_double
