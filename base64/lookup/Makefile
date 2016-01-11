.SUFFIXES:
.PHONY: all

GCC=g++
FLAGS=-Wall -pedantic -O3 -std=c++11

all: verify speed

verify: verify.cpp lookup.*.cpp
	$(GCC) $(FLAGS) verify.cpp -o verify

speed: speed.cpp fnv32.cpp lookup.sse.cpp encode.*.cpp bmi2.cpp config.h
	$(GCC) $(FLAGS) -mssse3 speed.cpp -o speed

clean:
	rm -f verify speed
