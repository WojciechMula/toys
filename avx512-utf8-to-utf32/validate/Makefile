FLAGS=-Wall -Wextra -pedantic -Wfatal-errors -O3 -march=icelake-server -std=c++17

ALL=unittest

all: $(ALL)

unittest: unittest.cpp utf8-sequences.h reference.o utf8-sequences.o
	$(CXX) $(FLAGS) reference.o utf8-sequences.o unittest.cpp -o $@

utf8-sequences.cpp utf8-sequences.h: unittest.py
	python3 unittest.py

utf8-sequences.o: utf8-sequences.cpp utf8-sequences.h
	$(CXX) $(FLAGS) utf8-sequences.cpp -c -o $@

reference.o: reference.cpp reference.h
	$(CXX) $(FLAGS) reference.cpp -c -o $@

clean:
	$(RM) $(ALL) *.o
