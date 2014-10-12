.SUFFIXES:

CC=g++
FLAGS=-Wall -Wextra -pedantic -std=c++11
DEPS=common.c pext.c parse.*.c

all: verify

verify: verify.cpp $(DEPS)
	$(CC) $(FLAGS) -O2 verify.cpp -o $@

clean:
	rm -f verify
