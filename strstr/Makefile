CC=g++
FLAGS=-Wall -pedantic -std=c++11 -O2

demo: demo.cpp strstr32.cpp strstr-libc.cpp
	$(CC) $(FLAGS) $@.cpp -o $@

clean:
	rm -f demo
