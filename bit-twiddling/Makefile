.SUFFIXES:

CC=gcc
FLAGS=-Wall -Wextra -pedantic
CFLAGS=-std=c99

all: is_power_of_two \
     single_bit_to_mask

is_power_of_two: is_power_of_two.c
	$(CC) $(FLAGS) $(CFLAGS) -O2 $< -o $@

single_bit_to_mask: single_bit_to_mask.c
	$(CC) $(FLAGS) $(CFLAGS) -O2 $< -o $@
