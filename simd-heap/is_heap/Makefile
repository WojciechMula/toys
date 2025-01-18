FLAGS=$(CXXFLAGS) -Wall -Wextra -pedantic -std=c++17 -O3 -Werror
FLAGS_AVX2=$(FLAGS) -march=native
FLAGS_AVX512=$(FLAGS) -D HAVE_AVX512 -march=icelake-server # change to native, when running tests

DEPS=is_heap_scalar.h   \
     is_heap_sse.cpp    \
     is_heap_avx2.cpp

ALL=validate benchmark validate_avx512 benchmark_avx512

.PHONY: all
all: $(ALL)

test: validate
	./validate 256 512 1024 4096 8192 16384 32768

bench: benchmark
	./benchmark 256 512 1024 4096 8192 16384 32768 65536

validate: validate.cpp $(DEPS)
	$(CXX) $(FLAGS_AVX2) validate.cpp -o $@

validate_avx512: validate.cpp $(DEPS) is_heap_avx512.cpp
	$(CXX) $(FLAGS_AVX512) validate.cpp -o $@

benchmark: benchmark.cpp $(DEPS)
	$(CXX) $(FLAGS_AVX2) benchmark.cpp -o $@

benchmark_avx512: benchmark.cpp $(DEPS) is_heap_avx512.cpp
	$(CXX) $(FLAGS_AVX512) benchmark.cpp -o $@

.PHONY: clean
clean:
	$(RM) $(ALL)
