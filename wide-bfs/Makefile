FLAGS=-Wall -Wextra -pedantic -std=c++11 -O3 -mavx512f
DEPS=scalar.cpp avx512f.cpp x86.cpp
ALL=validate benchmark

all: $(ALL)

validate: validate.cpp $(DEPS)
	$(CXX) $(FLAGS) validate.cpp -o $@

benchmark: benchmark.* $(DEPS)
	$(CXX) $(FLAGS) benchmark.cpp -o $@

clean:
	rm -f $(ALL)
