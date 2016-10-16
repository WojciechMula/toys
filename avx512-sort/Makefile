.PHONY: clean

FLAGS=-std=c++11 -mavx512f -O3 -Wall -Wextra -pedantic

ALL=speed verify verify_any
SDE=sde -cnl --

all: $(ALL)

run: run_verify run_speed

run_speed: speed
	$(SDE) ./$^

run_verify: verify
	$(SDE) ./$^

run_verify_any: verify_any
	$(SDE) ./$^

speed: speed.cpp gettime.cpp insertion-sort.cpp avx512-sort.cpp
	$(CXX) $(FLAGS) speed.cpp -o $@

verify: verify.cpp avx512-sort.cpp avx512-sort-4regs.cpp
	$(CXX) $(FLAGS) verify.cpp -o $@

verify_any: verify_any.cpp avx512-sort-any.cpp
	$(CXX) $(FLAGS) verify_any.cpp -o verify_any

clean:
	rm -f $(ALL)
