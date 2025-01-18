FLAGS=$(CXXFLAGS) -Wall -Wextra -pedantic -std=c++17 -O3 -Werror
AVX2_FLAGS=$(FLAGS) -DHAVE_AVX2 -march=native
AVX512_FLAGS=$(FLAGS) -DHAVE_AVX2 -DHAVE_AVX512 -march=icelake-server

AVX2_DEPS=push_heap.h push_heap_avx2.h
AVX512_DEPS=$(AVX2_DEPS)

ALL=validate_avx2 \
    validate_avx512 \
    benchmark_avx2 \
    benchmark_avx512

.PHONY: all
all: $(ALL)

validate_avx2: validate.cpp $(AVX2_DEPS)
	$(CXX) $(AVX2_FLAGS) validate.cpp -o $@

validate_avx512: validate.cpp $(AVX512_DEPS)
	$(CXX) $(AVX512_FLAGS) validate.cpp -o $@

benchmark_avx2: benchmark.cpp $(AVX2_DEPS)
	$(CXX) $(AVX2_FLAGS) benchmark.cpp -o $@

benchmark_avx512: benchmark.cpp $(AVX512_DEPS)
	$(CXX) $(AVX512_FLAGS) benchmark.cpp -o $@

.PHONY: clean
clean:
	$(RM) $(ALL)
