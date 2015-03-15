#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <sys/time.h>


uint8_t buffer[11];

void invoke_fbstp(const double x);
void simple_itoa(int x);
uint32_t get_time(void);

int main() {
	int i;
	uint32_t t1, t2;

	const int max = 10000000;

	puts("FBSTP...");
	t1 = get_time();
	for (i=1; i < max; i++) {
		invoke_fbstp(i);
	}
	t2 = get_time();
	printf("... %0.3f s\n", (t2 - t1)/1000000.0);

	puts("simple itoa...");
	t1 = get_time();
	for (i=1; i < max; i++) {
		simple_itoa(i);
	}
	t2 = get_time();
	printf("... %0.3f s\n", (t2 - t1)/1000000.0);


	return 0;
}


void invoke_fbstp(const double x) {
	__asm__ (
		"fbstp (%1)\n"
		: 
		: "f" (x), "r" (buffer)
		: "memory"
	);
}


void simple_itoa(int x) {
	int i = 0;
	while (x > 0) {
		buffer[i] = x % 10 + '0';
		x /= 10;
	}
}


uint32_t get_time(void) {
	struct timeval T;
	gettimeofday(&T, NULL);
	return (T.tv_sec * 1000000) + T.tv_usec;
}
