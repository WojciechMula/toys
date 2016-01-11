.SUFFIXES:
.PHONY: all

GCC=g++
FLAGS=-Wall -pedantic -O3 -std=c++11

all: verify speed

verify: verify.cpp lookup.*.cpp
	$(GCC) $(FLAGS) verify.cpp -o verify

speed: speed.cpp lookup.sse.cpp encode.*.cpp config.h ../../fnv32.cpp ../../bmi2.cpp ../../gettime.cpp
	$(GCC) $(FLAGS) -mssse3 speed.cpp -o speed

clean:
	rm -f verify speed
