FLAGS=-Wall -Wextra -pedantic -std=c++17 -O3 -ggdb
AVX2_FLAGS=-march=native -D HAVE_AVX2
AVX512_FLAGS=-march=icelake-server -D HAVE_AVX512 -D HAVE_AVX2

ALL=unittest_avx2 \
    benchmark_avx2 \
    unittest_avx512 \
    benchmark_avx512 \
    rcp_tests

DEPS=scalar.cpp impl.cpp
AVX2_DEPS=avx2.cpp
AVX512_DEPS=avx512.cpp

all: $(ALL)

unittest_avx2: unittest.cpp $(DEPS) $(AVX2_DEPS)
	$(CXX) $(FLAGS) $(AVX2_FLAGS) $< -o $@

benchmark_avx2: benchmark.cpp $(DEPS) $(AVX2_DEPS)
	$(CXX) $(FLAGS) $(AVX2_FLAGS) $< -o $@

unittest_avx512: unittest.cpp $(DEPS) $(AVX512_DEPS)
	$(CXX) $(FLAGS) $(AVX512_FLAGS) $< -o $@

benchmark_avx512: benchmark.cpp $(DEPS) $(AVX512_DEPS)
	$(CXX) $(FLAGS) $(AVX512_FLAGS) $< -o $@

rcp_tests: rcp_tests.cpp $(DEPS)
	$(CXX) $(FLAGS) $(AVX2_FLAGS) $< -o $@

rcp_diff: rcp_diff.cpp $(DEPS)
	$(CXX) $(FLAGS) $(AVX2_FLAGS) $< -o $@

clean:
	$(RM) $(ALL)
