FLAGS=-Wall -Wextra -pedantic -Wfatal-errors -O3 -march=icelake-server -std=c++17

ALL=validate-utf8-to-utf32 validate-byte-expand validate-avx512-validate unittest benchmark check
OBJ=utf8.o avx512-utf8-to-utf32.o avx512-utf8-to-utf32-ver4.o avx512-utf8-validate.o avx512-expand.o avx512-transcode-utf8.o

all: $(ALL)

validate-utf8-to-utf32: validate-utf8-to-utf32.cpp avx512-transcode-utf8.o utf8.o
	$(CXX) $(FLAGS) utf8.o avx512-transcode-utf8.o $@.cpp -o $@

validate-byte-expand: validate-byte-expand.cpp avx512-expand.o
	$(CXX) $(FLAGS) avx512-expand.o $@.cpp -o $@

validate-avx512-validate: validate-avx512-validate.cpp utf8.o avx512-utf8-validate.o
	$(CXX) $(FLAGS) avx512-utf8-validate.o utf8.o $@.cpp -o $@

validate-avx512-validate-range: validate-avx512-validate-range.cpp utf8.o avx512-utf8-validate.o
	$(CXX) $(FLAGS) avx512-utf8-validate.o utf8.o $@.cpp -o $@

unittest: unittest.cpp $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) $@.cpp -o $@

check: check.cpp $(OBJ) bom.o
	$(CXX) $(FLAGS) $(OBJ) bom.o $@.cpp -o $@

benchmark: benchmark.cpp $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) $@.cpp -o $@

utf8.o: utf8.h utf8.cpp
	$(CXX) $(FLAGS) utf8.cpp -c -o $@

bom.o: bom.h bom.cpp
	$(CXX) $(FLAGS) bom.cpp -c -o $@

avx512-utf8-to-utf32.o: avx512-utf8-to-utf32.h avx512-utf8-to-utf32.cpp
	$(CXX) $(FLAGS) avx512-utf8-to-utf32.cpp -c -o $@

avx512-utf8-to-utf32-ver4.o: avx512-utf8-to-utf32-ver4.h avx512-utf8-to-utf32-ver4.cpp
	$(CXX) $(FLAGS) avx512-utf8-to-utf32-ver4.cpp -c -o $@

avx512-utf8-validate.o: avx512-utf8-to-utf32.h avx512-utf8-validate.cpp
	$(CXX) $(FLAGS) avx512-utf8-validate.cpp  -c -o $@

avx512-expand.o: avx512-expand.h avx512-expand*.cpp
	$(CXX) $(FLAGS) avx512-expand.cpp  -c -o $@

avx512-transcode-utf8.o: avx512-transcode-utf8.h avx512-transcode-utf8*.cpp
	$(CXX) $(FLAGS) avx512-transcode-utf8.cpp  -c -o $@

clean:
	$(RM) $(ALL) *.o
