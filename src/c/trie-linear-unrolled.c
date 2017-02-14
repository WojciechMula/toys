/************************************************************************

	Trie speedup - trie_next: linear search with minimized memory reads

	author: Wojciech Muła
	e-mail: wojciech_mula@poczta.onet.pl
	last update: 2013-09-30

	license: simplifed BSD

************************************************************************/

#include "trie.h"

#define ROUND_UP(size) (4*(((size) + 3)/4))


TrieNode* trie_next(TrieNode* node, const char letter) {
	const uint32_t n = node->n;
	if (n == 0) {
		return NULL;
	}

    const uint32_t packed_byte = (letter & 0xff) * 0x01010101;

    for (size_t i = 0; i < n; i+=4) {
        const uint32_t dword = *((uint32_t*)&node->chars[i]);
        const uint32_t v = dword ^ packed_byte;

		if ((v & 0x000000ff) == 0) {
			return node->next[i + 0];
		}
		if ((v & 0x0000ff00) == 0) {
			return node->next[i + 1];
		}
		if ((v & 0x00ff0000) == 0) {
			return node->next[i + 2];
		}
		if ((v & 0xff000000) == 0) {
			return node->next[i + 3];
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
