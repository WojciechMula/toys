.SUFFIXES:
.PHONY: all clean run

CC=g++
FLAGS=-Wall -pedantic -O3 -std=c++11
DEPS=decode.*.cpp decoders.*.cpp lookup.*.cpp config.h
ALL=verify speed check
ALL_AVX2=verify_avx2 speed_avx2 check_avx2

all: run

sse: run

avx2: run_avx2

run: $(ALL)
	./verify
	./check
	./speed

run_avx2: $(ALL_AVX2)
	./verify_avx2
	./check_avx2
	./speed_avx2

VERIFY_DEPS=verify.cpp $(DEPS)
SPEED_DEPS=speed.cpp $(DEPS) application.cpp ../../cmdline.cpp ../../bmi2.cpp ../../gettime.cpp
CHECK_DEPS=check.cpp $(DEPS) application.cpp ../../cmdline.cpp ../../bmi2.cpp ../../fnv32.cpp

verify: $(VERIFY_DEPS)
	$(CC) $(FLAGS) -msse4 verify.cpp -o $@

speed: $(SPEED_DEPS)
	$(CC) $(FLAGS) -msse4 speed.cpp -o $@

check: $(CHECK_DEPS)
	$(CC) $(FLAGS) -msse4 check.cpp -o $@

verify_avx2: $(VERIFY_DEPS)
	$(CC) $(FLAGS) -mavx2 -DHAVE_AVX2_INSTRUCTIONS verify.cpp -o $@

speed_avx2: $(SPEED_DEPS)
	$(CC) $(FLAGS) -mavx2 -DHAVE_AVX2_INSTRUCTIONS speed.cpp -o $@

check_avx2: $(CHECK_DEPS)
	$(CC) $(FLAGS) -mavx2 -DHAVE_AVX2_INSTRUCTIONS check.cpp -o $@

clean:
	rm -f $(ALL) $(ALL_AVX2)
