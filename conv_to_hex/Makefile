.SUFFIXES:
.PHONY: clean all

CC=g++
FLAGS=-O2 -std=c++11 -Wall -Wextra

all: verify speedup

verify: verify.cpp conv_to_hex.c expand_nibble.c
	$(CC) $(FLAGS) $@.cpp -o $@

speedup: speedup.cpp conv_to_hex.c expand_nibble.c
	$(CC) $(FLAGS) -DNDEBUG $@.cpp -o $@

clean:
	rm -rf verify speedup
