FLAGS=-Wall -Wextra -pedantic -Wfatal-errors -O3 -march=icelake-server -flto

ALL=validate unittest benchmark

all: $(ALL)

validate: validate.cpp utf8.o avx512-utf8-to-utf32.o
	$(CXX) $(FLAGS) avx512-utf8-to-utf32.o utf8.o validate.cpp -o $@

unittest: unittest.cpp utf8.o avx512-utf8-to-utf32.o
	$(CXX) $(FLAGS) avx512-utf8-to-utf32.o utf8.o unittest.cpp -o $@

benchmark: benchmark.cpp utf8.o avx512-utf8-to-utf32.o
	$(CXX) $(FLAGS) avx512-utf8-to-utf32.o utf8.o benchmark.cpp -o $@

utf8.o: utf8.h utf8.cpp
	$(CXX) $(FLAGS) utf8.cpp -c -o $@

avx512-utf8-to-utf32.o: avx512-utf8-to-utf32.h avx512-utf8-to-utf32.cpp
	$(CXX) $(FLAGS) avx512-utf8-to-utf32.cpp  -c -o $@

clean:
	$(RM) $(ALL) *.o
