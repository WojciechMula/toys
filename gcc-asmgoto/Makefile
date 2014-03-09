CC=gcc

all: demo show

demo: asmgoto.c
	$(CC) asmgoto.c -o $@

show: demo
	./demo 0xff 0
	./demo 0xff 1
	./demo 0xff 2
	./demo 0xff 4
	./demo 0xff 5
	./demo 0xff 6
	./demo 0xff 7
	./demo 0xff 8
	./demo 0xff 12

clean:
	rm -f demo
