.PHONY: clean

FLAGS=$(CXXFLAGS) -std=c++11 -Wextra -Wall

ALL=test-sse2\
    test-ssse3\
    test-avx2\
    test-avx512f\
    test-avx512bw\
    test-avx512vbmi

all: $(ALL)

test-sse2: *.cpp *.h
	$(CXX) $(FLAGS) test.cpp -DHAVE_SSE2 -o $@

test-ssse3: *.cpp *.h
	$(CXX) $(FLAGS) -mssse3 test.cpp -DHAVE_SSSE3 -o $@

test-avx2: *.cpp *.h
	$(CXX) $(FLAGS) -mavx2 test.cpp -DHAVE_AVX2 -o $@

test-avx512f: *.cpp *.h
	$(CXX) $(FLAGS) -mavx512f test.cpp -DHAVE_AVX512F -o $@

test-avx512bw: *.cpp *.h
	$(CXX) $(FLAGS) -mavx512bw test.cpp -DHAVE_AVX512BW -o $@

test-avx512vbmi: *.cpp *.h
	$(CXX) $(FLAGS) -mavx512vbmi test.cpp -DHAVE_AVX512VBMI -o $@

clean:
	$(RM) $(ALL)
