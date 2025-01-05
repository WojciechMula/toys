FLAGS=-Wall -Wextra -pedantic -std=c++17 -O3 -ggdb
FLAGS+=-march=icelake-server

ALL=verify avx512.o

.PHONY: all
all: $(ALL)

.PHONY: clear
clear:
	$(RM) $(ALL)

verify: verify.cpp avx512.cpp
	$(CXX) $(FLAGS) verify.cpp -o $@

avx512.o: avx512.cpp
	$(CXX) $(FLAGS) avx512.cpp -c -o $@
