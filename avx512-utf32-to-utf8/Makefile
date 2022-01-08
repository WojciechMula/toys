FLAGS=-Wall -Wextra -pedantic -Wfatal-errors -O3 -march=icelake-server -std=c++17

ALL=verify avx512bw-utf32-to-utf8.o avx512vbmi2-utf32-to-utf8.o

all: $(ALL)

verify: verify.cpp avx512bw-utf32-to-utf8.o avx512vbmi2-utf32-to-utf8.o
	$(CXX) $(FLAGS) avx512bw-utf32-to-utf8.o avx512vbmi2-utf32-to-utf8.o $@.cpp -o $@

avx512bw-utf32-to-utf8.o: avx512bw-utf32-to-utf8.cpp avx512bw-utf32-to-utf8.h
	$(CXX) $(FLAGS) avx512bw-utf32-to-utf8.cpp -c -o $@

avx512vbmi2-utf32-to-utf8.o: avx512vbmi2-utf32-to-utf8.cpp avx512vbmi2-utf32-to-utf8.h
	$(CXX) $(FLAGS) avx512vbmi2-utf32-to-utf8.cpp -c -o $@

clean:
	$(RM) $(ALL)
