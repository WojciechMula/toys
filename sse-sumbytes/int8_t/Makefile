.SUFFIXES:
.PHONY: all
.PHONY: clean

FLAGS_COMMON=$(CXXFLAGS) -std=c++11 -Wall -Wextra -pedantic -O3 -ftree-vectorize -funroll-loops
FLAGS=$(FLAGS_COMMON) -march=native
FLAGS_AVX2=$(FLAGS_COMMON) -DHAVE_AVX2 -mavx2

OBJ=scalar.o\
    sse.o\
    sse_sadbw.o

OBJ_AVX2=scalar_avx2.o\
         sse_avx2.o\
         sse_sadbw_avx2.o\
         avx2.o\
         avx2_sadbw.o\
         avx2_maddubs.o

EXE=unittest benchmark
EXE_AVX2=unittest_avx2 benchmark_avx2

ALL=$(OBJ) $(EXE) $(OBJ_AVX2) $(EXE_AVX2)

all: $(EXE)

sse: $(EXE)

avx2: $(EXE_AVX2)

unittest: unittest.cpp $(OBJ)
	$(CXX) $(FLAGS) $^ -o $@

benchmark: benchmark.cpp $(OBJ)
	$(CXX) $(FLAGS) $^ -o $@

unittest_avx2: unittest.cpp $(OBJ_AVX2)
	$(CXX) $(FLAGS_AVX2) $^ -o $@

benchmark_avx2: benchmark.cpp $(OBJ_AVX2)
	$(CXX) $(FLAGS_AVX2) $^ -o $@

################################################################################

scalar.o: scalar.cpp scalar.h
	$(CXX) $(FLAGS) -c $< -o $@

sse.o: sse.cpp sse.h
	$(CXX) $(FLAGS) -c $< -o $@

sse_sadbw.o: sse_sadbw.cpp sse_sadbw.h
	$(CXX) $(FLAGS) -c $< -o $@

################################################################################

avx2.o: avx2.cpp avx2.h
	$(CXX) $(FLAGS_AVX2) -c $< -o $@

avx2_sadbw.o: avx2_sadbw.cpp avx2_sadbw.h
	$(CXX) $(FLAGS_AVX2) -c $< -o $@

avx2_maddubs.o: avx2_maddubs.cpp avx2_maddubs.h
	$(CXX) $(FLAGS_AVX2) -c $< -o $@

scalar_avx2.o: scalar.cpp scalar.h
	$(CXX) $(FLAGS_AVX2) -c $< -o $@

sse_avx2.o: sse.cpp sse.h
	$(CXX) $(FLAGS_AVX2) -c $< -o $@

sse_sadbw_avx2.o: sse_sadbw.cpp sse_sadbw.h
	$(CXX) $(FLAGS_AVX2) -c $< -o $@

################################################################################

%.table: %.txt
	python scripts/format.py $< > /dev/shm/tmp.rst
	mv /dev/shm/tmp.rst $@
	

RESULTS=$(wildcard results/*.txt)
RST=$(RESULTS:.txt=.table)

rst: $(RST)

clean:
	$(RM) $(ALL)
