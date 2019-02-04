.PHONY: clean

CXXFLAGS+=-std=c++17 -c -S -Wall -Wextra -O3

%.s: %.cpp
	$(CXX) $(CXXFLAGS) $<

CPP=$(wildcard *.cpp)
ASM=$(CPP:cpp=s)

all: summary.rst

summary.rst: scripts/*.py results/*.txt
	python scripts/summary.py > /dev/shm/tmp.rst
	mv /dev/shm/tmp.rst $@

asm: $(ASM)

clean:
	$(RM) *.s
