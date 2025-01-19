.PHONY: clean

FLAGS=-O3 -std=c99 -lX11 
FLAGS_DEMO=$(FLAGS)
FLAGS_LIB=$(FLAGS) -Wall -Wextra -pedantic -Werror

demo: demo.c Xscr.o
	$(CC) $(FLAGS_DEMO) Xscr.o demo.c -o $@

Xscr.o: Xscr.c Xscr.h
	$(CC) $(FLAGS_LIB) -c Xscr.c -o $@

clean:
	rm -f demo Xscr.o
