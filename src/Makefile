GCC=gcc -I. -std=c99 -pedantic -O2
RM=rm

COMMON=trie.h trie.c test.c
PROG=bin/linear bin/linear-unrolled bin/binary bin/sse

.SUFFIXES:
	# disable default rules

all: $(PROG)

bin/linear: $(COMMON) c/trie-linear.c
	$(GCC) c/trie-linear.c trie.c test.c -o bin/linear

bin/linear-unrolled: $(COMMON) c/trie-linear-unrolled.c
	$(GCC) c/trie-linear-unrolled.c trie.c test.c -o bin/linear-unrolled

bin/binary: $(COMMON) c/trie-binary.c
	$(GCC) c/trie-binary.c trie.c test.c -o bin/binary

bin/sse: $(COMMON) 32/trie-sse.c
	$(GCC) 32/trie-sse.c trie.c test.c -o bin/sse

test: $(PROG)
	sh testall.sh

clean:
	$(RM) -f *.o c/*.o 32/*.o
	$(RM) -f $(PROG)
