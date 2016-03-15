.SUFFIXES:
.PHONY: all avx2

CC=g++
FLAGS=-Wall -pedantic -O3 -std=c++11
EXT_DEPS=../../fnv32.cpp ../../bmi2.cpp ../../gettime.cpp
ALL=verify speed check
ALL_AVX2=verify_avx2 speed_avx2 check_avx2

all: $(ALL)

avx2: $(ALL_AVX2)


VERIFY_DEPS=verify.cpp lookup.*.cpp

verify: $(VERIFY_DEPS)
	$(CC) $(FLAGS) -msse4 verify.cpp -o $@

verify_avx2: $(VERIFY_DEPS)
	$(CC) $(FLAGS) -mavx2 -DHAVE_AVX2_INSTRUCTIONS verify.cpp -o $@


SPEED_DEPS=speed.cpp lookup.sse.cpp encode.*.cpp application.cpp config.h $(EXT_DEPS)

speed: $(SPEED_DEPS)
	$(CC) $(FLAGS) -msse4 speed.cpp -o $@

speed_avx2: $(SPEED_DEPS) lookup.avx2.cpp
	$(CC) $(FLAGS) -mavx2 -DHAVE_AVX2_INSTRUCTIONS speed.cpp -o $@


CHECK_DEPS=check.cpp lookup.sse.cpp encode.*.cpp application.cpp config.h $(EXT_DEPS)

check: $(CHECK_DEPS)
	$(CC) $(FLAGS) -msse4 check.cpp -o $@

check_avx2: $(CHECK_DEPS)
	$(CC) $(FLAGS) -mavx2 -DHAVE_AVX2_INSTRUCTIONS check.cpp -o $@

clean:
	rm -f $(ALL) $(ALL_AVX2)
