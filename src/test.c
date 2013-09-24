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
            trie_add_word(root, buffer, n-1);
            k++;
        }
    }

    return k;
}

char** load_words(FILE* file, size_t wordscount) {
    char buffer[256];
    char** list = (char**)malloc(wordscount * sizeof(char*));

    for (size_t i = 0; i < wordscount; i++) {
        fgets(buffer, sizeof(buffer), file);
        int n = strlen(buffer);
        
        list[i] = strndup(buffer, n-1);
    }

    return list;
}

unsigned gettime() {
	struct timeval tv;
	gettimeofday(&tv, NULL);

	return (tv.tv_sec * 1000000 + tv.tv_usec)/1000;
}
//---------------------------------------------------------------------------

void usage() {
    puts("program dictionary-file word-test-file number-of-words iterations-count");
}

int main(int argc, char* argv[])
{
    char**      words;
    int         wordscount;
    TrieNode*   root;
    int         iterations;

    if (argc != 5) {
        usage();
        return EXIT_FAILURE;
    }

    puts("loading dictionary...");
    {
        root = trie_new_node();
        assert(root != NULL);
        FILE* f = fopen(argv[1], "rt");
        assert(f != NULL);
        load_dictionary(root, f);
        fclose(f);
    }

    puts("loading test words");
    {
        FILE *f = fopen(argv[2], "rt");
        assert(f != NULL);
        wordscount = atoi(argv[3]);
        assert(wordscount > 0);
        words = load_words(f, wordscount);
    }

    
    puts("benchmarking...");
        iterations = atoi(argv[4]);
        assert(iterations > 0);

        unsigned t1 = gettime();
        int count = 0;
        for (int j = 0; j < iterations; j++) {
            count = 0;
            for (int i=0; i < wordscount; i++) {
                count += (int)trie_lookup(root, words[i]);
            }
        }
        unsigned t2 = gettime();

        printf("... time = %d ms, matched words = %d\n", t2 - t1, count);

    return EXIT_SUCCESS;
}
