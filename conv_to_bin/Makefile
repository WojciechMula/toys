.SUFFIXES:
.PHONY: clean all

CC=g++
FLAGS=-O2 -std=c++11 -Wall -Wextra

all: verify speedup

verify: verify.cpp conv_to_bin.cpp
	$(CC) $(FLAGS) $@.cpp -o $@

speedup: speedup.cpp conv_to_bin.cpp
	$(CC) $(FLAGS) $@.cpp -o $@

clean:
	rm -rf verify speedup
