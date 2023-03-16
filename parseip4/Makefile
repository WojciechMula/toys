.SUFFIXES:

FLAGS=$(CXXFLAGS) -Wall -Wextra -pedantic -std=c++11 -Wno-implicit-fallthrough -Wno-overflow -march=native

ALL=unittest benchmark

all: $(ALL)

DEPS=common.h naive.cpp naive.h sse.h sse.cpp \
        glibc_ref.h glibc_ref.cpp \
        go_ref.h go_ref.cpp \
        sse_parse_aux_v2.inl \
        sse_parse_aux_v3.inl \
        sse_parse_aux_v4.inl \
        sse_parse_aux_v5.inl sse_v5.cpp.inl \
        sse_parse_aux_v6.inl sse_v6.cpp.inl \
        sse_parse_aux_v7.inl sse_v7.cpp.inl

sse_parse_aux_v2.inl: generator_v2.py
	python3 generator_v2.py > sse_parse_aux_v2.inl

sse_parse_aux_v3.inl: generator_v3.py
	python3 generator_v3.py > sse_parse_aux_v3.inl

sse_parse_aux_v4.inl: generator_v4.py
	python3 generator_v4.py > sse_parse_aux_v4.inl

sse_parse_aux_v5.inl: generator_v5.py
	python3 generator_v5.py > sse_parse_aux_v5.inl

sse_parse_aux_v6.inl: generator_v6.py
	python3 generator_v6.py > sse_parse_aux_v6.inl

sse_parse_aux_v7.inl: generator_v7/*.go
	cd generator_v7; go build
	./generator_v7/main $@

unittest: unittest.cpp $(DEPS)
	$(CXX) $(FLAGS) $< -o $@

benchmark: benchmark.cpp $(DEPS)
	$(CXX) $(FLAGS) -O2 $< -o $@
