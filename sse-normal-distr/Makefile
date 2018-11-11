.PHONY: clean

FLAGS=$(CXXFLAGS) -std=c++14 -Wall -Wextra -pedantic

ALL=benchmark

all: $(ALL)

benchmark: benchmark.cpp *.h f1.cpp
	$(CXX) $(FLAGS) $< -o $@

f1.cpp: scripts/approx.py
	python $< f1 $@

clean:
	$(RM) $(ALL)

