FLAGS=-Wall -Wextra -pedantic -std=c++17 -O3 -ggdb
AVX2_FLAGS=-march=native -D HAVE_AVX2 -D HAVE_SSE
AVX512_FLAGS=-march=icelake-server -D HAVE_AVX512 -D HAVE_AVX2 -D HAVE_SSE

ALL=unittest_avx2 \
    benchmark_avx2 \
    rcp_tests

DEPS=scalar.cpp impl.cpp
AVX2_DEPS=avx2.cpp
AVX512_DEPS=avx512.cpp

all: $(ALL)

unittest_avx2: unittest.cpp $(DEPS) $(AVX2_DEPS)
	$(CXX) $(FLAGS) $(AVX2_FLAGS) $< -o $@

benchmark_avx2: benchmark.cpp $(DEPS) $(AVX2_DEPS)
	$(CXX) $(FLAGS) $(AVX2_FLAGS) $< -o $@

rcp_tests: rcp_tests.cpp $(DEPS)
	$(CXX) $(FLAGS) $(AVX2_FLAGS) $< -o $@

rcp_diff: rcp_diff.cpp $(DEPS)
	$(CXX) $(FLAGS) $(AVX2_FLAGS) $< -o $@

clean:
	$(RM) $(ALL)
