.PHONY: clean
.PHONY: help

FLAGS=$(CXXFLAGS) -Wall -Wextra -pedantic -std=c++17 -march=native -O3 -g

test: *.cpp *.h
	$(CXX) $(FLAGS) main.cpp -o $@

clean:
	$(RM) test

