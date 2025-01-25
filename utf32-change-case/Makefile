FLAGS=-Wall -Wextra -pedantic -Werror -O3 -march=native -std=c++20 -ggdb

ALL=verify \
    benchmark

.PHONY: all
all: $(ALL)

.PHONY: clean
clean:
	$(RM) $(ALL)

verify: verify.cpp scalar.cpp plain.cpp.inl compressed.cpp.inl
	$(CXX) $(FLAGS) verify.cpp -o $@

benchmark: benchmark.cpp scalar.cpp plain.cpp.inl compressed.cpp.inl
	$(CXX) $(FLAGS) benchmark.cpp -o $@

plain.cpp.inl: scripts/plain_lookup.py
	python3 scripts/plain_lookup.py > /dev/shm/$@
	mv /dev/shm/$@ $@

compressed.cpp.inl: scripts/compressed_lookup.py
	python3 scripts/compressed_lookup.py > /dev/shm/$@
	mv /dev/shm/$@ $@
