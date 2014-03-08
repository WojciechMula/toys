CC=g++
FLAGS=-Wall -pedantic -std=c++11 -O2

all: demo test

demo: demo.cpp strstr*.cpp
	$(CC) $(FLAGS) $@.cpp -o $@

test: test.cpp strstr*.cpp
	$(CC) $(FLAGS) $@.cpp -o $@

clean:
	rm -f demo test
