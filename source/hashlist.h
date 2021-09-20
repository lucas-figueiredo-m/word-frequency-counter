#ifndef HASH_H
  #define HASH_H

  #include <iostream>
  #include <fstream>
  #include <string>
  #include <filesystem>
  #include <unistd.h>
  #include <stdio.h>
  #include <dirent.h>
  #include <sys/types.h>
  #include <iomanip>
  #include <functional>
  #include <unordered_set>
  using namespace std;

  typedef struct HeapNode_t {
    int prio;
    string info;
  } HeapNode_t;

  typedef struct HashNode_t {
    HashNode_t *next;
    HashNode_t *prev;
    uint count;
    string info;
  } HashNode_t;

  class Hashlist {

    public:
      Hashlist(uint m);
      void Insert(string word);
      void Print();
      int unrepeatedWords;
      int totalWords;

    private:
      uint length;
      HashNode_t **table;
      uint hashString(string k);
  };

#endif