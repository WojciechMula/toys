.SUFFIXES:
.PHONY: all
.PHONY: clean

FLAGS_COMMON=$(CXXFLAGS) -std=c++11 -Wall -Wextra -pedantic -O3
FLAGS=$(FLAGS_COMMON) -march=native
FLAGS_AVX2=$(FLAGS_COMMON) -DHAVE_AVX2 -mavx2

OBJ=scalar.o\
    sse.o\
    sse_sadbw.o

 
EXE=unittest benchmark

ALL=$(OBJ) $(EXE)

all: $(EXE)

sse: $(EXE)

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

clean:
	$(RM) $(ALL)
