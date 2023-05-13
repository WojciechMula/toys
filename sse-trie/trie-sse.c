/************************************************************************

	Trie speedup - trie_next: SSE implementation

	author: Wojciech Muła
	e-mail: wojciech_mula@poczta.onet.pl
	last update: 2013-09-30

	license: simplifed BSD

************************************************************************/

#define _POSIX_C_SOURCE 200112

#include "trie.h"
#include <string.h>
#include <stdlib.h>
#include <immintrin.h>


#define SIMD_ALIGN 16
#define ALIGNED_SIZE(size) (SIMD_ALIGN*(((size) + SIMD_ALIGN - 1)/SIMD_ALIGN))

TrieNode* trie_next(TrieNode* node, const char letter) {
    const int n = node->n;
    const __m128i v = _mm_set1_epi8(letter);

    size_t i, j;
    for (i = 0; i < n; i+=16) {
        const __m128i  input = _mm_loadu_si128((const __m128i*)(&(node->chars[i])));
        const __m128i  eq    = _mm_cmpeq_epi8(input, v);
        const unsigned m     = _mm_movemask_epi8(eq);
        if (m != 0) {
            j = __builtin_ctz(m) + i;
            if (j < n) {
                return node->next[j];
            }
        }
    }

    return NULL;
}

void trie_add_link(TrieNode* node, TrieNode* newnode, const char letter) {
	const size_t old_count = node->n;
	const size_t new_count = old_count + 1;

	if (ALIGNED_SIZE(new_count) > ALIGNED_SIZE(old_count)) {
		char* tmp;
		posix_memalign((void**)&tmp, SIMD_ALIGN, ALIGNED_SIZE(new_count));

		memset(tmp, 0, ALIGNED_SIZE(new_count));
		memcpy(tmp, node->chars, old_count);

		free(node->chars);
		node->chars = tmp;
	}

    node->n += 1;
    node->next = (TrieNode**)realloc(node->next, sizeof(TrieNode*) * node->n);

    node->chars[node->n - 1] = letter;
    node->next [node->n - 1] = newnode;
}

