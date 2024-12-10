FLAGS=-Wall -Wextra -pedantic -std=c++17 -O3 -ggdb
FLAGS+=-march=native

ALL=unittest benchmark rcp_tests
DEPS=scalar.cpp sse.cpp avx2.cpp manual.cpp impl.cpp

all: $(ALL)

unittest: unittest.cpp $(DEPS)
	$(CXX) $(FLAGS) unittest.cpp -o unittest

benchmark: benchmark.cpp $(DEPS)
	$(CXX) $(FLAGS) benchmark.cpp -o benchmark

rcp_tests: rcp_tests.cpp $(DEPS)
	$(CXX) $(FLAGS) rcp_tests.cpp -o rcp_tests

clean:
	$(RM) $(ALL)
