#include "trie.h"

Trie::Trie() {
  // root = (trie_node_t *) malloc(sizeof(trie_node_t));

  root = GetNode('/' - 'a');
}

trie_node_t *Trie::GetNode(int index) {
  trie_node_t *newnode = new trie_node_t;
  int i;

  newnode->val = 'a' + index;
  newnode->cnt = newnode->endsHere = 0;

  for (i = 0; i < DICT_LEN; i++)
    newnode->child[i] = NULL;

  return newnode;
}

void Trie::Insert (string word) {
  trie_node_t *curr = root;
  int index, i;

  for (i = 0; word[i] != '\0'; i++) {
    index = word[i] - 'a';
    if (curr->child[index] == NULL)
      curr->child[index] = GetNode(index);

    curr->child[index]->cnt += 1;
    curr = curr->child[index];
  }

  curr->endsHere += 1;
}

boolean_t Trie::Search (string word) {
  trie_node_t *curr = root;
  int index, i;

  for (i = 0; word[i] != '\0'; i++) {
    index = word[i] - 'a';
    
    if (curr->child[index] == NULL)
      return false;

    curr = curr->child[index];
  }

  return (curr->endsHere > 0);
}