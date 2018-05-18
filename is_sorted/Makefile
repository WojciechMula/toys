.PHONY: all, clean

FLAGS_COMMON=-O3 -std=c++11 -Wall -Wextra -pedantic
FLAGS=$(FLAGS_COMMON) -march=native
FLAGS_AVX2=$(FLAGS_COMMON) -mavx2 -DHAVE_AVX2
FLAGS_AVX512=$(FLAGS_COMMON) -mavx512f -DHAVE_AVX512 -DHAVE_AVX2

DEPS=scalar.cpp sse.cpp sse.simd-generic.cpp
DEPS_AVX2=$(DEPS) avx2.cpp avx2.simd-generic.cpp
DEPS_AVX512=$(DEPS_AVX2) avx512.cpp avx512.simd-generic.cpp

ALL=unittest benchmark unittest_avx2 benchmark_avx2 unittest_avx512 benchmark_avx512

all: $(ALL)

unittest: unittest.cpp $(DEPS)
	$(CXX) $(FLAGS) $< -o $@

benchmark: benchmark.cpp $(DEPS) time_utils.h
	$(CXX) $(FLAGS) $< -o $@

unittest_avx2: unittest.cpp $(DEPS_AVX2)
	$(CXX) $(FLAGS_AVX2) $< -o $@

benchmark_avx2: benchmark.cpp $(DEPS_AVX2) time_utils.h
	$(CXX) $(FLAGS_AVX2) $< -o $@

unittest_avx512: unittest.cpp $(DEPS_AVX512)
	$(CXX) $(FLAGS_AVX512) $< -o $@

benchmark_avx512: benchmark.cpp $(DEPS_AVX512) time_utils.h
	$(CXX) $(FLAGS_AVX512) $< -o $@

measurements.txt: benchmark scripts/performance_test.py
	python scripts/performance_test.py ./$< > /tmp/$@
	mv /tmp/$@ $@

measurements_avx2.txt: benchmark_avx2 scripts/performance_test.py
	python scripts/performance_test.py ./$< > /tmp/$@
	mv /tmp/$@ $@

measurements_avx512.txt: benchmark_avx512 scripts/performance_test.py
	python scripts/performance_test.py ./$< > /tmp/$@
	mv /tmp/$@ $@

measurements.rst: measurements.txt scripts/performance_report.py
	python scripts/performance_report.py ./$< > /tmp/$@
	mv /tmp/$@ $@

measurements_avx2.rst: measurements_avx2.txt scripts/performance_report.py
	python scripts/performance_report.py ./$< > /tmp/$@
	mv /tmp/$@ $@

measurements_avx512.rst: measurements_avx512.txt scripts/performance_report.py
	python scripts/performance_report.py ./$< > /tmp/$@
	mv /tmp/$@ $@

clean:
	$(RM) $(ALL)

