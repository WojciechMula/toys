.SUFFIXES:
.PHONY: all clean

FLAGS=-std=c++11 -mavx512f -Wall -pedantic -Wextra
DEPS_SORT=partition.cpp avx512-partition.cpp quicksort.cpp
ALL=test speed

all: $(ALL)

test: test.cpp input_data.cpp $(DEPS_SORT)
	$(CXX) $(FLAGS) -fsanitize=address test.cpp -o $@

speed: speed.cpp input_data.cpp gettime.cpp $(DEPS_SORT)
	$(CXX) $(FLAGS) -O3 -DNDEBUG speed.cpp -o $@

clean:
	rm -f $(ALL)
