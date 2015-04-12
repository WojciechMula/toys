.SUFFIXES:
.PHONY: clean all

CC=g++
DEFINES=-DHAVE_BSWAP_INSTRUCTION
FLAGS=-O2 -std=c++11 -Wall -Wextra $(DEFINES)

DEPS=conv_to_hex.c expand_nibble.c common.c
ALL=verify speedup

all: $(ALL)

verify: verify.cpp $(DEPS)
	$(CC) $(FLAGS) $< -o $@

speedup: speedup.cpp $(DEPS)
	$(CC) $(FLAGS) -DNDEBUG $< -o $@

clean:
	rm -f $(ALL)
