/*
	Image crossfading --- SSE implementation, $Revision: 1.10 $

	Author: Wojciech Muła
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://0x80.pl/

	License: BSD

	initial release 5-06-2008, last update $Date: 2008-06-21 22:15:11 $

	----------------------------------------------------------------------

	Comparison of three crossfading procedures:
	1. x86    --- naive C implementation
	2. sse4   --- SSE implementation
	3. sse4-2 --- SSE4 implementation, that use new instruction PMADDUBSW 
*/

#ifndef _XOPEN_SOURCE
#	define _XOPEN_SOURCE 600
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdarg.h>
#include <stdint.h>
#include <sys/time.h>
#include <time.h>
#include <immintrin.h>
#include <emmintrin.h>


//=== global variables ===================================================
int width, height, maxval;
uint8_t *imgA, *imgB, *data;
uint8_t alpha;

int function = 0;


#define OPT_COUNT 6

static char* function_name[OPT_COUNT] = {
	"x86", "SSE4", "SSE4-2", "swar-64bit", "SSE(1)", "SSE(2)",
};


static char* function_name_abbr[OPT_COUNT] = {
	"x86", "SSE4", "SSE4-2", "swar", "SSE-1", "SSE-2"
};



//=== common functions ===================================================
uint32_t getTime(void) {
	static struct timeval T;
	gettimeofday(&T, NULL);
	return (T.tv_sec * 1000000) + T.tv_usec;
}



void die(const char* fmt, ...) {
	va_list ap;

	va_start(ap, fmt);
	vprintf(fmt, ap);
	putchar('\n');
	va_end(ap);

	exit(2);
}



//=== crossfading implementations ========================================
#include "blend_scalar.c"
#include "blend_sse4.c"
#include "blend_sse42.c"
#include "blend_swar_64bit.c"
#include "blend_sse.c"


//=== test procedure =====================================================
void measure(int function, int repeat_count) {
	uint32_t t1, t2;
	int n = repeat_count;
	
	printf(
		"function %s, called %d times; image %d x %d\n",
		function_name[function],
		repeat_count,
		width, height
	);

	switch (function) {
		case 0:
			t1 = getTime();
			while (n--)
				blend();
			t2 = getTime();
			break;
		
		case 1:
			t1 = getTime();
			while (n--)
				SSE4_blend();
			t2 = getTime();
			break;
		
		case 2:
			t1 = getTime();
			while (n--)
				SSE42_blend();
			t2 = getTime();
			break;
		
		case 3:
			t1 = getTime();
			while (n--)
				swar_64bit_blend();
			t2 = getTime();
			break;
		
		case 4:
			t1 = getTime();
			while (n--)
				blend_sse_1();
			t2 = getTime();
			break;
		
		case 5:
			t1 = getTime();
			while (n--)
				blend_sse_2();
			t2 = getTime();
			break;
		default:
			return;
	}

	printf("time = %d us\n", t2 - t1);
}


//=== main program =======================================================
void help(char* progname) {
	int i;

	printf("1. %s measure %s", progname, function_name_abbr[0]);

	for (i=1; i < OPT_COUNT; i++)
		printf("|%s", function_name_abbr[i]);
	
	printf(" repeat-count\n");
#ifdef USE_Xscr
	printf("2. %s view file1.ppm file2.ppm\n", progname);
#endif

	exit(1);
}


int main(int argc, char* argv[]) {
	int function;
	int repeat_count;

	// parse args
	if (argc < 2)
		help(argv[0]);

	if (strcasecmp(argv[1], "measure") == 0) {
		if (argc < 4)
			help(argv[0]);

		repeat_count = atoi(argv[3]);
		if (repeat_count < 0)
			help(argv[0]);

		width  = 1024;
		height = 768;
		alpha  = 127;

		imgA = NULL;
		imgB = NULL;
		data = NULL;

		posix_memalign((void*)&imgA, 16, width*height*4);
		if (imgA == NULL) die("No free memory");

		posix_memalign((void*)&imgB, 16, width*height*4);
		if (imgB == NULL) die("No free memory");

		posix_memalign((void*)&data, 16, width*height*4);
		if (data == NULL) die("No free memory");

		for (function=0; function < OPT_COUNT; function++) {
			if (strcasecmp(argv[2], function_name_abbr[function]) == 0) {
				measure(function, repeat_count);
				break;
			}
		}

		free(imgA);
		free(imgB);
		free(data);
		
		if (function == OPT_COUNT)
			help(argv[0]);
		else
			return 0;
	}
#ifdef USE_Xscr
	else
	if (strcasecmp(argv[1], "view") == 0) {
		if (argc < 4)
			help(argv[0]);
		else
			view(argv[2], argv[3]);
	}
#endif
	else
		help(argv[0]);

	
	return 0;
}

