FLAGS=$(CXXFLAGS) -O3 -Wall -Wextra -pedantic -std=c++11
FLAGS_SSE=$(FLAGS) -msse4.1 -DHAVE_SSE
FLAGS_AVX2=$(FLAGS) -mavx2 -DHAVE_SSE -DHAVE_AVX2
FLAGS_AVX512BW=$(FLAGS) -mavx512bw -DHAVE_SSE -DHAVE_AVX2 -DHAVE_AVX512BW

OBJ_SSE=scalar_sse.o sse_sse.o
OBJ_AVX2=scalar_avx2.o sse_avx2.o avx2_avx2.o
OBJ_AVX512BW=scalar_avx512bw.o sse_avx512bw.o avx2_avx512bw.o avx512bw_avx512bw.o

OBJ=$(OBJ_SSE) $(OBJ_AVX2) $(OBJ_AVX512BW)

ALL=benchmark_sse benchmark_avx2 benchmark_avx512bw\
    unittests_sse unittests_avx2 unittests_avx512bw

# --------------------------------------------------

all: $(ALL)

# --------------------------------------------------

benchmark_sse: benchmark.cpp $(OBJ_SSE)
	$(CXX) $(FLAGS_SSE) $(OBJ_SSE) $< -o $@

benchmark_avx2: benchmark.cpp $(OBJ_AVX2)
	$(CXX) $(FLAGS_AVX2) $(OBJ_AVX2) $< -o $@

benchmark_avx512bw: benchmark.cpp $(OBJ_AVX512BW)
	$(CXX) $(FLAGS_AVX512BW) $(OBJ_AVX512BW) $< -o $@

# --------------------------------------------------

unittests_sse: unittests.cpp $(OBJ_SSE)
	$(CXX) $(FLAGS_SSE) $< $(OBJ_SSE) -o $@

unittests_avx2: unittests.cpp $(OBJ_AVX2)
	$(CXX) $(FLAGS_AVX2) $< $(OBJ_AVX2) -o $@

unittests_avx512bw: unittests.cpp $(OBJ_AVX512BW)
	$(CXX) $(FLAGS_AVX512BW) $< $(OBJ_AVX512BW) -o $@

# --------------------------------------------------

scalar_sse.o: scalar.cpp scalar.h
	$(CXX) $(FLAGS_SSE) $< -c -o $@

scalar_avx2.o: scalar.cpp scalar.h
	$(CXX) $(FLAGS_AVX2) $< -c -o $@

scalar_avx512bw.o: scalar.cpp scalar.h
	$(CXX) $(FLAGS_AVX512BW) $< -c -o $@

# --------------------------------------------------

sse_sse.o: sse.cpp sse.h
	$(CXX) $(FLAGS_SSE) $< -c -o $@

sse_avx2.o: sse.cpp sse.h
	$(CXX) $(FLAGS_AVX2) $< -c -o $@

sse_avx512bw.o: sse.cpp sse.h
	$(CXX) $(FLAGS_AVX512BW) $< -c -o $@

# --------------------------------------------------

avx2_avx2.o: avx2.cpp avx2.h
	$(CXX) $(FLAGS_AVX2) $< -c -o $@

avx2_avx512bw.o: avx2.cpp avx2.h
	$(CXX) $(FLAGS_AVX512BW) $< -c -o $@

# --------------------------------------------------

avx512bw_avx512bw.o: avx512bw.cpp avx512bw.h
	$(CXX) $(FLAGS_AVX512BW) $< -c -o $@

# --------------------------------------------------

RST=skylake.rst skylake-x.rst cannonlake.rst

%.rst: results/%.txt scripts/*.py
	python scripts/format.py $< > /dev/shm/$@
	mv /dev/shm/$@ $@

rst: $(RST)

clean:
	$(RM) $(ALL) $(OBJ)

