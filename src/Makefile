GCC=gcc -I. -std=c99 -pedantic -O2
RM=rm

COMMON=trie.h trie.c test.c
PROG=bin/linear bin/linear-trick bin/binary bin/sse

.SUFFIXES:
	# disable default rules

all: $(PROG)

bin/linear: $(COMMON) c/trie-linear.c
	$(GCC) c/trie-linear.c trie.c test.c -o bin/linear

bin/linear-trick: $(COMMON) c/trie-linear-trick.c
	$(GCC) c/trie-linear-trick.c trie.c test.c -o bin/linear-trick

bin/binary: $(COMMON) c/trie-binary.c
	$(GCC) c/trie-binary.c trie.c test.c -o bin/binary

bin/sse: $(COMMON) 32/trie-sse.c
	$(GCC) 32/trie-sse.c trie.c test.c -o bin/sse

test: $(PROG)
	echo "dupa"

clean:
	$(RM) -f *.o c/*.o 32/*.o
	$(RM) -f $(PROG)
