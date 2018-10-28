.PHONY: all clean

FLAGS_COMMON=$(CXXFLAGS) -O3 -Wall -Wextra -pedantic -std=c++11
FLAGS_SSE4=$(FLAGS_COMMON) -msse4.1
FLAGS_AVX512F=$(FLAGS_COMMON) -mavx512f -DHAVE_AVX512F
FLAGS_AVX512BW=$(FLAGS_COMMON) -mavx512bw -DHAVE_AVX512F -DHAVE_AVX512BW

DEPS=common.cpp\
     scalar.cpp\
     sse.cpp sse.inl sse-copy-single.inl sse_generate.py\
     avx512f.cpp avx512f.inl avx512f_generate.py\
     avx512bw.cpp

ALL=unittest\

all: $(ALL)

unittest: unittest.cpp $(DEPS)
	$(CXX) $(FLAGS_SSE4) $< -o $@

unittest_avx512f: unittest.cpp $(DEPS)
	$(CXX) $(FLAGS_AVX512F) $< -o $@

unittest_avx512bw: unittest.cpp $(DEPS)
	$(CXX) $(FLAGS_AVX512BW) $< -o $@

benchmark: benchmark.cpp $(DEPS)
	$(CXX) $(FLAGS_SSE4) $< -o $@

benchmark_avx512f: benchmark.cpp $(DEPS)
	$(CXX) $(FLAGS_AVX512F) $< -o $@

benchmark_avx512bw: benchmark.cpp $(DEPS)
	$(CXX) $(FLAGS_AVX512BW) $< -o $@

sse.inl: sse_generate.py
	python $< $@

sse-copy-single.inl: sse_generate.py
	python $< --copy-single $@

avx512f.inl: avx512f_generate.py
	python $< $@

clean:
	$(RM) $(ALL)
