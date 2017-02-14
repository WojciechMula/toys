#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int myrange01(float x)
{
 uint32_t bin   = *(uint32_t*)&x;

 if ((bin & 0x7fffffff) == 0)		// x = +/-0.0
	 return 1;
 if ((bin & 0x80000000) == 0x80000000)	// x < 0
	 return 0;
 if (bin > 0x3f800000)			// exp > 1.0
	 return 0;
 else
	 return 1;
}
