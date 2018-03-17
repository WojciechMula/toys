.SUFFIXES:

FLAGS=-O2 -Wall -Wextra -pedantic $(CXXFLAGS)
FLAGS=-O2 $(CXXFLAGS)

demo: sse-utoa.c
	$(CC) $(FLAGS) -m32 $^ -o $@

demo64: sse-intrin-utoa.c
	$(CC) $(FLAGS) $^ -o $@

verify: verify.sh demo
	./verify.sh
 
compare: experiment.sh demo
	./experiment.sh

clean:
	rm -f demo demo64

