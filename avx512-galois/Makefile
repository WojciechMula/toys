CXXFLAGS=-Wall -Wextra -O2 -std=c++17 -march=icelake-server -Wpsabi

test: test_transpose
	sde -- ./test_transpose

test_transpose: test_transpose.cpp transpose.cpp
	$(CXX) $(CXXFLAGS) test_transpose.cpp -o test_transpose
