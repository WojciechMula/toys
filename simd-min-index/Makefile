.PHONY: clean
.PHONY: sse
.PHONY: avx2

FLAGS=$(CXXFLAGS) -O3 -march=native -std=c++11 -Wall -Wextra -pedantic
FLAGS_AVX2=$(FLAGS) -mavx2 -DHAVE_AVX2

PROCEDURES=all.cpp\
           scalar.cpp\
           sse.cpp\
           sse_unrolled.cpp

PROCEDURES_AVX2=avx2.cpp $(PROCEDURES)

SSE=benchmark unittest
AVX2=benchmark_avx2 unittest_avx2
ALL=$(SSE) $(AVX2)

all: $(ALL)

sse: $(SSE)

avx2: $(AVX2)

benchmark: benchmark.cpp $(PROCEDURES)
	$(CXX) $(FLAGS) $< -o $@

unittest: unittest.cpp $(PROCEDURES)
	$(CXX) $(FLAGS) $< -o $@

benchmark_avx2: benchmark.cpp $(PROCEDURES_AVX2)
	$(CXX) $(FLAGS_AVX2) $< -o $@

unittest_avx2: unittest.cpp $(PROCEDURES_AVX2)
	$(CXX) $(FLAGS_AVX2) $< -o $@


clean:
	$(RM) $(ALL)
