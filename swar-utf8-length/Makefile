FLAGS=-Wall -Wextra -pedantic -Wfatal-errors -O3 -march=native

ALL=unittest benchmark

all: $(ALL)

unittest: unittest.cpp scalar.h scalar.cpp swar.h swar.cpp
	$(CXX) $(FLAGS) scalar.cpp swar.cpp unittest.cpp -o $@

benchmark: benchmark.cpp scalar.h scalar.cpp swar.h swar.cpp
	$(CXX) $(FLAGS) scalar.cpp swar.cpp benchmark.cpp -o $@

clear:
	$(RM) $(ALL)
