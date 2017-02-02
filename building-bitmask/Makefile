.SUFFIXES:

FLAGS=-std=c++11 -O3 -Wall -Wextra -pedantic
FLAGS_AVX2=$(FLAGS) -mavx2 -DHAVE_AVX2_INSTRUCTIONS -Wpsabi
FLAGS_AVX512=$(FLAGS) -mavx512f -DHAVE_AVX512_INSTRUCTIONS
DEPS=scalar.cpp sse.cpp avx2.cpp avx512.cpp
ALL=demo demo_avx2 demo_avx512 assembly.s

all: $(ALL)

assembly.s: algorithms.cpp
	$(CXX) -O3 -S algorithms.cpp -o $@

demo: demo.cpp algorithms.cpp $(DEPS)
	$(CXX) $(FLAGS) demo.cpp -o $@

demo_avx2: demo.cpp algorithms.cpp $(DEPS)
	$(CXX) $(FLAGS_AVX2) demo.cpp -o $@

demo_avx512: demo.cpp algorithms.cpp $(DEPS)
	$(CXX) $(FLAGS_AVX512) demo.cpp -o $@
