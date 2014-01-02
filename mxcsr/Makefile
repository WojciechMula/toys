.SUFFIXES:
.PHONY: clean all

CC=gcc
CCFLAGS=-std=c99

all: test_flush_to_zero test_invalid_operation

test_flush_to_zero: test_flush_to_zero.c mxcsr.c time.c
	$(CC) $(CCFLAGS) $@.c -o $@

test_invalid_operation: test_invalid_operation.c mxcsr.c
	$(CC) $(CCFLAGS) $@.c -o $@

clean:
	rm -rf test_flush_to_zero test_invalid_operation
