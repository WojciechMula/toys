.PHONY: all clean

FLAGS_COMMON=$(CXXFLAGS) -O3 -Wall -Wextra -pedantic -std=c++11
FLAGS_SSE4=$(FLAGS_COMMON) -msse4.1
FLAGS_AVX512BW=$(FLAGS_COMMON) -mavx512bw -DHAVE_AVX512BW

DEPS=common.cpp\
     scalar.cpp\
     sse.cpp sse.inl sse_generate.py\
     avx512bw.cpp

ALL=unittest\

all: $(ALL)

unittest: unittest.cpp $(DEPS)
	$(CXX) $(FLAGS_SSE4) $< -o $@

unittest_avx512bw: unittest.cpp $(DEPS)
	$(CXX) $(FLAGS_AVX512BW) $< -o $@

sse.inl: sse_generate.py
	python $< $@

clean:
	$(RM) $(ALL)
