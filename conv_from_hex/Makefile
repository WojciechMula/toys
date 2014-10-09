.SUFFIXES:

CC=g++
FLAGS=-Wall -Wextra -pedantic -std=c++11

all: verify

verify: verify.cpp pext.c parse_hex_string.c
	$(CC) $(FLAGS) -O2 verify.cpp -o $@

clean:
	rm -f verify
