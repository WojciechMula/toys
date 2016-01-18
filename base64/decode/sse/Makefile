.SUFFIXES:
.PHONY: all

GCC=g++
FLAGS=-Wall -pedantic -O3 -std=c++11 -msse4
DEPS=decode.*.cpp config.h
ALL=verify speed check

all: $(ALL)

verify: verify.cpp $(DEPS)
	$(GCC) $(FLAGS) verify.cpp -o verify

speed: speed.cpp $(DEPS) application.cpp ../../cmdline.cpp ../../bmi2.cpp ../../gettime.cpp
	$(GCC) $(FLAGS) speed.cpp -o speed

check: check.cpp $(DEPS) application.cpp ../../cmdline.cpp ../../bmi2.cpp ../../fnv32.cpp
	$(GCC) $(FLAGS) check.cpp -o check

clean:
	rm -f $(ALL)
