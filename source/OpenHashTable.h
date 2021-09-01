#ifndef LINKEDLIST_H
  #define LINKEDLIST_H

  #include "common.h"

  // typedef struct hash_element_t {
  //   int key;
  //   boolean_t isDeleted;
  // } hash_element_t;

  typedef struct hash_element_t {
    char key;
    boolean_t isDeleted;
  } hash_element_t;

  class OpenHashTable {

    uint length;

    hash_element_t *hashList;


    public:
      OpenHashTable(uint m);
      void Print();
      void Insert(uint key);
      void Remove(uint key);
      // void Insert(char key);

    private:
      uint h1(uint k);
      uint h2(uint k);
      uint h(uint k, uint i);
      uint linearHash(uint k, uint i);

      uint hash(uint k);
      uint charHash1(char c);
      uint charHash2(char c);
      uint charHash(char c, uint i);

  };



#endif