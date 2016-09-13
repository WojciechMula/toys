.PHONY: all clean run

all: simd-bit-mask.cpp
	$(CXX) -std=c++11 -O3 -mavx2 $^ -o $@

run: all
	sde -cnl -- ./demo

clean:
	rm -f demo
