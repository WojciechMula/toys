.SUFFIXES:
.PHONY: all clean run

SDE=sde -cnl
FLAGS_BASE=-Wall -Wextra -pedantic -O3 -std=c++11

HAVE_BMI2=$(shell python script/cpuflags.py bmi2)
ifeq ($(HAVE_BMI2),present)
    FLAGS_BASE+=-DHAVE_BMI2_INSTRUCTIONS
endif

FLAGS=$(FLAGS_BASE) -msse4
FLAGS_AVX2=$(FLAGS_BASE) -mavx2 -DHAVE_AVX2_INSTRUCTIONS
FLAGS_AVX512=$(FLAGS_BASE) -mavx512vbmi -DHAVE_AVX512_INSTRUCTIONS

DEPS=decode.*.cpp decoders.*.cpp lookup.*.cpp pack.*.cpp run_all.cpp function_registry.cpp config.h

ALL=verify speed check
ALL_AVX2=verify_avx2 speed_avx2 check_avx2
ALL_AVX512=verify_avx512 check_avx512

all: run

sse: run

avx2: run_avx2

avx512: run_avx512

run: $(ALL)
	./verify
	./check
	./speed

run_avx2: $(ALL_AVX2)
	./verify_avx2
	./check_avx2
	./speed_avx2

run_avx512: $(ALL_AVX512)
	$(SDE) -- ./verify_avx512
	$(SDE) -- ./check_avx512

VERIFY_DEPS=verify.cpp $(DEPS)
SPEED_DEPS=speed.cpp $(DEPS) application.cpp ../../cmdline.cpp ../../bmi2.cpp ../../gettime.cpp
CHECK_DEPS=check.cpp $(DEPS) application.cpp ../../cmdline.cpp ../../bmi2.cpp ../../fnv32.cpp

verify: $(VERIFY_DEPS)
	$(CXX) $(FLAGS) verify.cpp -o $@

speed: $(SPEED_DEPS)
	$(CXX) $(FLAGS) speed.cpp -o $@

check: $(CHECK_DEPS)
	$(CXX) $(FLAGS) check.cpp -o $@

verify_avx2: $(VERIFY_DEPS)
	$(CXX) $(FLAGS_AVX2) verify.cpp -o $@

verify_avx512: $(VERIFY_DEPS)
	$(CXX) $(FLAGS_AVX512) verify.cpp -o $@

speed_avx2: $(SPEED_DEPS)
	$(CXX) $(FLAGS_AVX2) speed.cpp -o $@

check_avx2: $(CHECK_DEPS)
	$(CXX) $(FLAGS_AVX2) check.cpp -o $@

check_avx512: $(CHECK_DEPS)
	$(CXX) $(FLAGS_AVX512) check.cpp -o $@

clean:
	rm -f $(ALL) $(ALL_AVX2) $(ALL_AVX512)
