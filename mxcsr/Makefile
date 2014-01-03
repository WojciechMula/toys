.SUFFIXES:
.PHONY: clean all

CC=gcc
CCFLAGS=-std=c99
ALL=test_flush_to_zero test_invalid_operation test_denormal test_divide_by_zero

all: $(ALL)

test_flush_to_zero: test_flush_to_zero.c mxcsr.c time.c
	$(CC) $(CCFLAGS) $@.c -o $@

test_invalid_operation: test_invalid_operation.c mxcsr.c
	$(CC) $(CCFLAGS) $@.c -o $@

test_denormal: test_denormal.c mxcsr.c
	$(CC) $(CCFLAGS) $@.c -o $@

test_divide_by_zero: test_divide_by_zero.c mxcsr.c
	$(CC) $(CCFLAGS) $@.c -o $@

clean:
	rm -rf $(ALL)
