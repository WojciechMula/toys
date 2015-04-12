.SUFFIXES:
.PHONY: clean all

CC=g++
DEFINES=
DEFINES=-DARCH_64BIT -DHAVE_PDEP_INSTRUCTION
FLAGS=-std=c++11 -Wall -Wextra $(DEFINES)

ALL: verify speedup


all: $(ALL)

verify: verify.cpp conv_to_bin.cpp
	$(CC) $(FLAGS) $< -o $@

speedup: speedup.cpp conv_to_bin.cpp
	$(CC) $(FLAGS) -O2 -DNDEBUG $< -o $@

clean:
	rm -f $(ALL)
