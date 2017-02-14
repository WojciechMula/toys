/************************************************************************

	Trie speedup - some statistics

	author: Wojciech Muła
	e-mail: wojciech_mula@poczta.onet.pl
	last update: 2013-09-30

	license: simplifed BSD

************************************************************************/

#define _POSIX_C_SOURCE 201109
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <iso646.h>
#include <string.h>
#include <sys/time.h>
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

#define TERM_WIDTH 70

void print_statistics(trie_statistics_t* stats) {
	printf("words: %d\n", stats->word_count);
	printf("nodes: %d\n", stats->node_count);

	printf(" len  |  count  | word length\n");
	print_histogram(stats->word_length, "%5d | %7d | ", TERM_WIDTH, '=');

	putchar('\n');
	printf(" len  |  count  | node degree\n");
	print_histogram(stats->degree, "%5d | %7d | ", TERM_WIDTH, '=');

	putchar('\n');
	printf(" len  |  count  | characters\n");
	print_histogram(stats->degree, "%5d | %7d | ", TERM_WIDTH, '=');
}
//---------------------------------------------------------------------------

int load_dictionary(TrieNode* root, FILE* file) {
    char buffer[256];
    size_t n;
    int k = 0; 

    while (not feof(file)) {
        fgets(buffer, sizeof(buffer), file);
        n = strlen(buffer);
        
        if (n > 1) {
            k += trie_add_word(root, buffer, n-1);
        }
    }

    return k;
}
//---------------------------------------------------------------------------

void usage() {
    puts("program dictionary-file");
}

int main(int argc, char* argv[])
{
    TrieNode* root;

    if (argc != 2) {
        usage();
        return EXIT_FAILURE;
    }

    printf("loading dictionary... ");
	fflush(stdout);
    {
        root = trie_new_node();
        assert(root != NULL);
        FILE* f = fopen(argv[1], "rt");
        assert(f != NULL);
		const int n = load_dictionary(root, f);
        printf("%d words loaded\n", n);
        fclose(f);
    }

    trie_statistics_t stats;
	trie_statistics(root, &stats);

	print_statistics(&stats);

	trie_destroy(root);

    return EXIT_SUCCESS;
}
