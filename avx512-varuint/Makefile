FLAGS=-Wall -Wextra -pedantic -std=c++17 -O3
#FLAGS+=-march=native
FLAGS+=-march=icelake-server

ALL=sse_varuint_validate avx512vbmi2_varuint_validate benchmark

all: $(ALL)

benchmark: benchmark.cpp byte_buffer.o avx512vbmi2_varuint.o sse_varuint.o
	$(CXX) $(FLAGS) byte_buffer.o avx512vbmi2_varuint.o sse_varuint.o benchmark.cpp -o $@

avx512vbmi2_varuint_validate: avx512vbmi2_varuint_validate.cpp avx512vbmi2_varuint.o byte_buffer.o
	$(CXX) $(FLAGS) avx512vbmi2_varuint.o byte_buffer.o avx512vbmi2_varuint_validate.cpp -o $@

avx512vbmi2_varuint.o: avx512vbmi2_varuint.cpp avx512vbmi2_varuint.h byte_buffer.o
	$(CXX) $(FLAGS) -c avx512vbmi2_varuint.cpp -o $@

sse_varuint_validate: sse_varuint_validate.cpp sse_varuint.o
	$(CXX) $(FLAGS) sse_varuint.o sse_varuint_validate.cpp -o $@

sse_varuint.o: sse_varuint.cpp sse_varuint.h sse_varuint.incl.cpp
	$(CXX) $(FLAGS) -c sse_varuint.cpp -o $@

sse_varuint.incl.cpp: sse_varuint.py
	python3 sse_varuint.py

byte_buffer.o: byte_buffer.cpp byte_buffer.h
	$(CXX) $(FLAGS) -c byte_buffer.cpp -o $@

clean:
	$(RM) $(ALL) sse_varuint.o avx512vbmi2_varuint.o byte_buffer.o
