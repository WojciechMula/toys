.SUFFIXES:

FLAGS=-Wall -O3 -pedantic -std=c++11

test: test.cpp gettime.cpp fnv32.cpp tolower.cpp
	g++ $(FLAGS) test.cpp -o test

clean:
	rm -f test
