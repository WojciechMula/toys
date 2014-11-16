.SUFFIXES:

CC=g++
FLAGS=-std=c++11 -Wall -Wextra -pedantic -Werror -msse2 -O2

demo: demo.cpp simple_list.hpp simd_list.hpp measure.hpp arglist.hpp
	$(CC) $(FLAGS) $< -o $@

clean:
	rm -f demo

