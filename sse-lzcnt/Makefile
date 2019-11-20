CFLAGS=-Wall -Wextra -O2 -march=native

run: test
	./test

test: sse-lzcnt.cpp
	$(CXX) $(CFLAGS) $^ -o $@
