FLAGS=-Wall -Wextra -pedantic -Wfatal-errors -O3 -march=icelake-server -flto

ALL=validate-utf8-to-utf32 validate-byte-expand unittest benchmark
OBJ=utf8.o avx512-utf8-to-utf32.o uint32-accumulator.o

all: $(ALL)

validate-utf8-to-utf32: validate-utf8-to-utf32.cpp utf8.o avx512-utf8-to-utf32.o
	$(CXX) $(FLAGS) avx512-utf8-to-utf32.o utf8.o $@.cpp -o $@

validate-byte-expand: validate-byte-expand.cpp utf8.o avx512-utf8-to-utf32.o
	$(CXX) $(FLAGS) avx512-utf8-to-utf32.o utf8.o $@.cpp -o $@

unittest: unittest.cpp $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) $@.cpp -o $@

benchmark: benchmark.cpp $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) $@.cpp -o $@

utf8.o: utf8.h utf8.cpp
	$(CXX) $(FLAGS) utf8.cpp -c -o $@

avx512-utf8-to-utf32.o: avx512-utf8-to-utf32.h avx512-utf8-to-utf32.cpp
	$(CXX) $(FLAGS) avx512-utf8-to-utf32.cpp  -c -o $@

uint32-accumulator.o: uint32-accumulator.h uint32-accumulator.cpp
	$(CXX) $(FLAGS) uint32-accumulator.cpp -c -o $@

clean:
	$(RM) $(ALL) *.o
