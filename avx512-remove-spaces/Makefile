FLAGS=$(CXXFLAGS) -mavx512vbmi -Wall -Wextra -pedantic -std=c++11

DEPS=all.cpp scalar.cpp avx512vbmi.cpp

ALL=unittest benchmark

unittest: unittest.cpp $(DEPS)
	$(CXX) $(FLAGS) $< -o $@

benchmark: benchmark.cpp $(DEPS)
	$(CXX) $(FLAGS) -O3 $< -o $@

clean:
	$(RM) $(ALL)
