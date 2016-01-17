.SUFFIXES:
.PHONY: all

GCC=g++
FLAGS=-Wall -pedantic -O3 -std=c++11 -mssse3
ALL=verify speed

all: $(ALL)

verify: verify.cpp decode.*.cpp
	$(GCC) $(FLAGS) verify.cpp -o verify

speed: speed.cpp decode.*.cpp ../../gettime.cpp ../../cmdline.cpp ../../fnv32.cpp
	$(GCC) $(FLAGS) speed.cpp -o speed

clean:
	rm -f $(ALL)
