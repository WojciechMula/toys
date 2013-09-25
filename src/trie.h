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


typedef struct trie_statistics_t {
	size_t node_count;
	size_t word_count;
	size_t word_length[256];	// histogram of word length
	size_t degree[256];			// histogram of node's degree
	size_t chars[256];			// histogram of chars
} trie_statistics_t;


TrieNode* trie_new_node();
int trie_add_word(TrieNode* root, const char* word, const size_t n);
bool trie_lookup(TrieNode* root, char* word);
int trie_statistics(TrieNode* root, trie_statistics_t* stats);

// implementation defined
void trie_add_link(TrieNode* node, TrieNode* newnode, const char letter);
TrieNode* trie_next(TrieNode* node, const char letter);

#endif
