#include "trie.h"

TrieNode* trie_new_node() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));

    node->eow   = false;
    node->n     = 0;
    node->chars = NULL;
    node->next  = NULL;

    return node;
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
