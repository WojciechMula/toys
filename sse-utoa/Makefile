.SUFFIXES:

FLAGS=-O2 -Wall -pedantic -m32

demo: *.c
	$(CC) $(FLAGS) $^ -o $@

verify: verify.sh demo
	./verify.sh
    

clean:
	rm -f demo

