FLAGS=-Wall -Wextra -pedantic -O3 -std=c++17 -ggdb -march=native # -Werror

ALL=verify benchmark

DEPS=scalar.cpp \
     simdutf.cpp \
     simdutf_ver2.cpp

TMP=/dev/shm

.PHONY: all
all: $(ALL)

.PHONY: clean
clean:
	$(RM) $(ALL)

verify: $(DEPS) verify.cpp
	$(CXX) $(FLAGS) verify.cpp -o $@

benchmark: $(DEPS) benchmark.cpp
	$(CXX) $(FLAGS) benchmark.cpp -o $@
