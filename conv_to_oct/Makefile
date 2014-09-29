.SUFFIXES:

CC=g++
FLAGS=-std=c++11 -Wall -Wextra -pedantic
DEPS=conv.swar.c conv.pdep.c conv.sse2.c common.c

all: verify speedup

verify: verify.cpp $(DEPS)
	$(CC) $(FLAGS) verify.cpp -o $@

speedup: speedup.cpp $(DEPS)
	$(CC) $(FLAGS) speedup.cpp -o $@

clean:
	rm -f verify speedup

