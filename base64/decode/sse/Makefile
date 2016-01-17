.SUFFIXES:
.PHONY: all

GCC=g++
FLAGS=-Wall -pedantic -O3 -std=c++11 -mssse3
DEPS=decode.*.cpp config.h
ALL=verify speed check

all: $(ALL)

verify: verify.cpp $(DEPS)
	$(GCC) $(FLAGS) verify.cpp -o verify

speed: speed.cpp $(DEPS) ../../cmdline.cpp ../../gettime.cpp
	$(GCC) $(FLAGS) speed.cpp -o speed

check: check.cpp $(DEPS) ../../cmdline.cpp ../../fnv32.cpp
	$(GCC) $(FLAGS) check.cpp -o check

clean:
	rm -f $(ALL)
