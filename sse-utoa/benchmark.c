/*
	SSE: conversion integers to decimal representation

	Author: Wojciech Muła
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://0x80.pl/

	License: BSD

	----------------------------------------------------------------------

	See http://0x80.pl/articles/sse-itoa.html
*/
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

#include <sys/time.h>

unsigned gettime() {
	struct timeval tv;
	gettimeofday(&tv, NULL);

	return (tv.tv_sec * 1000000 + tv.tv_usec)/1000;
}

//--- functions --------------------------------------------------------
char* utoa32_sse(const uint32_t x);   // 0 .. 9999_9999 => ASCII
char* utoa32_sse_2(const uint32_t x); // 0 .. 9999_9999 => ASCII

char* utoa32(const uint32_t x); // reference implementation

//----------------------------------------------------------------------
//--- C reference implementations --------------------------------------
//----------------------------------------------------------------------

char* utoa32(uint32_t x) {
	static char buf[17];
	uint32_t i = 15;
	do {
		buf[i--] = (x % 10) + '0';
		x /= 10;
	} while (x > 0);

	return buf + i + 1;
}


#include "procedures.c"

//----------------------------------------------------------------------

typedef char* (*convfun)(uint32_t);

struct Procedure {
    convfun procedure;
    const char* name;
    const char* keyword;
};

struct Procedure procedures[] = {
    {utoa32,        "scalar procedure", "c32"},
    {utoa32_sse,    "SSE (algorithm 1)", "sse32"},
    {utoa32_sse_2,  "SSE (algorithm 2)", "sse32_2"},
    {NULL, NULL, NULL}
};

void usage() {
	puts("usage: progname min max count [functions]");
	puts("");
	puts("where function is:");
    struct Procedure* item;
    for (item = procedures; item->procedure != NULL; item++) {
        printf("* %-8s - %s\n", item->keyword, item->name);
    }

	exit(1);
}

int is_keyword(const char* keyword, int argc, char* argv[]) {
    if (argc == 4) {
        return 1;
    }

    for (int i=4; i < argc; i++) {
        if (strcasecmp(keyword, argv[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char* argv[]) {

	if (argc < 4)
		usage();

    const uint32_t min = atoi(argv[1]);
    const uint32_t max = atoi(argv[2]);
    if (min >= max) {
        usage();
    }

    const uint32_t count = atoi(argv[3]);

    printf("Parameters: min = %u, max = %d, count = %d\n", min, max, count);

    struct Procedure* item;
    unsigned reference_time = 0;
    for (item = procedures; item->procedure != NULL; item++) {
        if (!is_keyword(item->keyword, argc, argv)) {
            continue;
        }

        unsigned tmp = count;
        convfun proc = item->procedure;

        printf("%-20s ", item->name);
        fflush(stdout);
        const unsigned t1 = gettime();
        while (tmp-- > 0) {
            for (uint32_t x = min; x <= max; x++) {
                proc(x);
            }
        }
        const unsigned t2 = gettime();
        const unsigned time = t2 - t1;
        printf("%6u ms", time);
        if (reference_time == 0) {
            reference_time = time;
            putchar('\n');
        } else {
            printf(" (%0.2f)\n", ((float)reference_time)/time);
        }
    }

	return EXIT_SUCCESS;
}

