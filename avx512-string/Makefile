.PHONY: all clean

all: test

run: test
	sde -cnl -- ./$^

test: *.cpp
	$(CXX) -std=c++14 -mavx512f -O3 test.cpp -o $@

clean:
	rm -f test
