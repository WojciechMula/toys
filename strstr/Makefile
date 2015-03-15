CC=g++
FLAGS=-Wall -pedantic -std=c++11 -O2
DEPS=strstr-*.cpp

all: test32 test64

i386.txt:
	wget http://css.csail.mit.edu/6.858/2013/readings/i386.txt

words: i386.txt
	sh make_words.sh $^ $@
	
test32: test.cpp strstr32.cpp $(DEPS)
	$(CC) $(FLAGS) test.cpp -o $@

demo32: test32 i386.txt words
	./test32 i386.txt `cat words` > demo32
	
test64: test.cpp strstr32.cpp $(DEPS)
	$(CC) $(FLAGS) -DTEST64 test.cpp -o $@

demo64: test64 i386.txt words
	./test64 i386.txt `cat words` > demo64

analyze32: demo32
	python analyze.py < demo32

analyze64: demo64
	python analyze.py < demo64

clean:
	rm -f test32
	rm -f test64
