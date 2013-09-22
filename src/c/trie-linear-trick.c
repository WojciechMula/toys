#include "trie.h"

TrieNode* trie_next(TrieNode* node, const char letter) {
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


void trie_add_link(TrieNode* node, TrieNode* newnode, const char letter) {
    node->n += 1;
    node->chars = (char*)realloc(node->chars, node->n);
    node->next  = (TrieNode**)realloc(node->next, sizeof(TrieNode*) * node->n);

    node->chars[node->n - 1] = letter;
    node->next [node->n - 1] = newnode;
}
