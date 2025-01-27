FLAGS=-Wall -Wextra -pedantic -O3 -march=native -std=c++20 -ggdb # -Werror

ALL=verify \
    benchmark

DEPS=impl.cpp scalar.cpp avx2.cpp plain.cpp.inl compressed.cpp.inl compressed_v2.cpp.inl compressed_avx2.cpp.inl cpp_lookup.cpp.inl

.PHONY: all
all: $(ALL)

.PHONY: clean
clean:
	$(RM) $(ALL)

verify: $(DEPS) verify.cpp
	$(CXX) $(FLAGS) verify.cpp -o $@

benchmark: $(DEPS) benchmark.cpp
	$(CXX) $(FLAGS) benchmark.cpp -o $@

plain.cpp.inl: scripts/plain_lookup.py
	python3 scripts/plain_lookup.py > /dev/shm/$@
	mv /dev/shm/$@ $@

compressed.cpp.inl: scripts/compressed_lookup.py
	python3 scripts/compressed_lookup.py > /dev/shm/$@
	mv /dev/shm/$@ $@

compressed_v2.cpp.inl: scripts/compressed_lookup_v2.py
	python3 scripts/compressed_lookup_v2.py > /dev/shm/$@
	mv /dev/shm/$@ $@

compressed_avx2.cpp.inl: scripts/compressed_lookup_avx2.py
	python3 scripts/compressed_lookup_avx2.py > /dev/shm/$@
	mv /dev/shm/$@ $@

cpp_lookup.cpp.inl: scripts/cpp_lookup.py
	python3 scripts/cpp_lookup.py > /dev/shm/$@
	mv /dev/shm/$@ $@
