.SUFFIXES:
.PHONY: clean all run

CC=gcc
CCFLAGS=-std=c99 -Wall -pedantic
ALL=test_flush_to_zero test_invalid_operation test_denormal_speed test_divide_by_zero

all: $(ALL)

run: test_flush_to_zero test_denormal_speed
	./test_flush_to_zero
	./test_denormal_speed

test_flush_to_zero: test_flush_to_zero.c mxcsr.c time.c
	$(CC) $(CCFLAGS) $< -o $@

test_invalid_operation: test_invalid_operation.c mxcsr.c
	$(CC) $(CCFLAGS) $< -o $@

test_denormal_speed: test_denormal_speed.c mxcsr.c fpclassify.c time.c
	$(CC) $(CCFLAGS) -lm $< -o $@

test_divide_by_zero: test_divide_by_zero.c mxcsr.c
	$(CC) $(CCFLAGS) $< -o $@

clean:
	rm -rf $(ALL)
