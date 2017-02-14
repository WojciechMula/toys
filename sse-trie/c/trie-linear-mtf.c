/************************************************************************

	Trie speedup - trie_next: linear search with move-to-front strategy

	author: Wojciech Muła
	e-mail: wojciech_mula@poczta.onet.pl
	last update: 2013-09-30

	license: simplifed BSD

************************************************************************/

#include "trie.h"

TrieNode* trie_next(TrieNode* node, const char letter) {
	for (size_t i = 0; i < node->n; i++) {
		if (node->chars[i] == letter) {
			if (i == 0) {
				return node->next[0];
			}

			char	  c0 = node->chars[0];
			TrieNode* n0 = node->next[0];

			node->chars[0] = letter;
			node->next[0]  = node->next[i];

			node->chars[i] = c0;
			node->next[i]  = n0;

			return node->next[0];
		}
	}

	return NULL;
}


void trie_add_link(TrieNode* node, TrieNode* newnode, const char letter) {
	node->n += 1;
	node->chars = (char*)realloc(node->chars, node->n);
	node->next  = (TrieNode**)realloc(node->next, sizeof(TrieNode*) * node->n);

	node->chars[node->n - 1] = letter;
	node->next [node->n - 1] = newnode;
}

