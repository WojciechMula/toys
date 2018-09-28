.PHONY: clean

FLAGS=$(CXXFLAGS) -O3 -march=native -std=c++11 -Wall -Wextra -pedantic

PROCEDURES=all.cpp\
           scalar.cpp\
           sse.cpp\
           sse_unrolled.cpp

benchmark: benchmark.cpp $(PROCEDURES)
	$(CXX) $(FLAGS) $< -o $@

unittest: unittest.cpp $(PROCEDURES)
	$(CXX) $(FLAGS) $< -o $@

clean:
	$(RM) benchmark unittest
