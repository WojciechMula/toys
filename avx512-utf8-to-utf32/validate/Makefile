FLAGS=-Wall -Wextra -pedantic -Wfatal-errors -O3 -march=icelake-server -std=c++17

ALL=unittest

all: $(ALL)

unittest: unittest.cpp utf8-sequences.o reference.o avx512-validate-utf8.o
	$(CXX) $(FLAGS) avx512-validate-utf8.o reference.o utf8-sequences.o unittest.cpp -o $@

utf8-sequences.cpp utf8-sequences.h: utf8-sequences.py
	python3 utf8-sequences.py

utf8-sequences.o: utf8-sequences.cpp utf8-sequences.h
	$(CXX) $(FLAGS) utf8-sequences.cpp -c -o $@

reference.o: reference.cpp reference.h
	$(CXX) $(FLAGS) reference.cpp -c -o $@

avx512-validate-utf8.o: avx512-validate-utf8.cpp avx512-validate-utf8.h avx512*-validate*.cpp
	$(CXX) $(FLAGS) avx512-validate-utf8.cpp -c -o $@

clean:
	$(RM) $(ALL) *.o
