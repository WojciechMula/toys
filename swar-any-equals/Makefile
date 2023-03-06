.phony: all clean

FLAGS=-Wall -Wextra -std=c++11 -O3 -march=native

DEPS=reference.o \
     better.o

ALL=unittest \
    benchmark

all: $(ALL)

clean:
	$(RM) $(ALL) $(DEPS)

benchmark: benchmark.cpp $(DEPS)
	$(CXX) $(FLAGS) benchmark.cpp $(DEPS) -o $@

unittest: unittest.cpp $(DEPS)
	$(CXX) $(FLAGS) unittest.cpp $(DEPS) -o $@

reference.o: reference.cpp reference.h
	$(CXX) $(FLAGS) reference.cpp -c -o $@

better.o: better.cpp better.h
	$(CXX) $(FLAGS) better.cpp -c -o $@
