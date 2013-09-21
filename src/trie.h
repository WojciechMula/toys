#ifndef trie_h_included__
#define trie_h_included__

#include <stdint.h>
#include <stdlib.h>

#define false 0
#define true  1
#define bool  int

typedef struct TrieNode* PTrieNode;
typedef struct TrieNode {
    char        eow;         // end of word
    size_t      n;           // elements in buffer
    char*       chars;       // n chars
    PTrieNode*  next;        // n pointers
} TrieNode;


TrieNode* trie_new_node();
void trie_add_word(TrieNode* root, const char* word, const size_t n);
bool trie_lookup(TrieNode* root, char* word);

// implementation defined
void trie_add_link(TrieNode* node, TrieNode* newnode, const char letter);
TrieNode* trie_next(TrieNode* node, const char letter);

#endif
