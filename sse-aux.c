#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_vect(float* v) {
	int i;
	printf("{", i);
	for (i=0; i < 4; i++) {
		printf("%12.2f", v[i]);
		if (i < 3) printf(", ");
		else printf("}\n");
	}
}

void print_xmmps(int i) {
	static float v[4];
	switch (i) {
		case 0: asm("movups %%xmm0, (%0)":: "r" (v)); break;
		case 1: asm("movups %%xmm1, (%0)":: "r" (v)); break;
		case 2: asm("movups %%xmm2, (%0)":: "r" (v)); break;
		case 3: asm("movups %%xmm3, (%0)":: "r" (v)); break;
		case 4: asm("movups %%xmm4, (%0)":: "r" (v)); break;
		case 5: asm("movups %%xmm5, (%0)":: "r" (v)); break;
		case 6: asm("movups %%xmm6, (%0)":: "r" (v)); break;
		case 7: asm("movups %%xmm7, (%0)":: "r" (v)); break;
	}
	printf("xmm%d = ", i);
	print_vect(v);
}

float initfrand() {
	srand(time(NULL));
}

float frand(float min, float max) {
	return (max - min)*rand()/(float)RAND_MAX + min;
}

// vim: ts=4 sw=4 nowrap
