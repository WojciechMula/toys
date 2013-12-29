#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "ieee_double.h"

void print_double(const double x);
void print_double_params(const double x);

int main(int argc, char* argv[]) {
	for (int i=1; i < argc; i++) {
		const double value = atof(argv[i]);
		print_double_params(value);
		print_double(value);
	}
}




void print_bin(const uint64_t value, int minbits, int maxbits);
void repeat_char(const char c, const int repeat);

void print_double(const double x) {
	IEEE754_double number = {.value = x};

	putchar('+');
	repeat_char('-', 1);
	putchar('+');
	repeat_char('-', 11);
	putchar('+');
	repeat_char('-', 52);
	putchar('+');
	putchar('\n');

	putchar('|');
		print_bin(number.qword, 63, 63); // sign
	putchar('|');
		print_bin(number.qword, 52, 62); // exp_bias
	putchar('|');
		print_bin(number.qword,  0, 51); // fraction
	putchar('|');
	putchar('\n');

	putchar('+');
	repeat_char('-', 1);
	putchar('+');
	repeat_char('-', 11);
	putchar('+');
	repeat_char('-', 52);
	putchar('+');
	putchar('\n');

	printf("63");
	repeat_char(' ', 1);
	printf("62");
	repeat_char(' ', 7);
	printf("52");
	repeat_char(' ', 1);
	printf("51");
	repeat_char(' ', 50);
	printf("0");
	putchar('\n');
}

void print_double_params(const double x) {
	IEEE754_double number = {.value = x};

	printf("sign           = %d\n", number.fields.sign);
	printf("exponent       = %d\n", number.fields.exp_bias - IEEE754_DOUBLE_BIAS);
	printf("fraction [hex] = %013llx\n", number.fields.fraction);
}

void print_bin(const uint64_t value, int minbits, int maxbits) {
	for (int bit=maxbits; bit >= minbits; bit--) {
		if (value & ((uint64_t)1 << bit)) {
			putchar('1');
		} else {
			putchar('0');
		}
	}
}

void repeat_char(const char c, const int repeat) {
	for (int i=0; i < repeat; i++)
		putchar(c);
}

