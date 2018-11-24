FLAGS=$(CXXFLAGS) -Wall -Wextra -std=c++11 -O3

OBJ=join_naive.o join_precalc.o

test: test.cpp $(OBJ)
	$(CXX) $(FLAGS) $< $(OBJ) -o $@

join_naive.o: join_naive.cpp join_naive.h
	$(CXX) $(FLAGS) $< -c -o $@

join_precalc.o: join_precalc.cpp join_precalc.h
	$(CXX) $(FLAGS) $< -c -o $@
