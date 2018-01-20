#include <stdint.h>


void fill_buffer(const double x);
void print_buffer();

int main(int argc, char* argv[]) {
	double x;
	int i;

	for (i=1; i < argc; i++) {
		x = atof(argv[i]);
		printf("printf => %f\n", x);

		printf("FBSTP  => ");
		fill_buffer(x);
		print_buffer();
		putchar('\n');
	}

	return 0;
}


uint8_t buffer[11];

void fill_buffer(const double x) {
	__asm__ (
		"fbstp (%%eax)\n"
		:
		: "f" (x), "a" (buffer)
		: "memory"
	);
}


void print_buffer() {
	int i;
	char nonzero = 0;

	// first char determines type and sign of value
	switch (buffer[9]) {
		case 0x00:
			//putchar('+');
			break;

		case 0x80:
			putchar('-');
			break;

		default:
			// buffer[9] == 0xff
			// buffer[8] == 0xc0
			printf("NaN/overflow");
			return;
	}

	// decode BCD and skip leading zeros
	for (i=8; i >= 0; i--) {
		const int lo = buffer[i] & 0x0f;
		const int hi = (buffer[i] >> 4) & 0x0f;
		if (nonzero || hi > 0) {
			printf("%d", hi);

			if (hi > 0)
				nonzero = 1;
		}

		if (nonzero || lo > 0) {
			printf("%d", lo);

			if (lo > 0)
				nonzero = 1;
		}
	}

	// no digits were printed -> zeros
	if (!nonzero) {
		putchar('0');
	}
}
