FLAGS=-Wall -Wextra -pedantic -Wfatal-errors -O3 -march=icelake-server

ALL=validate-utf8-to-utf32 validate-byte-expand validate-avx512-validate unittest benchmark
OBJ=utf8.o avx512-utf8-to-utf32.o avx512-utf8-to-utf32-ver4.o avx512-utf8-validate.o

all: $(ALL)

validate-utf8-to-utf32: validate-utf8-to-utf32.cpp $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) $@.cpp -o $@

validate-byte-expand: validate-byte-expand.cpp $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) $@.cpp -o $@

validate-avx512-validate: validate-avx512-validate.cpp utf8.o avx512-utf8-validate.o
	$(CXX) $(FLAGS) avx512-utf8-validate.o utf8.o $@.cpp -o $@

validate-avx512-validate-range: validate-avx512-validate-range.cpp utf8.o avx512-utf8-validate.o
	$(CXX) $(FLAGS) avx512-utf8-validate.o utf8.o $@.cpp -o $@

unittest: unittest.cpp $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) $@.cpp -o $@

benchmark: benchmark.cpp $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) $@.cpp -o $@

utf8.o: utf8.h utf8.cpp
	$(CXX) $(FLAGS) utf8.cpp -c -o $@

avx512-utf8-to-utf32.o: avx512-utf8-to-utf32.h avx512-utf8-to-utf32.cpp
	$(CXX) $(FLAGS) avx512-utf8-to-utf32.cpp -c -o $@

avx512-utf8-to-utf32-ver4.o: avx512-utf8-to-utf32-ver4.h avx512-utf8-to-utf32-ver4.cpp
	$(CXX) $(FLAGS) avx512-utf8-to-utf32-ver4.cpp -c -o $@

avx512-utf8-validate.o: avx512-utf8-to-utf32.h avx512-utf8-validate.cpp
	$(CXX) $(FLAGS) avx512-utf8-validate.cpp  -c -o $@

clean:
	$(RM) $(ALL) *.o
