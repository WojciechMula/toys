FLAGS=$(CXXFLAGS) -O3 -mavx2 -Wall -Wextra -std=c++11

benchmark: benchmark.cpp functions.cpp
	$(CXX) $(FLAGS) $< -o $@
