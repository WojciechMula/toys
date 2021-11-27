FLAGS=-Wall -Wextra -pedantic -Wfatal-errors -O3 -march=native

ALL=unittest benchmark benchmark-force-scalar

all: $(ALL)

unittest: unittest.cpp scalar.h scalar.cpp swar.h swar.cpp
	$(CXX) $(FLAGS) scalar.cpp swar.cpp unittest.cpp -o $@

benchmark: benchmark.cpp scalar.h scalar.cpp swar.h swar.cpp
	$(CXX) $(FLAGS) scalar.cpp swar.cpp benchmark.cpp -o $@

benchmark-force-scalar: benchmark.cpp scalar.h scalar.cpp swar.h swar.cpp
	$(CXX) $(FLAGS) -fno-tree-vectorize scalar.cpp swar.cpp benchmark.cpp -o $@

clean:
	$(RM) $(ALL)
