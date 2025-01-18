FLAGS=-Wall -Wextra -pedantic -std=c++17 -O3 -ggdb -march=native

benchmark: test.cpp
	$(CXX) $(FLAGS) test.cpp -o $@

.PHONY: clean
clean:
	$(RM) benchmark
