.SUFFIXES:
.PHONY: all clean

FLAGS=-std=c++11 -Wall -Wextra -pedantic -march=native $(CXXFLAGS)
DEPS=parse.*.cpp common.cpp

ALL=verify benchmark

all: $(ALL)

verify: verify.cpp $(DEPS)
	$(CXX) $(FLAGS) $< -o $@

benchmark: benchmark.cpp $(DEPS)
	$(CXX) $(FLAGS) $< -o $@

clean:
	rm -f $(ALL)
