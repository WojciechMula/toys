#include "trie.h"

#define ROUND_UP(size) (4*(((size) + 3)/4))


TrieNode* trie_next(TrieNode* node, const char letter) {
    const int n = node->n;

	switch (n) {
		case 0:
        	return NULL;

		case 1:
			if (node->chars[0] == letter)
				return node->next[0];

			if (n == 1)
				return NULL;

		case 2:
			if (node->chars[1] == letter)
				return node->next[1];

			if (n == 2)
				return NULL;

		case 3:
			if (node->chars[2] == letter)
				return node->next[2];

			if (n == 3)
				return NULL;
	}
	

    uint32_t ml = (letter & 0xff) * 0x01010101;

    size_t i;
    int k;
    for (i = 0; i < n; i+=4) {
        const uint32_t tmp = *((uint32_t*)&node->chars[i]);
        const uint32_t v = tmp ^ ml;
        const uint32_t mask = v - 0x01010101 & (~v) & 0x80808080;

		const uint32_t f = __builtin_ffs(mask);
		if (f != 0) {
			return node->next[i + f/8 - 1];
		}
    }

    return NULL;
}


void trie_add_link(TrieNode* node, TrieNode* newnode, const char letter) {
    node->n += 1;
    node->chars = (char*)realloc(node->chars, ROUND_UP(node->n));
    node->next  = (TrieNode**)realloc(node->next, sizeof(TrieNode*) * node->n);

    node->chars[node->n - 1] = letter;
    node->next [node->n - 1] = newnode;
	for (size_t i = node->n; i < ROUND_UP(node->n); i++) {
		node->chars[i] = 0;
	}
}
