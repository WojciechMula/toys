.SUFFIXES:

FLAGS=$(CXXFLAGS) -Wall -Wextra -pedantic -std=c++11 -Wno-implicit-fallthrough -Wno-overflow -march=native

ALL=unittest benchmark

all: $(ALL)

DEPS=common.h common.cpp \
        naive.cpp naive.h \
        swar.h swar.cpp \
        sse.h sse.cpp \
        glibc_ref.h glibc_ref.cpp \
        go_ref.h go_ref.cpp \
        sse_parse_aux_v2.inl sse_v2.cpp.inl \
        sse_parse_aux_v3.inl sse_v3.cpp.inl \
        sse_parse_aux_v4.inl sse_v4.cpp.inl \
        sse_parse_aux_v5.inl sse_v5.cpp.inl \
        sse_parse_aux_v6.inl sse_v6.cpp.inl \
        sse_parse_aux_v7.inl sse_v7.cpp.inl \
        sse_parse_aux_v8.inl sse_v8.cpp.inl

sse_parse_aux_v2.inl: generator_v2.py
	python3 generator_v2.py > sse_parse_aux_v2.inl

sse_parse_aux_v3.inl: generator_v3.py
	python3 generator_v3.py > sse_parse_aux_v3.inl

sse_parse_aux_v4.inl: generator_v4.py generator_sse.py
	python3 generator_v4.py > sse_parse_aux_v4.inl

sse_parse_aux_v5.inl: generator_v5.py
	python3 generator_v5.py > sse_parse_aux_v5.inl

sse_parse_aux_v6.inl: generator_v6.py
	python3 generator_v6.py > sse_parse_aux_v6.inl

sse_parse_aux_v7.inl: generator_v7/*.go
	cd generator_v7; go build
	./generator_v7/main $@

sse_parse_aux_v8.inl: generator_v8.py generator_sse.py
	python3 generator_v8.py > sse_parse_aux_v8.inl

unittest: unittest.cpp $(DEPS)
	$(CXX) $(FLAGS) $< -o $@

benchmark: benchmark.cpp $(DEPS)
	$(CXX) $(FLAGS) -O2 $< -o $@

clean:
	$(RM) $(ALL)
