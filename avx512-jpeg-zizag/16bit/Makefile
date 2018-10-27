.PHONY: all clean

FLAGS_COMMON=$(CXXFLAGS) -O3 -Wall -Wextra -pedantic -std=c++11
FLAGS_SSE4=$(FLAGS_COMMON) -msse4.1

DEPS=common.cpp\
     scalar.cpp\
     sse.cpp sse.inl sse_generate.py\

ALL=unittest\

all: $(ALL)

unittest: unittest.cpp $(DEPS)
	$(CXX) $(FLAGS_SSE4) $< -o $@

benchmark: benchmark.cpp $(DEPS)
	$(CXX) $(FLAGS_SSE4) $< -o $@

sse.inl: sse_generate.py
	python $< $@

clean:
	$(RM) $(ALL)
