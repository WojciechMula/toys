#define _POSIX_C_SOURCE 201109
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <iso646.h>
#include <string.h>
#include <sys/time.h>
#include "trie.h"


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

typedef struct {
	char** list;
	size_t count;
} strings_t;


void load_words(FILE* file, strings_t* words) {
    char buffer[256];
	size_t allocated = 128;
	int r=0;
	
	words->list = (char**)malloc(allocated * sizeof(char*));
	words->count = 0;

	while (not feof(file)) {
        fgets(buffer, sizeof(buffer), file);
        int n = strlen(buffer);
 
        words->list[words->count] = strndup(buffer, n-1);

		words->count += 1;
		if (words->count >= allocated) {
			allocated += allocated/2;
			words->list = (char**)realloc(words->list, allocated * sizeof(char*));
			r += 1;
		}
    }
}


void free_strings(strings_t *strings) {
	for (size_t i=0; i < strings->count; i++) {
		free(strings->list[i]);
	}

	free(strings->list);
	strings->list = NULL;
	strings->count = 0;
}

unsigned gettime() {
	struct timeval tv;
	gettimeofday(&tv, NULL);

	return (tv.tv_sec * 1000000 + tv.tv_usec)/1000;
}
//---------------------------------------------------------------------------

void usage() {
    puts("program dictionary-file word-test-file iterations-count");
}

int main(int argc, char* argv[])
{
    TrieNode*   root;
    int         iterations;
	strings_t   words;

    if (argc != 4) {
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

    printf("loading test words... ");
	fflush(stdout);
    {
        FILE *f = fopen(argv[2], "rt");
        assert(f != NULL);
        load_words(f, &words);
		printf("%d words loaded\n", words.count);
        fclose(f);
    }

    
    puts("benchmarking...");
        iterations = atoi(argv[3]);
        assert(iterations > 0);

        unsigned t1 = gettime();
        int count = 0;
        for (int j = 0; j < iterations; j++) {
            count = 0;
            for (int i=0; i < words.count; i++) {
                count += (int)trie_lookup(root, words.list[i]);
            }
        }
        unsigned t2 = gettime();

        printf("... time = %d ms, matched words = %d\n", t2 - t1, count);

	free_strings(&words);
	trie_destroy(root);

    return EXIT_SUCCESS;
}
