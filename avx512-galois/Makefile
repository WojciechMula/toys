CXXFLAGS=-Wall -Wextra -O2 -std=c++17 -march=icelake-server -Wpsabi

test: test_bit_shuffle test_transpose
	sde -- ./test_bit_shuffle
	sde -- ./test_transpose

test_bit_shuffle: test_bit_shuffle.cpp bit_shuffle.h interleave.cpp reverse.cpp
	$(CXX) $(CXXFLAGS) test_bit_shuffle.cpp -o test_bit_shuffle

test_transpose: test_transpose.cpp transpose.cpp
	$(CXX) $(CXXFLAGS) test_transpose.cpp -o test_transpose
