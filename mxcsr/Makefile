.SUFFIXES:
.PHONY: clean all

CC=gcc
CCFLAGS=-std=c99 -Wall -pedantic
ALL=test_flush_to_zero test_invalid_operation test_denormal test_denormal_speed test_divide_by_zero

all: $(ALL)

test_flush_to_zero: test_flush_to_zero.c mxcsr.c time.c
	$(CC) $(CCFLAGS) $@.c -o $@

test_invalid_operation: test_invalid_operation.c mxcsr.c
	$(CC) $(CCFLAGS) $@.c -o $@

test_denormal: test_denormal.c mxcsr.c
	$(CC) $(CCFLAGS) $@.c -o $@

test_denormal_speed: test_denormal_speed.c mxcsr.c fpclassify.c time.c
	$(CC) $(CCFLAGS) -lm $@.c -o $@

test_divide_by_zero: test_divide_by_zero.c mxcsr.c
	$(CC) $(CCFLAGS) $@.c -o $@

clean:
	rm -rf $(ALL)
