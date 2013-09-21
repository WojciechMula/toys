#include "trie.h"

TrieNode* trie_next(TrieNode* node, const char letter) {
    size_t i;
    for (i = 0; i < node->n; i++) {
        if (node->chars[i] == letter) {
            return node->next[i];
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

