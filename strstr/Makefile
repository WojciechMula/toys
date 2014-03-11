CC=g++
FLAGS=-Wall -pedantic -std=c++11 -O2

all: test

i386.txt:
	wget http://css.csail.mit.edu/6.858/2013/readings/i386.txt

words: i386.txt
	sh make_words.sh $^ $@
	
test: test.cpp strstr*.cpp
	$(CC) $(FLAGS) $@.cpp -o $@

demo: test i386.txt words
	./test i386.txt `cat words` > demo

analyze: demo
	python analyze.py

clean:
	rm -f test
