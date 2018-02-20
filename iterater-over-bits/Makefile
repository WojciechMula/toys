.PHONY: clean

FLAGS=-O2 -std=c++11 -Wall -Wextra -pedantic $(CXXFLAGS)

test: main.cpp bitvector.h
	$(CXX) $(FLAGS) main.cpp -o $@

clean:
	$(RM) test

