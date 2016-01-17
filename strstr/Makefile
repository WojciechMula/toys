CC=g++
FLAGS=-Wall -pedantic -std=c++11 -O3
DEPS=strstr-*.cpp
ALL=test32 test64 verify

all: $(ALL)

i386.txt:
	wget http://css.csail.mit.edu/6.858/2013/readings/i386.txt

words: i386.txt
	sh make_words.sh $^ $@
	
test32: test.cpp strstr32.cpp $(DEPS)
	$(CC) $(FLAGS) test.cpp -o $@

demo32: test32 i386.txt words
	./test32 i386.txt `cat words` > demo32
	
test64: test.cpp strstr64.cpp $(DEPS)
	$(CC) $(FLAGS) -DTEST64 $< -o $@

demo64: test64 i386.txt words
	./test64 i386.txt `cat words` > demo64

analyze32: demo32
	python analyze.py < $<

analyze64: demo64
	python analyze.py < $<

verify: verify.cpp $(DEPS) strstr64.cpp
	$(CC) $(FLAGS) verify.cpp -o $@

verification: verify i386.txt words
	@./verify i386.txt words && echo OK

clean:
	rm -f $(ALL)
