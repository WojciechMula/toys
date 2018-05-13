.PHONY: all clean

FLAGS_COMMON=-O2 -Wall -Wextra -pedantic -std=c++11
FLAGS_SSE4=$(FLAGS_COMMON) -msse4.1
FLAGS_AVX512VBMI=$(FLAGS_COMMON) -mavx512vbmi -DHAVE_AVX512VBMI

DEPS=common.cpp\
     scalar.cpp\
     sse.cpp\
     avx512vbmi.cpp

ALL=unittest\
    unittest_avx512vbmi

all: $(ALL)

unittest: unittest.cpp $(DEPS)
	$(CXX) $(FLAGS_SSE4) $< -o $@

unittest_avx512vbmi: unittest.cpp $(DEPS)
	$(CXX) $(FLAGS_AVX512VBMI) $< -o $@

clean:
	$(RM) $(ALL)
