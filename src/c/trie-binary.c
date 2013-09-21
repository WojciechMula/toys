#include "trie.h"

static void sort_chars(TrieNode* node);

TrieNode* trie_next(TrieNode* node, const char letter) {
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
}


void trie_add_link(TrieNode* node, TrieNode* newnode, const char letter) {
    node->n += 1;
    node->chars = (char*)realloc(node->chars, node->n);
    node->next  = (TrieNode**)realloc(node->next, sizeof(TrieNode*) * node->n);

    node->chars[node->n - 1] = letter;
    node->next [node->n - 1] = newnode;

	sort_chars(node);
}


// insertion sort
static void sort_chars(TrieNode* node) {
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
}
