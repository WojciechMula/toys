.PHONY: clean
.PHONY: test

FLAGS=$(CXXFLAGS) -Wall -Wextra -pedantic -std=c++11 -march=native -O3

ALL=unittests unittests_scalar benchmark

all: $(ALL)

benchmark: benchmark.cpp sse.cpp sse_kendall.cpp scalar.cpp benchmark.h
	$(CXX) $(FLAGS) $< -o $@

test: unittests unittests_scalar
	./unittests
	./unittests_scalar

unittests: unittests.cpp sse.cpp
	$(CXX) $(FLAGS) $< -o $@

unittests_scalar: unittests.cpp scalar.cpp
	$(CXX) $(FLAGS) -DTEST_SCALAR -DUNITTESTS $< -o $@

unittests_kendall: unittests.cpp sse_kendall.cpp
	$(CXX) $(FLAGS) -DTEST_KENDALL -DUNITTESTS $< -o $@

clean:
	$(RM) $(ALL)
