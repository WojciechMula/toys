.PHONY: clean

FLAGS=$(CXXFLAGS) -Wall -Wextra -pedantic -std=c++11 -march=native -O3

ALL=unittests

all: $(ALL)

unittests: unittests.cpp sse.cpp
	$(CXX) $(FLAGS) $< -o $@

clean:
	$(RM) $(ALL)
