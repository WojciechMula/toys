#include "trie.h"

static void print_histogram(size_t histogram[256], const char* format, int width, char active) {
	size_t i_min = 0;
	size_t i_max = 0;
	size_t max = 0;

	// find the largest value and max non zero index
	for (int i=0; i < 256; i++) {
		const size_t val = histogram[i];
		if (val > max) {
			max = val;
		}

		if (val > 0) {
			i_max = i;
		}
	}

	for (int i=i_min; i <= i_max; i++) {
		size_t val = histogram[i];
		printf(format, i, val);

		if (max > 0) {
			for (int j=0; j < (int)(width*val/max); j++) {
				putchar(active);
			}
		}

		putchar('\n');
	}
}
//---------------------------------------------------------------------------

void print_statistics(trie_statistics_t* stats) {
	printf("words: %d\n", stats->word_count);
	printf("nodes: %d\n", stats->node_count);

	printf(" len  |  count  | word length histogram\n");
	print_histogram(stats->word_length, "%5d | %7d | ", 60, '=');

	putchar('\n');
	printf(" len  |  count  | node degree histogram\n");
	print_histogram(stats->degree, "%5d | %7d | ", 60, '=');

	putchar('\n');
	printf(" len  |  count  | characters histogram\n");
	print_histogram(stats->degree, "%5d | %7d | ", 60, '=');
}
//---------------------------------------------------------------------------



