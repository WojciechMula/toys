.SUFFIXES:
.PHONY: clean all

CC=g++
DEFINES=-DHAVE_BSWAP_INSTRUCTION
FLAGS=-O2 -std=c++11 -Wall -Wextra $(DEFINES)

DEPS=conv_to_hex.c expand_nibble.c common.c

all: verify speedup

verify: verify.cpp $(DEPS)
	$(CC) $(FLAGS) $@.cpp -o $@

speedup: speedup.cpp $(DEPS)
	$(CC) $(FLAGS) -DNDEBUG $@.cpp -o $@

clean:
	rm -rf verify speedup
