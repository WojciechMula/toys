
FLAGS=$(CXXFLAGS) -Wall -Wextra -pedantic -std=c++11 -ggdb3 -O3

DEPS=algorithm.h \
     all.h\

OBJ=scalar.o\
     sse.o\
     sse_mult_vector_many.o

ALL=benchmark

benchmark: benchmark.cpp $(OBJ) $(DEPS)
	$(CXX) $(FLAGS) $< $(OBJ) -o $@

scalar.o: scalar.cpp scalar.h 
	$(CXX) $(FLAGS) $< -c -o $@

sse.o: sse.cpp sse.h 
	$(CXX) $(FLAGS) $< -c -o $@

sse_mult_vector_many.o: sse_mult_vector_many.cpp sse_mult_vector_many.h 
	$(CXX) $(FLAGS) $< -c -o $@

clean:
	$(RM) $(ALL) $(OBJ)
