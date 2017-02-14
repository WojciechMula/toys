/************************************************************************

	Trie speedup - common trie functions

	author: Wojciech Muła
	e-mail: wojciech_mula@poczta.onet.pl
	last update: 2013-09-30

	license: simplifed BSD

************************************************************************/

#include "trie.h"

TrieNode* trie_new_node() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));

    node->eow   = false;
    node->n     = 0;
    node->chars = NULL;
    node->next  = NULL;

    return node;
}


int trie_add_word(TrieNode* root, const char* word, const size_t n) {
    size_t i;
    TrieNode* node = root;

    if (n == 0)
        return 0;

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
	return 1;
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


void trie_destroy(TrieNode* node) {
	for (size_t i=0; i < node->n; i++) {
		trie_destroy(node->next[i]);
	}

	if (node->n > 0) {
		free(node->next);
		free(node->chars);
	}

	free(node);
}


static void trie_statistics_init(trie_statistics_t* stats) {
	stats->node_count = 0;
	stats->word_count = 0;

	for (int i=0; i < 256; i++) {
		stats->word_length[i] = 0;
		stats->degree[i] = 0;
		stats->chars[i] = 0;
	}
}
	

static int trie_statistics_update(TrieNode* node, trie_statistics_t* stats, const int depth) {
	stats->node_count += 1;
	
	if (node->eow && depth < 256) {
		stats->word_count += 1;
		stats->word_length[depth] += 1;
	}

	if (node->n < 256) {
		stats->degree[node->n] += 1;
	}

	for (size_t i=0; i < node->n; i++) {
		stats->chars[(unsigned char)(node->chars[i])] += 1;
		if (trie_statistics_update(node->next[i], stats, depth+1)) {
			return 1;
		}
	}

	return 0;
}


int trie_statistics(TrieNode* root, trie_statistics_t* stats) {
	trie_statistics_init(stats);

	return trie_statistics_update(root, stats, 0);
}
