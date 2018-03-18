.SUFFIXES:
.PHONY: all clean

FLAGS=-O2 -Wall -Wextra -pedantic
FLAGS=-O2 $(CXXFLAGS)

DEPS=procedures.c\
     *-intrin.c\
     *-asm.c

all: demo verify

demo: sse-utoa.c $(DEPS)
	$(CC) $(FLAGS) $< -o $@

verify: verify.c $(DEPS)
	$(CC) $(FLAGS) $< -o $@
 
compare: experiment.sh demo
	./experiment.sh

clean:
	rm -f demo verify

