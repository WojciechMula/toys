.SUFFIXES:
.PHONY: all clean

FLAGS=-O2 -Wall -Wextra -pedantic
FLAGS=-O2 -std=c99 $(CXXFLAGS)

DEPS=procedures.c\
     *-intrin.c\
     *-asm.c

ALL=demo verify benchmark

all: $(ALL)

demo: sse-utoa.c $(DEPS)
	$(CC) $(FLAGS) $< -o $@

verify: verify.c $(DEPS)
	$(CC) $(FLAGS) $< -o $@

benchmark: benchmark.c $(DEPS)
	$(CC) $(FLAGS) $< -o $@
 
compare: experiment.sh benchmark
	./experiment.sh

clean:
	rm -f $(ALL)

