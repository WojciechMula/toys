.PHONY: all, clean

FLAGS_COMMON=-O3 -std=c++11 -Wall -Wextra -pedantic
FLAGS=$(FLAGS_COMMON) -march=native
FLAGS_AVX2=$(FLAGS_COMMON) -mavx2 -DHAVE_AVX2

DEPS=scalar.cpp sse.cpp sse.simd-generic.cpp
DEPS_AVX2=$(DEPS) avx2.cpp

ALL=unittest benchmark unittest_avx2 benchmark_avx2

all: $(ALL)

unittest: unittest.cpp $(DEPS)
	$(CXX) $(FLAGS) $< -o $@

benchmark: benchmark.cpp $(DEPS) time_utils.h
	$(CXX) $(FLAGS) $< -o $@

unittest_avx2: unittest.cpp $(DEPS_AVX2)
	$(CXX) $(FLAGS_AVX2) $< -o $@

benchmark_avx2: benchmark.cpp $(DEPS) time_utils.h
	$(CXX) $(FLAGS_AVX2) $< -o $@

clean:
	$(RM) $(ALL)

