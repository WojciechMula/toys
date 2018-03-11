.SUFFIXES:

CC=gcc
FLAGS=-Wall -Wextra -pedantic
CFLAGS=-std=c99

all: is_power_of_two \
     is_power_of_two_bmi2 \
     single_bit_to_mask \
     all-higher-set

is_power_of_two: is_power_of_two.c
	$(CC) $(FLAGS) $(CFLAGS) -O2 $< -o $@

is_power_of_two_bmi2: is_power_of_two_bmi2.c
	$(CC) $(FLAGS) $(CFLAGS) -march=skylake -O2 $< -o $@

single_bit_to_mask: single_bit_to_mask.c
	$(CC) $(FLAGS) $(CFLAGS) -O2 $< -o $@

all-higher-set: all-higher-set.c
	$(CC) $(FLAGS) $(CFLAGS) -O2 $< -o $@
