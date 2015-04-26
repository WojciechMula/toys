.SUFFIXES:

CC=g++
FLAGS=-Wall -Wextra -std=c++11
FLAGS=-std=c++11

ALL=demo

demo: demo.cpp float2string.h
	$(CC) $(FLAGS) $^ -o $@

clean:
	rm -f $(ALL)
