#ifndef AVL_TREE_H
  #define AVL_TREE_H

  #include "common.h"

  typedef struct Node {
    key_type_t key;
    int height;
    Node *left;
    Node *right;
  } Node;

  class AVLTree {
    Node *raiz;

    public:
      AVLTree();
      Node* search(key_type_t key);
      void print();
      void insert(key_type_t valor);
  };

#endif