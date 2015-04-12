.SUFFIXES:
.PHONY: clean all

CC=gcc
CCFLAGS=-std=c99 -O2 -lm -Wall
ALL=test_speed test_accuracy

all: $(ALL)

test_speed: test_speed.c taylor.c sse-sin.c
	$(CC) $(CCFLAGS) $< -o $@

test_accuracy: test_accuracy.c sse-sin.c
	$(CC) $(CCFLAGS) $< -o $@

clean:
	rm -f $(ALL)
