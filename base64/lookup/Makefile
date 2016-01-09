.SUFFIXES:

GCC=g++
FLAGS=-Wall -pedantic -O3 -std=c++11

verify: verify.cpp lookup.*.cpp
	$(GCC) $(FLAGS) verify.cpp -o verify

clean:
	rm -f verify
