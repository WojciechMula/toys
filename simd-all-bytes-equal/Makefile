.PHONY: all
.PHONY: clean

FLAGS=-Wall -Wextra -pedantic -O3

all: sse.s avx2.s avx512f.s avx512bw.s

sse.s: sse.cpp
	$(CXX) $(FLAGS) -msse4.1 sse.cpp -S

avx2.s: avx2.cpp
	$(CXX) $(FLAGS) -mavx2 avx2.cpp -S

avx512f.s: avx512f.cpp
	$(CXX) $(FLAGS) -mavx512f avx512f.cpp -S

avx512bw.s: avx512bw.cpp
	$(CXX) $(FLAGS) -mavx512bw avx512bw.cpp -S

clean:
	rm *.s
