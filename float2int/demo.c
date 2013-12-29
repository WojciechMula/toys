#include <stdio.h>
#include "float2int.c"


int main(int argc, char* argv[]) {
	for (int i=1; i < argc; i++) {
		const float value     = atof(argv[i]);
		const int   casted    = (int)value;
		const int   converted = float2int(value);
		const int   overflow  = (errno == ERANGE);

		printf("input: '%s'\n", argv[i]);
		printf("\tvalue     : %0.9f\n", value);
		printf("\tcasted    : %d\n", casted);
		printf("\tfloat2int : %d (overflow=%s)\n", converted, overflow ? "yes" : "no");
	}
}
