/*

	Time sequential memory scan vs random scan

	Wojciech Mu³a, 2010-01-06


*/
#include <iso646.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void seq(uint32_t* tbl, uint32_t n);
void shuffle(uint32_t* tbl, uint32_t n);
uint32_t scanmem(uint32_t* tbl, uint32_t* indexes, uint32_t n);

int main(int argc, char* argv[]) {
	int n = 0;
	uint32_t* table   = NULL;
	uint32_t* indexes = NULL;
	clock_t ta1, ta2;
	clock_t tb1, tb2;
	
	if (argc < 2) {
		fprintf(stderr, "program table_size\n");
		return EXIT_FAILURE;
	}

	n = strtoul(argv[1], NULL, 0); 
	if (n <= 0) {
		fprintf(stderr, "table_size=%d <= 0\n", n);
		return EXIT_FAILURE;
	}

	table   = malloc(sizeof(uint32_t)*n);
	indexes = malloc(sizeof(uint32_t)*n);
	if (table == NULL or indexes == NULL) {
		if (table) free(table);
		if (indexes) free(table);
	}

	seq(table, n);
	seq(indexes, n);

	printf("sequential scan... "); fflush(stdout);
	ta1 = clock();
		scanmem(table, indexes, n);
	ta2 = clock();
	printf("took %0.2fs\n", (double)(ta2 - ta1)/CLOCKS_PER_SEC);

	printf("shuffling indexes... "); fflush(stdout);
	srand(time(NULL));
	shuffle(indexes, n);
	putchar('\n');
	
	printf("random scan... "); fflush(stdout);
	tb1 = clock();
		scanmem(table, indexes, n);
	tb2 = clock();
	printf("took %0.2fs\n", (double)(tb2 - tb1)/CLOCKS_PER_SEC);

	if (tb2 - tb1 != 0) {
		printf("slower %0.3f times\n", (double)(tb2 - tb1)/(ta2 - ta1));
	}


	free(table);
	free(indexes);
	return EXIT_SUCCESS;
}
/*------------------------------------------------------------------------*/

void seq(uint32_t* tbl, uint32_t n) {
	uint32_t i;
	for (i=0; i < n; i++)
		tbl[i] = i;
}
/*------------------------------------------------------------------------*/

void shuffle(uint32_t* tbl, uint32_t n) {
	uint32_t i, j, x;
	if (n == 0)
		return;

	for (i=0; i < n - 1; i++) {
		j = rand() % (n - i);
 
		x        = tbl[i];
		tbl[i]   = tbl[i+j];
		tbl[i+j] = x;
	}
}
/*------------------------------------------------------------------------*/

uint32_t scanmem(uint32_t* tbl, uint32_t* indexes, uint32_t n) {
	uint32_t i, acc;
	acc = 0;
	for (i=0; i < n; i++)
		acc += tbl[indexes[i]];

	return acc;
}
/*------------------------------------------------------------------------*/

