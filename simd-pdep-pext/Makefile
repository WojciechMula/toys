FLAGS=-Wall -Wextra -pedantic -std=c++17 -O3 -ggdb
SSE_FLAGS=-march=native -D HAVE_SSE
AVX2_FLAGS=-march=native -D HAVE_AVX2
AVX512_FLAGS=-march=icelake-server -D HAVE_AVX512 #-D HAVE_AVX2

BENCH=benchmark_pext_avx2   \
      benchmark_pdep_avx2   \
      benchmark_pext_avx512 \
      benchmark_pdep_avx512 \

UT=unittest_pext_avx2   \
   unittest_pdep_avx2   \
   unittest_pext_avx512 \
   unittest_pdep_avx512 \

ALL=$(BENCH) $(UT)

DEPS=scalar.cpp impl.cpp
BENCH_DEPS=$(DEPS) benchmark.cpp.inl
UT_DEPS=$(DEPS) unittest.cpp.inl argparse.cpp
AVX2_DEPS=pext_avx2.cpp pdep_avx2.cpp
AVX512_DEPS=pext_avx512.cpp pdep_avx512.cpp

.PHONY: all
all: $(ALL)

.PHONY: bench
bench: $(BENCH)

.PHONY: ut
bench: $(UT)

benchmark_pext_avx2: benchmark_pext.cpp $(BENCH_DEPS) $(AVX2_DEPS)
	$(CXX) $(FLAGS) $(AVX2_FLAGS) $< -o $@

benchmark_pdep_avx2: benchmark_pdep.cpp $(BENCH_DEPS) $(AVX2_DEPS)
	$(CXX) $(FLAGS) $(AVX2_FLAGS) $< -o $@

unittest_pext_avx2: unittest_pext.cpp $(UT_DEPS) $(AVX2_DEPS)
	$(CXX) $(FLAGS) $(AVX2_FLAGS) $< -o $@

unittest_pdep_avx2: unittest_pdep.cpp $(UT_DEPS) $(AVX2_DEPS)
	$(CXX) $(FLAGS) $(AVX2_FLAGS) $< -o $@

benchmark_pext_avx512: benchmark_pext.cpp $(BENCH_DEPS) $(AVX2_DEPS) $(AVX512_DEPS)
	$(CXX) $(FLAGS) $(AVX512_FLAGS) $< -o $@

benchmark_pdep_avx512: benchmark_pdep.cpp $(BENCH_DEPS) $(AVX2_DEPS) $(AVX512_DEPS)
	$(CXX) $(FLAGS) $(AVX512_FLAGS) $< -o $@

unittest_pext_avx512: unittest_pext.cpp $(UT_DEPS) $(AVX2_DEPS) $(AVX512_DEPS)
	$(CXX) $(FLAGS) $(AVX512_FLAGS) $< -o $@

unittest_pdep_avx512: unittest_pdep.cpp $(UT_DEPS) $(AVX2_DEPS) $(AVX512_DEPS)
	$(CXX) $(FLAGS) $(AVX512_FLAGS) $< -o $@

.PHONY: clean
clean:
	$(RM) $(ALL)
