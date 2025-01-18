FLAGS=$(CXXFLAGS) -Wall -Wextra -pedantic -std=c++17 -O3 -Werror -march=native

DEPS=is_heap_scalar.h   \
     is_heap_sse.cpp    \
     is_heap_avx2.cpp

ALL=validate benchmark

.PHONY: all
all: $(ALL)

test: validate
	./validate 256 512 1024 4096 8192 16384 32768

bench: benchmark
	./benchmark 256 512 1024 4096 8192 16384 32768 65536

validate: validate.cpp $(DEPS)
	$(CXX) $(FLAGS) validate.cpp -o $@

benchmark: benchmark.cpp $(DEPS)
	$(CXX) $(FLAGS) benchmark.cpp -o $@

.PHONY: clean
clean:
	$(RM) $(ALL)
