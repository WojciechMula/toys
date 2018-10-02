.SUFFIXES:
.PHONY: clean
.PHONY: sse
.PHONY: avx2

FLAGS=$(CXXFLAGS) -O3 -march=native -std=c++11 -Wall -Wextra -pedantic
FLAGS_AVX2=$(FLAGS) -mavx2 -DHAVE_AVX2
FLAGS_AVX512=$(FLAGS) -mavx512f -DHAVE_AVX2 -DHAVE_AVX512

PROCEDURES=all.cpp\
           scalar.cpp\
           sse.cpp\
           sse_unrolled.cpp

PROCEDURES_AVX2=avx2.cpp $(PROCEDURES)
PROCEDURES_AVX512=avx512f.cpp $(PROCEDURES_AVX2)

SSE=benchmark unittest
AVX2=benchmark_avx2 unittest_avx2
AVX512=benchmark_avx512 unittest_avx512
ALL=$(SSE) $(AVX2) $(AVX512)

all: $(ALL)

sse: $(SSE)

avx2: $(AVX2)

avx512: $(AVX512)


procedures.o: all.cpp all.h $(PROCEDURES)
	$(CXX) $(FLAGS) -c $< -o $@

procedures_avx2.o: all.cpp all.h $(PROCEDURES_AVX2)
	$(CXX) $(FLAGS_AVX2) -c $< -o $@

procedures_avx512.o: all.cpp all.h $(PROCEDURES_AVX512)
	$(CXX) $(FLAGS_AVX512) -c $< -o $@


benchmark: benchmark.cpp procedures.o
	$(CXX) $(FLAGS) $^ -o $@

unittest: unittest.cpp procedures.o
	$(CXX) $(FLAGS) $^ -o $@


benchmark_avx2: benchmark.cpp procedures_avx2.o
	$(CXX) $(FLAGS_AVX2) $^ -o $@

unittest_avx2: unittest.cpp procedures_avx2.o
	$(CXX) $(FLAGS_AVX2) $^ -o $@


benchmark_avx512: benchmark.cpp procedures_avx512.o
	$(CXX) $(FLAGS_AVX512) $^ -o $@

unittest_avx512: unittest.cpp procedures_avx512.o
	$(CXX) $(FLAGS_AVX512) $^ -o $@


clean:
	$(RM) $(ALL) *.o
