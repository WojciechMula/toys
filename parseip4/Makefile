.SUFFIXES:

FLAGS=$(CXXFLAGS) -Wall -Wextra -pedantic -std=c++11 -Wno-implicit-fallthrough -Wno-overflow

ALL=unittest benchmark

all: $(ALL)

DEPS=common.h naive.cpp naive.h sse.h sse.cpp sse_parse_aux.inl sse_parse_aux_v3.inl

sse_parse_aux.inl: generator.py
	python3 generator.py > sse_parse_aux.inl

sse_parse_aux_v3.inl: generator_v3.py
	python3 generator_v3.py > sse_parse_aux_v3.inl

unittest: unittest.cpp $(DEPS)
	$(CXX) $(FLAGS) $< -o $@

benchmark: benchmark.cpp $(DEPS)
	$(CXX) $(FLAGS) -O2 -march=native $< -o $@
