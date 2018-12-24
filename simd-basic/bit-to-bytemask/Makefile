.PHONY: clean

FLAGS=$(CXXFLAGS) -std=c++11 -Wextra -Wall

ALL=test-sse2\
    test-avx512f\
    test-avx512bw

all: $(ALL)

test-sse2: *.sse2.cpp *.h
	$(CXX) $(FLAGS) test.cpp -DHAVE_SSE2 -o $@

test-avx512f: *.avx512f.cpp *.h
	$(CXX) $(FLAGS) -mavx512f test.cpp -DHAVE_AVX512F -o $@

test-avx512bw: *.avx512bw.cpp *.h
	$(CXX) $(FLAGS) -mavx512bw test.cpp -DHAVE_AVX512BW -o $@

clean:
	$(RM) $(ALL)
