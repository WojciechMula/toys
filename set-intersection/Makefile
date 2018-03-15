.PHONY: clean
.PHONY: help

FLAGS=$(CXXFLAGS) -Wall -Wextra -pedantic -std=c++17 -march=native -O3 -g

test: *.h *.cpp config.h
	$(CXX) $(FLAGS) main.cpp -o $@

config.h:
	./config.h.sh

clean:
	$(RM) test

