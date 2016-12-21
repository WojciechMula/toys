FLAGS=-Wall -Wextra -pedantic -std=c++11 -O3
FLAGS_AVX512=$(FLAGS) -mavx512f
FLAGS_SCALAR=$(FLAGS)
DEPS=scalar.cpp avx512f.cpp x86.cpp
ALL=validate benchmark benchmark_scalar

all: $(ALL)

validate: validate.cpp $(DEPS)
	$(CXX) $(FLAGS_AVX512) validate.cpp -o $@

benchmark: benchmark.* $(DEPS)
	$(CXX) $(FLAGS_AVX512) benchmark.cpp -DHAVE_AVX512_INSTRUCTIONS -o $@

benchmark_scalar: benchmark.* $(DEPS)
	$(CXX) $(FLAGS_SCALAR) benchmark.cpp -o $@

clean:
	rm -f $(ALL)
