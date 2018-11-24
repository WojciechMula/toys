.PHONY: clean

FLAGS=$(CXXFLAGS) -std=c++11 -Wextra -Wall

ALL=test-sse2\
    test-sse41\
    test-avx2\
    test-avx512f

all: $(ALL)

test-sse2: *.cpp *.h
	$(CXX) $(FLAGS) test.cpp -DHAVE_SSE2 -o $@

test-sse41: *.cpp *.h
	$(CXX) $(FLAGS) test.cpp -DHAVE_SSE41 -o $@

test-avx2: *.cpp *.h
	$(CXX) $(FLAGS) -mavx2 test.cpp -DHAVE_AVX2 -o $@

test-avx512f: *.cpp *.h
	$(CXX) $(FLAGS) -mavx512f test.cpp -DHAVE_AVX512F -o $@

clean:
	$(RM) $(ALL)
