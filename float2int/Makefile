.SUFFIXES:
.PHONY: clean all

CC=gcc
CCFLAGS=-std=c99 -O3 -Wall -pedantic

all: demo verify

demo: demo.c float2int.c
	$(CC) $(CCFLAGS) demo.c -o demo

verify: verify.c float2int.c
	$(CC) $(CCFLAGS) -lm verify.c -o verify

clean:
	rm -rf demo verify
