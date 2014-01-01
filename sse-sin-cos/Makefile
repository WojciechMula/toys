.SUFFIXES:
.PHONY: clean all

CC=gcc
CCFLAGS=-std=c99 -O2 -lm -Wall

all: test_speed test_accuracy

test_speed: test_speed.c taylor.c sse-sin.c
	$(CC) $(CCFLAGS) test_speed.c -o test_speed

test_accuracy: test_accuracy.c sse-sin.c
	$(CC) $(CCFLAGS) test_accuracy.c -o test_accuracy

clean:
	rm -rf test_speed
	rm -rf test_accuracy
