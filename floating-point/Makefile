FLAGS=-Wall -pedantic -std=c99 -O3 

all: float2int round2

float2int: float2int.c
	$(CC) $(FLAGS) -m32 $^ -o $@

round2: round2.c
	$(CC) $(FLAGS) -lm -m32 $^ -o $@

test: float2int round2
	./test-float2int.sh
	./test-round2.sh
