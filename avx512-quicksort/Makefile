.SUFFIXES:
.PHONY: all clean

FLAGS=-std=c++11 -mbmi2 -Wall -pedantic -Wextra
FLAGS_AVX512=$(FLAGS) -mavx512f -DHAVE_AVX512F_INSTRUCTIONS -DHAVE_AVX2_INSTRUCTIONS
FLAGS_AVX2=$(FLAGS) -mavx2 -DHAVE_AVX2_INSTRUCTIONS

DEPS_SORT=partition.cpp \
          avx2-partition.cpp \
          avx512-partition.cpp \
          avx512-bmi2-partition.cpp \
          avx512-popcnt-partition.cpp \
          quicksort.cpp

ALL=test speed test_avx2 speed_avx2

all: $(ALL)

test: test.cpp input_data.cpp $(DEPS_SORT)
	$(CXX) $(FLAGS_AVX512) -fsanitize=address test.cpp -o $@

test_avx2: test.cpp input_data.cpp $(DEPS_SORT)
	$(CXX) $(FLAGS_AVX2) -fsanitize=address test.cpp -o $@

speed: speed.cpp input_data.cpp gettime.cpp $(DEPS_SORT)
	$(CXX) $(FLAGS_AVX512) -O3 -DNDEBUG speed.cpp -o $@

speed_avx2: speed.cpp input_data.cpp gettime.cpp $(DEPS_SORT)
	$(CXX) $(FLAGS_AVX2) -O3 -DNDEBUG speed.cpp -o $@

run: test
	sde -cnl -- ./$^

run_avx2: test_avx2
	sde -cnl -- ./$^

clean:
	rm -f $(ALL)
