.PHONY: all
.PHONY: clean

FLAGS=$(CXXFLAGS) -std=c++11 -Wall -Wextra -pedantic -O3 -march=native

OBJ=scalar.o\
    sse.o\
    sse_sadbw.o
 
ALL=unittest $(OBJ)

unittest: unittest.cpp $(OBJ) 
	$(CXX) $(FLAGS) $^ -o $@

benchmark: benchmark.cpp $(OBJ) 
	$(CXX) $(FLAGS) $^ -o $@


scalar.o: scalar.cpp scalar.h
	$(CXX) $(FLAGS) -c $< -o $@

sse.o: sse.cpp sse.h
	$(CXX) $(FLAGS) -c $< -o $@

sse_sadbw.o: sse_sadbw.cpp sse_sadbw.h
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(ALL)
