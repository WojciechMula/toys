.SUFFIXES:
.PHONY: clean all

CC=g++
DEFINES=-DARCH_64BIT
FLAGS=-std=c++11 -Wall -Wextra $(DEFINES)
DEPS=conv_to_bin.cpp config.h
ALL=verify speedup


all: $(ALL)

verify: verify.cpp $(DEPS)
	$(CC) $(FLAGS) $< -o $@

speedup: speedup.cpp $(DEPS)
	$(CC) $(FLAGS) -O2 -DNDEBUG $< -o $@

clean:
	rm -f $(ALL)
