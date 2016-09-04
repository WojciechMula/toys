.SUFFIXES:
.PHONY: all avx2 avx512 avx512bw

SDE=sde -cnl

FLAGS_BASE=-Wall -pedantic -O3 -std=c++11
HAVE_BMI2=$(shell python script/cpuflags.py bmi2)
ifeq ($(HAVE_BMI2),present)
    FLAGS_BASE+=-DHAVE_BMI2_INSTRUCTIONS
endif
FLAGS=$(FLAGS_BASE) -msse4
FLAGS_AVX2=$(FLAGS_BASE) -mavx2 -DHAVE_AVX2_INSTRUCTIONS
FLAGS_AVX512=$(FLAGS_BASE) -mavx512f -DHAVE_AVX512_INSTRUCTIONS
FLAGS_AVX512BW=$(FLAGS_BASE) -mavx512vbmi -DHAVE_AVX512BW_INSTRUCTIONS

EXT_DEPS=../../fnv32.cpp ../../bmi2.cpp ../../gettime.cpp

ALL=verify speed check
ALL_AVX2=verify_avx2 speed_avx2 check_avx2
ALL_AVX512=verify_avx512 check_avx512 speed_avx512
ALL_AVX512BW=check_avx512bw

all: $(ALL)

avx2: $(ALL_AVX2)

avx512: $(ALL_AVX512)
	$(SDE) -- ./verify_avx512
	$(SDE) -- ./check_avx512

avx512bw: $(ALL_AVX512BW)
	$(SDE) -- ./check_avx512bw

VERIFY_DEPS=verify.cpp lookup.*.cpp unpack.*.cpp encode.avx512.cpp

verify: $(VERIFY_DEPS)
	$(CXX) $(FLAGS) verify.cpp -o $@

verify_avx2: $(VERIFY_DEPS)
	$(CXX) $(FLAGS_AVX2) verify.cpp -o $@

verify_avx512: $(VERIFY_DEPS)
	$(CXX) $(FLAGS_AVX512) verify.cpp -o $@


SPEED_DEPS=speed.cpp lookup.sse.cpp encode.*.cpp unpack.*.cpp functions.cpp application.cpp config.h $(EXT_DEPS)

speed: $(SPEED_DEPS)
	$(CXX) $(FLAGS) speed.cpp -o $@

speed_avx2: $(SPEED_DEPS) lookup.avx2.cpp
	$(CXX) $(FLAGS_AVX2) speed.cpp -o $@

speed_avx512: $(SPEED_DEPS) lookup.avx2.cpp
	$(CXX) $(FLAGS_AVX512) speed.cpp -o $@


CHECK_DEPS=check.cpp lookup.sse.cpp encode.*.cpp unpack.*.cpp functions.cpp application.cpp config.h $(EXT_DEPS)

check: $(CHECK_DEPS)
	$(CXX) $(FLAGS) check.cpp -o $@

check_avx2: $(CHECK_DEPS)
	$(CXX) $(FLAGS_AVX2) check.cpp -o $@

check_avx512: $(CHECK_DEPS)
	$(CXX) $(FLAGS_AVX512) check.cpp -o $@

check_avx512bw: $(CHECK_DEPS)
	$(CXX) $(FLAGS_AVX512BW) check.cpp -o $@

clean:
	rm -f $(ALL) $(ALL_AVX2) $(ALL_AVX512)

