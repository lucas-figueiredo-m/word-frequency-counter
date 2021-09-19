#ifndef TRIE_H
  #define TRIE_H

  #include <stddef.h>
  #include <stdlib.h>
  #include <string>
  #include <stdio.h>
  #include <iostream>

  #define true 1
  #define false 0
  #define DICT_LEN 26

  using namespace std;

  typedef int boolean_t;
  
  typedef struct trie_node_t {
    char val;
    int cnt;
    int endsHere;
    trie_node_t *child[DICT_LEN];
  } trie_node_t;

  class Trie {

    public:
      Trie();
      void Insert (string word);
      boolean_t Search (string word);

    private:
      trie_node_t *root;
      trie_node_t *GetNode(int index);
  };

#endif