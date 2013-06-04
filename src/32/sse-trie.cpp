#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

#include <sys/time.h>

typedef struct TrieNode {
    char        eow;         // end of word
    size_t      n;           // elements in buffer
    char*       chars;       // n chars
    TrieNode**  next;        // n pointers
} TrieNode;

TrieNode* trie_new_node() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));

    node->eow   = false;
    node->n     = 0;
    node->chars = NULL;
    node->next  = NULL;

    return node;
}

#define SIMD_ALIGN 16
#define ALIGNED_SIZE(size) (SIMD_ALIGN*(((size) + SIMD_ALIGN - 1)/SIMD_ALIGN))

//#define SORT
#define LINEAR_SEARCH
#define SSE

TrieNode* trie_next_c(TrieNode* node, const char letter) {
#ifdef SORT
    int a = 0;
    int b = node->n - 1;

    while (a <= b) {
        const int c = (a + b)/2;
        if (node->chars[c] == letter) {
            return node->next[c];
        }

        if (letter < (int)node->chars[c]) {
            b = c - 1;
        } else {
            a = c + 1;
        }
    }

    return NULL;
#endif

#ifdef LINEAR_SEARCH
    size_t i;
    for (i = 0; i < node->n; i++) {
        if (node->chars[i] == letter) {
            return node->next[i];
        }
    }

    return NULL;
#endif
}

TrieNode* trie_next_sse(TrieNode* node, const char letter) {
    const int n = node->n;

    if (n == 0) {
        return NULL;
    }

    if (n == 1) {
        if (node->chars[0] == letter) {
            return node->next[0];
        } else {
            return NULL;
        }
    }

    int dummy;
    asm __volatile__ (
        "movzbl %%al, %%eax                 \n"
        "imul   $0x01010101, %%eax, %%eax   \n"
        "movd   %%eax, %%xmm0               \n"
        "pshufd $0x00, %%xmm0, %%xmm0       \n"
        : "=a" (dummy)
        : "a" (letter)
    );

    size_t i, j;
    for (i = 0; i < n; i+=16) {
        asm __volatile__ (
            "movdqa (%%eax), %%xmm1         \n"
            "pcmpeqb %%xmm0, %%xmm1         \n"
            "pmovmskb %%xmm1, %%eax         \n"
            "bsf %%eax, %%eax               \n"
            "setz %%ah                      \n"
            : "=a" (j)
            : "a"  (&(node->chars[i]))
        );
        if (j < 256) {
            return node->next[i+j];
        }
    }

    return NULL;
}

TrieNode* trie_next_trick(TrieNode* node, const char letter) {
    const int n = node->n;

    if (n == 0) {
        return NULL;
    }

    if (n == 1) {
        if (node->chars[0] == letter) {
            return node->next[0];
        } else {
            return NULL;
        }
    }

    uint32_t ml = (letter & 0xff) * 0x01010101;

    size_t i;
    int k;
    for (i = 0; i < n; i+=4) {
        const uint32_t tmp = *((uint32_t*)&node->chars[i]);
        const uint32_t v = tmp ^ ml;

        const uint32_t mask = v - 0x01010101 & (~v) & 0x80808080;

#if 0
        asm __volatile__ (
            "bsf %%eax, %%eax\n"
            "mov $-1, %%ecx\n"
            "jz 1f\n"
            "shr $3, %%eax\n"
            "mov %%eax, %%ecx\n"
            "1:"
            : "=c" (k)
            : "a" (mask)
        );

#else
        k = -1;

        if (mask & 0x00000080) {
            k = 0; //return node->next[i + 0];
        } else

        if (mask & 0x00008000) {
            k = 1; //return node->next[i + 1];
        } else

        if (mask & 0x00800000) {
            k = 2; //return node->next[i + 2];
        } else

        if (mask & 0x80000000) {
            k = 3; //return node->next[i + 3];
        }
#endif
        if (k >= 0) {
            return node->next[i + k];
        }
    }

    return NULL;
}

#ifdef SSE_
#   define trie_next trie_next_sse
#   define trie_next trie_next_trick
#else
#   define trie_next trie_next_c
#endif

void trie_add_link(TrieNode* node, TrieNode* newnode, const char letter) {
    node->n += 1;
    if (0) {
        node->chars = (char*)realloc(node->chars, node->n);
    } else {
        char* tmp;
        posix_memalign((void**)&tmp, SIMD_ALIGN, ALIGNED_SIZE(node->n));
        memset(tmp, 0, ALIGNED_SIZE(node->n));
        memcpy(tmp, node->chars, node->n - 1);
        node->chars = tmp;
    }

    node->next  = (TrieNode**)realloc(node->next, sizeof(TrieNode*) * node->n);

    node->chars[node->n - 1] = letter;
    node->next [node->n - 1] = newnode;

#ifdef SORT
    const int n = node->n;
    for (int i=0; i < n; i++) {
        int  min = 256;
        int  minidx = -1;
        for (int j=i; j < n; j++) {
            if (node->chars[j] < min) {
                min = node->chars[j];
                minidx = j;
            }
        }

        if (minidx >= 0) {
            {
                char tmp = node->chars[i];
                node->chars[i] = node->chars[minidx];
                node->chars[minidx] = tmp;
            }
            {
                TrieNode* tmp = node->next[i];
                node->next[i] = node->next[minidx];
                node->next[minidx] = tmp;
            }
        }
    }
#endif
}

void trie_add_word(TrieNode* root, const char* word, const size_t n) {
    size_t i;
    TrieNode* node = root;

    if (n == 0)
        return;

    for (i=0; i < n; i++) {
        const char letter = word[i];
        TrieNode* tmp = trie_next(node, letter);
        if (tmp == NULL) {
            tmp = trie_new_node();
            trie_add_link(node, tmp, letter);
        }

        node = tmp;
    }

    node->eow = true;
}

bool trie_lookup(TrieNode* root, char* word, const size_t n) {
    TrieNode* node = root;

    for (size_t i = 0; i < n; i++) {
        const char letter = word[i];
        node = trie_next(node, letter);
        if (node == NULL) {
            return false;
        }
    }

    return node ? node->eow : false;
}

bool trie_lookup(TrieNode* root, char* word) {
    TrieNode* node = root;
    char* c = word;

    while (*c) {
        const char letter = *c++;
        node = trie_next(node, letter);
        if (node == NULL) {
            return false;
        }
    }

    return node ? node->eow : false;
}

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
