.PHONY: clean

FLAGS=-std=c++11 -O3 -mavx512f -Wall -Wextra -pedantic

avx512f-alignr: avx512f-alignr.cpp
	$(CXX) $(FLAGS) avx512f-alignr.cpp -o $@

run: avx512f-alignr
	sde -cnl -- ./$^

clean:
	rm -f avx512f-alignr
