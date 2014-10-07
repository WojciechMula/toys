.SUFFIXES:

CC=g++
FLAGS=-std=c++11 -Wall -Wextra -pedantic
DEPS=conv.swar.c conv.pdep.c conv.sse2.c conv.single-lookup.c conv.two-lookups.c common.c conv.cpp conv.h

all: verify speedup speedup_pdep

verify: verify.cpp $(DEPS)
	$(CC) $(FLAGS) verify.cpp conv.cpp -o $@

speedup: speedup.cpp $(DEPS)
	$(CC) $(FLAGS) -O3 -DNDEBUG speedup.cpp conv.cpp -o $@

speedup_pdep: speedup.cpp $(DEPS)
	$(CC) $(FLAGS) -O3 -DNDEBUG -DHAVE_PDEP_INSTRUCTION speedup.cpp conv.cpp -o $@

clean:
	rm -f verify speedup speedup_pdep

