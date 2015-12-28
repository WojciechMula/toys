.SUFFIXES:

CC=g++
FLAGS=-Wall -Wextra -std=c++11
FLAGS=-std=c++11

ALL=demo speed

run: demo
	./demo selected

speedup: speed
	./speed

demo: demo.cpp float2string.h
	$(CC) $(FLAGS) $^ -o $@

speed: speed.cpp float2string.h gettime.cpp
	$(CC) $(FLAGS) speed.cpp -o $@

clean:
	rm -f $(ALL)
