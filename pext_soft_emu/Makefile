.SUFFIXES:

CC=gcc
FLAGS=-Wall -Wextra -pedantic -std=c99

all: verify parse_string

verify: verify.c pext.c
	$(CC) $(FLAGS) -O2 verify.c -o $@

parse_string: parse_string.c pext.c common.c
	$(CC) $(FLAGS) -O2 parse_string.c -o $@

clean:
	rm -f verify parse_string
