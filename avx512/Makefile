.PHONY: clean

FLAGS=-std=c++11 -O3 -Wall -Wextra -pedantic
ALL=avx512f-alignr \
    avx512cd-conflict-demo \
    avx512vl-multishift \
    avx512-ktest \
    avx512bw-rotate-by1

all: $(ALL)

avx512bw-rotate-by1: avx512bw-rotate-by1.cpp
	$(CXX) $(FLAGS) -mavx512bw $^ -o $@

avx512f-alignr: avx512f-alignr.cpp
	$(CXX) $(FLAGS) -mavx512f $^ -o $@

avx512cd-conflict-demo: avx512cd-conflict-demo.cpp
	$(CXX) $(FLAGS) -mavx512cd $^ -o $@

avx512vl-multishift: avx512vl-multishift.cpp
	$(CXX) $(FLAGS) -mavx512f $^ -o $@

avx512-ktest: avx512-ktest.c
	$(CC) -mavx512f $^ -o $@

run: avx512f-alignr
	sde -cnl -- ./$^

clean:
	rm -f $(ALL)

