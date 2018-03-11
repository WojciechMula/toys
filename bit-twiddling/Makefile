.SUFFIXES:
.PHONY: clean

CC=gcc
FLAGS=-Wall -Wextra -pedantic
CFLAGS=-std=c99

ALL=is_power_of_two \
    is_power_of_two_bmi1 \
    single_bit_to_mask \
    all-higher-set


all: $(ALL)

is_power_of_two: is_power_of_two.c
	$(CC) $(FLAGS) $(CFLAGS) -O2 $< -o $@

is_power_of_two_bmi1: is_power_of_two_bmi1.c
	$(CC) $(FLAGS) $(CFLAGS) -march=native -O2 $< -o $@

single_bit_to_mask: single_bit_to_mask.c
	$(CC) $(FLAGS) $(CFLAGS) -O2 $< -o $@

all-higher-set: all-higher-set.c
	$(CC) $(FLAGS) $(CFLAGS) -O2 $< -o $@

clean:
	$(RM) $(ALL)

