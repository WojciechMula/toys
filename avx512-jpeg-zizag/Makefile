.PHONY: all clean

FLAGS_COMMON=-O3 -Wall -Wextra -pedantic -std=c++11
FLAGS_SSE4=$(FLAGS_COMMON) -msse4.1
FLAGS_AVX512BW=$(FLAGS_COMMON) -mavx512bw -DHAVE_AVX512BW
FLAGS_AVX512VBMI=$(FLAGS_COMMON) -mavx512vbmi -DHAVE_AVX512VBMI -DHAVE_AVX512BW

DEPS=common.cpp\
     scalar.cpp\
     sse.cpp\
     avx512bw.cpp\
     avx512vbmi.cpp

ALL=unittest\
    unittest_avx512vbmi\
    unittest_avx512bw\
    benchmark\
    benchmark_avx512vbmi\
    benchmark_avx512bw

all: $(ALL)

unittest: unittest.cpp $(DEPS)
	$(CXX) $(FLAGS_SSE4) $< -o $@

unittest_avx512bw: unittest.cpp $(DEPS)
	$(CXX) $(FLAGS_AVX512BW) $< -o $@

unittest_avx512vbmi: unittest.cpp $(DEPS)
	$(CXX) $(FLAGS_AVX512VBMI) $< -o $@

benchmark: benchmark.cpp $(DEPS)
	$(CXX) $(FLAGS_SSE4) $< -o $@

benchmark_avx512bw: benchmark.cpp $(DEPS)
	$(CXX) $(FLAGS_AVX512BW) $< -o $@

benchmark_avx512vbmi: benchmark.cpp $(DEPS)
	$(CXX) $(FLAGS_AVX512VBMI) $< -o $@

clean:
	$(RM) $(ALL)
