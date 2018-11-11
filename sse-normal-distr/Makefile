.PHONY: clean

FLAGS=$(CXXFLAGS) -std=c++14 -Wall -Wextra -pedantic

ALL=benchmark

all: $(ALL)

benchmark: benchmark.cpp *.h
	$(CXX) $(FLAGS) $< -o $@

clean:
	$(RM) $(ALL)

