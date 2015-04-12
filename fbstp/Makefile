.SUFFIXES:
.PHONY: clean

CC=gcc
FLAGS=-std=c99 -Wall -Wextra -pedantic -O2
ALL=test speed

all: $(ALL)

test: fbstp_test.c
	$(CC) $(FLAGS) $< -o $@

speed: fbstp_speed.c
	$(CC) $(FLAGS) $< -o $@

clean:
	rm -f $(ALL)
