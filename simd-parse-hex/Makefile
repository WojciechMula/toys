FLAGS=-Wall -Wextra -pedantic -std=c++11 -O3 -march=native

OBJ=algorithm1.o algorithm2.o

validate: validate.cpp $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) validate.cpp -o $@

algorithm1.o: algorithm1.h algorithm1.cpp
	$(CXX) $(FLAGS) -c algorithm1.cpp -o $@

algorithm2.o: algorithm2.h algorithm2.cpp
	$(CXX) $(FLAGS) -c algorithm2.cpp -o $@

clean:
	$(RM) $(OBJ) validate
