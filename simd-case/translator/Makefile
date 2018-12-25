.PHONY: clean

TMP=/dev/shm/tmp
FLAGS=$(CXXFLAGS) -O3 -march=native #-Wall -Wextra -pedantic

EXE=test-compiled test-simd
ALL=*.o $(EXE)
    
all: $(EXE)

test: $(EXE)
	sh compare.sh

test-compiled: perf.cpp compiled.o
	g++ $(FLAGS) $< compiled.o -o $@

test-simd: perf.cpp simd.o
	g++ $(FLAGS) $< simd.o -o $@

simd.o: test.cpp
	g++ $(FLAGS) -DSIMD -c $< -o $@

compiled.o: test-pattern.cpp
	g++ $(FLAGS) -c $< -o $@

test.cpp: test-pattern.cpp translate.py
	python translate.py $< > $(TMP)
	mv $(TMP) $@

clean:
	$(RM) $(ALL)
