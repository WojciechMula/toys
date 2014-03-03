CC=gcc
FLAGS=-std=c99

.SUFFIXES:

all: demo show

demo: kill-strstr.c
	$(CC) $(FLAGS) $^ -o $@

show: demo
	sh demo.sh

clean:
	rm -f demo
