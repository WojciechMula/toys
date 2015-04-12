.SUFFIXES:

CC=g++
FLAGS=-std=c++11 -Wall -Wextra -pedantic
DEPS=conv.swar.c conv.pdep.c conv.sse2.c conv.single-lookup.c conv.two-lookups.c common.c conv.cpp conv.h
ALL=verify speedup speedup_pdep

all: $(ALL)

verify: verify.cpp $(DEPS)
	$(CC) $(FLAGS) $< conv.cpp -o $@

speedup: speedup.cpp $(DEPS)
	$(CC) $(FLAGS) -O3 -DNDEBUG $< conv.cpp -o $@

speedup_pdep: speedup.cpp $(DEPS)
	$(CC) $(FLAGS) -O3 -DNDEBUG -DHAVE_PDEP_INSTRUCTION $< conv.cpp -o $@

clean:
	rm -f $(ALL)

