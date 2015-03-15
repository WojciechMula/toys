.SUFFIXES:
.PHONY: clean

CC=gcc -std=c99 -Wall -Wextra -pedantic -O2

all: test speed

test: fbstp_test.c
	$(CC) fbstp_test.c -o $@

speed: fbstp_speed.c
	$(CC) fbstp_speed.c -o $@

clean:
	rm -rf test speed > /dev/null
