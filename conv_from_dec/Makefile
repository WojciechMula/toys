.SUFFIXES:

CC=g++
FLAGS=-std=c++11 -Wall -Wextra -pedantic
DEPS=parse.*.cpp common.cpp

all: verify

verify: verify.cpp $(DEPS)
	$(CC) $(FLAGS) verify.cpp -o $@

clean:
	rm -f verify
