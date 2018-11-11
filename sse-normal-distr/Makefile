.PHONY: clean

FLAGS=$(CXXFLAGS) -std=c++14 -Wall -Wextra -pedantic

ALL=benchmark

all: $(ALL)

benchmark: benchmark.cpp *.h f1.cpp f2.cpp
	$(CXX) $(FLAGS) $< -o $@

f1.cpp: scripts/approx.py
	python $< f1 $@

f2.cpp: scripts/approx.py
	python $< f2 $@

clean:
	$(RM) $(ALL)

