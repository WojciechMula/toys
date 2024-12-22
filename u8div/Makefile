FLAGS=-Wall -Wextra -pedantic -std=c++17 -O3 -ggdb
SSE_FLAGS=-march=native -D HAVE_SSE
AVX2_FLAGS=-march=native -D HAVE_AVX2 -D HAVE_SSE
AVX512_FLAGS=-march=icelake-server -D HAVE_AVX512 -D HAVE_AVX2 -D HAVE_SSE

ALL=unittest_sse \
    unittest_avx2 \
    unittest_avx512 \
    benchmark_sse \
    benchmark_avx2 \
    benchmark_avx512 \
    rcp_tests \
    rcp_diff \
    cmp_check

DEPS=scalar.cpp impl.cpp
SSE_DEPS=sse.cpp sse_long_div.cpp
AVX2_DEPS=avx2.cpp avx2_long_div.cpp
AVX512_DEPS=avx512.cpp avx512_long_div.cpp

all: $(ALL)

unittest_sse: unittest.cpp $(DEPS) $(SSE_DEPS)
	$(CXX) $(FLAGS) $(SSE_FLAGS) $< -o $@

unittest_avx2: unittest.cpp $(DEPS) $(AVX2_DEPS)
	$(CXX) $(FLAGS) $(AVX2_FLAGS) $< -o $@

unittest_avx512: unittest.cpp $(DEPS) $(AVX512_DEPS)
	$(CXX) $(FLAGS) $(AVX512_FLAGS) $< -o $@

benchmark_sse: benchmark.cpp $(DEPS) $(SSE_DEPS)
	$(CXX) $(FLAGS) $(SSE_FLAGS) $< -o $@

benchmark_avx2: benchmark.cpp $(DEPS) $(AVX2_DEPS)
	$(CXX) $(FLAGS) $(AVX2_FLAGS) $< -o $@

benchmark_avx512: benchmark.cpp $(DEPS) $(AVX512_DEPS)
	$(CXX) $(FLAGS) $(AVX512_FLAGS) $< -o $@

rcp_tests: rcp_tests.cpp
	$(CXX) $(FLAGS) $(SSE_FLAGS) $< -o $@

rcp_diff: rcp_diff.cpp
	$(CXX) $(FLAGS) $(SSE_FLAGS) $< -o $@

cmp_check: cmp_check.cpp
	$(CXX) $(FLAGS) $(SSE_FLAGS) $< -o $@

clean:
	$(RM) $(ALL)
