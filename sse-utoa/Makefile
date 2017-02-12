.SUFFIXES:

FLAGS=-O2 -Wall -pedantic -m32

demo: *.c
	$(CC) $(FLAGS) $^ -o $@

verify: verify.sh demo
	./verify.sh
 
compare: experiment.sh demo
	./experiment.sh

clean:
	rm -f demo

