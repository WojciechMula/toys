.SUFFIXES:

CC=g++
FLAGS=-Wall -Wextra -std=c++11
FLAGS=-std=c++11

ALL=demo speed

run: demo
	./demo selected

speedup: speed
	./speed

demo: demo.cpp float2string.h cmdline.cpp
	$(CC) $(FLAGS) demo.cpp -o $@

speed: speed.cpp float2string.h gettime.cpp cmdline.cpp
	$(CC) $(FLAGS) -O3 speed.cpp -o $@

clean:
	rm -f $(ALL)
