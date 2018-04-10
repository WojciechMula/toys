.PHONY: all, clean

FLAGS=-O3 -std=c++11 -Wall -Wextra -pedantic -march=native
ALL=unittest benchmark
DEPS=scalar.cpp sse.cpp sse.2.cpp

all: $(ALL)

unittest: unittest.cpp $(DEPS)
	$(CXX) $(FLAGS) $< -o $@

benchmark: benchmark.cpp $(DEPS) time_utils.h
	$(CXX) $(FLAGS) $< -o $@

clean:
	$(RM) $(ALL)

