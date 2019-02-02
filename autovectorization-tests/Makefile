.PHONY: clean

CXXFLAGS+=-std=c++17 -c -S -Wall -Wextra -O3

%.s: %.cpp
	$(CXX) $(CXXFLAGS) $<

CPP=$(wildcard *.cpp)
ASM=$(CPP:cpp=s)

all: $(ASM)

clean:
	$(RM) *.s
