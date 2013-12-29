#include <stdio.h>
#include <math.h>
#include "float2int.c"


int main(int argc, char* argv[]) {
	IEEE745_float number;

	uint64_t i;
	for (i=0; i < UINT32_MAX; i++) {
		number.dword = i & 0xffffffff;

		if ((number.dword & 0xfff) == 0)
			printf("dword: %08x\n", number.dword);

		if (!isnormal(number.value))
			continue;

		const int   casted    = (int)number.value;
		const int   converted = float2int(number.value);
		const int   overflow  = (errno == ERANGE);

		if (casted != INT32_MIN) {
			if (casted != converted) {
				puts("ERROR: CONVERT");
				printf("\tvalue     : %0.9f\n", number.value);
				printf("\tcasted    : %d\n", casted);
				printf("\tfloat2int : %d (overflow=%s)\n", converted, overflow ? "yes" : "no");
			}
		} else {
			if (!overflow) {
				puts("ERROR: OVERFLOW DETECT");
				printf("\tvalue     : %0.9f\n", number.value);
				printf("\tcasted    : %d\n", casted);
				printf("\tfloat2int : %d (overflow=%s)\n", converted, overflow ? "yes" : "no");
			}
		}
	}
}
