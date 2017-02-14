GCC=gcc -I. -std=c99 -pedantic -Wall -O3 -march=i686 -msse2
RM=rm

COMMON=trie.h trie.c test.c
PROG=bin/linear bin/linear-unrolled bin/linear-mtf bin/binary bin/sse bin/linear-mtf-incr

.SUFFIXES:
	# disable default rules

all: $(PROG)

histogram: histogram.c trie.h trie.c c/trie-linear.c
	$(GCC) histogram.c trie.c c/trie-linear.c -o histogram

bin/linear: $(COMMON) c/trie-linear.c
	$(GCC) c/trie-linear.c trie.c test.c -o bin/linear

bin/linear-unrolled: $(COMMON) c/trie-linear-unrolled.c
	$(GCC) c/trie-linear-unrolled.c trie.c test.c -o bin/linear-unrolled

bin/linear-mtf: $(COMMON) c/trie-linear-mtf.c
	$(GCC) c/trie-linear-mtf.c trie.c test.c -o bin/linear-mtf

bin/linear-mtf-incr: $(COMMON) c/trie-linear-mtf-incr.c
	$(GCC) c/trie-linear-mtf-incr.c trie.c test.c -o bin/linear-mtf-incr

bin/binary: $(COMMON) c/trie-binary.c
	$(GCC) c/trie-binary.c trie.c test.c -o bin/binary

bin/sse: $(COMMON) 32/trie-sse.c
	$(GCC) 32/trie-sse.c trie.c test.c -o bin/sse

test: $(PROG)
	sh testall.sh

clean:
	$(RM) -f *.o c/*.o 32/*.o histogram
	$(RM) -f $(PROG)
