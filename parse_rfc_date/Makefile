.PHONY: clean

FLAGS=$(CXXFLAGS) -Wall -Wextra -pedantic -std=c++11 -march=native -O3

ALL=unittests unittests_scalar benchmark

all: $(ALL)

benchmark: benchmark.cpp sse.cpp scalar.cpp benchmark.h
	$(CXX) $(FLAGS) $< -o $@

unittests: unittests.cpp sse.cpp
	$(CXX) $(FLAGS) $< -o $@

unittests_scalar: unittests.cpp scalar.cpp
	$(CXX) $(FLAGS) -DTEST_SCALAR -DUNITTESTS $< -o $@

clean:
	$(RM) $(ALL)
