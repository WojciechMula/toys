.SUFFIXES:
.PHONY: all

GCC=g++
FLAGS=-Wall -pedantic -O3 -std=c++11
EXT_DEPS=../../fnv32.cpp ../../bmi2.cpp ../../gettime.cpp
ALL=verify speed check

all: $(ALL)

verify: verify.cpp lookup.*.cpp
	$(GCC) $(FLAGS) verify.cpp -o verify

speed: speed.cpp lookup.sse.cpp encode.*.cpp application.cpp config.h $(EXT_DEPS)
	$(GCC) $(FLAGS) -mssse3 speed.cpp -o speed

check: check.cpp lookup.sse.cpp encode.*.cpp application.cpp config.h $(EXT_DEPS)
	$(GCC) $(FLAGS) -mssse3 check.cpp -o check

clean:
	rm -f $(ALL)
