.SUFFIXES:
.PHONY: all

GCC=g++
FLAGS=-Wall -pedantic -O3 -std=c++11 -mssse3
ALL=verify

all: $(ALL)

verify: verify.cpp decode.*.cpp
	$(GCC) $(FLAGS) verify.cpp -o verify

clean:
	rm -f $(ALL)
