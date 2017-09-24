.PHONY: clean

FLAGS=-Wall -Wextra -O3 -msse4

speed: speed.cpp *.c
	$(CXX) $(FLAGS) speed.cpp -o speed

clean:
	rm -f speed
