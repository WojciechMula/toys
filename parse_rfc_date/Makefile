.PHONY: clean

FLAGS=$(CXXFLAGS) -Wall -Wextra -pedantic -std=c++11 -march=native -O3

demo: sse.cpp
	$(CXX) $(FLAGS) $< -o $@

clean:
	$(RM) demo
