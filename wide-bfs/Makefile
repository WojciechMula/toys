FLAGS=-Wall -Wextra -pedantic -std=c++11 -O3 -mavx512f
ALL=validate benchmark

all: $(ALL)

validate: validate.cpp scalar.cpp avx512f.cpp
	$(CXX) $(FLAGS) validate.cpp -o $@

benchmark: benchmark.* scalar.cpp avx512f.cpp
	$(CXX) $(FLAGS) benchmark.cpp -o $@

clean:
	rm -f $(ALL)
