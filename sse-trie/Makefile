FLAGS=-I. -std=c99 -pedantic -Wall -O3 -m32
RM=rm

COMMON=trie.h trie.c test.c
PROG=bin/linear bin/linear-unrolled bin/linear-mtf bin/binary bin/sse bin/linear-mtf-incr

.SUFFIXES:
	# disable default rules

all: $(PROG)

histogram: histogram.c trie.h trie.c c/trie-linear.c
	$(CC) $(FLAGS) histogram.c trie.c c/trie-linear.c -o histogram

bin/linear: $(COMMON) c/trie-linear.c
	$(CC) $(FLAGS) c/trie-linear.c trie.c test.c -o bin/linear

bin/linear-unrolled: $(COMMON) c/trie-linear-unrolled.c
	$(CC) $(FLAGS) c/trie-linear-unrolled.c trie.c test.c -o bin/linear-unrolled

bin/linear-mtf: $(COMMON) c/trie-linear-mtf.c
	$(CC) $(FLAGS) c/trie-linear-mtf.c trie.c test.c -o bin/linear-mtf

bin/linear-mtf-incr: $(COMMON) c/trie-linear-mtf-incr.c
	$(CC) $(FLAGS) c/trie-linear-mtf-incr.c trie.c test.c -o bin/linear-mtf-incr

bin/binary: $(COMMON) c/trie-binary.c
	$(CC) $(FLAGS) c/trie-binary.c trie.c test.c -o bin/binary

bin/sse: $(COMMON) 32/trie-sse.c
	$(CC) $(FLAGS) 32/trie-sse.c trie.c test.c -o bin/sse

test: $(PROG) dictionary.txt input-words.txt
	sh testall.sh

dictionary.txt: /usr/share/dict/words
	ln -s $^ $@

input-words.txt: dictionary.txt
	cat $^ | shuf | head -n 1000 > $@

clean:
	$(RM) -f *.o c/*.o 32/*.o histogram
	$(RM) -f $(PROG)
