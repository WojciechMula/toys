.PHONY: clean
.PHONY: report

FLAGS=$(CXXFLAGS) -Wall -Wextra -pedantic -std=c++11 -ggdb3 -O3 -ffast-math

DEPS=algorithm.h \
     all.h\

OBJ=scalar.o\
     sse.o\
     sse_dist_vector_many.o

ALL=benchmark

benchmark: benchmark.cpp $(OBJ) $(DEPS)
	$(CXX) $(FLAGS) $< $(OBJ) -o $@

scalar.o: scalar.cpp scalar.h 
	$(CXX) $(FLAGS) $< -c -o $@

sse.o: sse.cpp sse.h 
	$(CXX) $(FLAGS) $< -c -o $@

sse_dist_vector_many.o: sse_dist_vector_many.cpp sse_dist_vector_many.h 
	$(CXX) $(FLAGS) $< -c -o $@

benchmark.txt: benchmark
	./benchmark > $@

report: benchmark.txt script/*.py
	python script/format.py $^ > report.txt

clean:
	$(RM) $(ALL) $(OBJ)
