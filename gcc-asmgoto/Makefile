CC=gcc

all: demo1 demo2 show

demo1: asmgoto.c
	$(CC) asmgoto.c -O3 -DNO_ASM_GOTO -o $@

demo2: asmgoto.c
	$(CC) asmgoto.c -O3 -o $@

show: demo1 demo2
	./demo1 0xff 0
	./demo1 0xff 1
	./demo1 0xff 2
	./demo1 0xff 4
	./demo1 0xff 5
	./demo1 0xff 6
	./demo1 0xff 7
	./demo1 0xff 8
	./demo1 0xff 12
	./demo2 0xff 0
	./demo2 0xff 1
	./demo2 0xff 2
	./demo2 0xff 4
	./demo2 0xff 5
	./demo2 0xff 6
	./demo2 0xff 7
	./demo2 0xff 8
	./demo2 0xff 12

clean:
	rm -f demo1 demo2
