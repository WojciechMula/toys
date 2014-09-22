.SUFFIXES:
.PHONY: clean all

CC=g++
DEFINES=
DEFINES=-DARCH_64BIT -DHAVE_PDEP_INSTRUCTION
FLAGS=-std=c++11 -Wall -Wextra $(DEFINES)

all: verify speedup

verify: verify.cpp conv_to_bin.cpp
	$(CC) $(FLAGS) $@.cpp -o $@

speedup: speedup.cpp conv_to_bin.cpp
	$(CC) $(FLAGS) -O2 -DNDEBUG $@.cpp -o $@

clean:
	rm -rf verify speedup
