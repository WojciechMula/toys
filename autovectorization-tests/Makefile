.PHONY: clean

CXXFLAGS+=-std=c++17 -c -S -Wall -Wextra -O3

%.s: %.cpp
	$(CXX) $(CXXFLAGS) $<

CPP=$(wildcard *.cpp)
ASM=$(CPP:cpp=s)

all: summary.rst comparison2021.rst comparison2021-msvc.rst

summary.rst: scripts/*.py results/*.txt
	python3 scripts/summary.py > /dev/shm/tmp.rst
	mv /dev/shm/tmp.rst $@

comparison2021.rst: scripts/*.py results/*.txt
	python3 scripts/comparison2021.py > /dev/shm/tmp.rst
	mv /dev/shm/tmp.rst $@

comparison2021-msvc.rst: scripts/*.py results/*.txt
	python3 scripts/comparison2021-msvc.py > /dev/shm/tmp.rst
	mv /dev/shm/tmp.rst $@

asm: $(ASM)

clean:
	$(RM) *.s
