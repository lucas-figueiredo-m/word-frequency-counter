#ifndef WORDCOUNTER_H
  #define WORDCOUNTER_H

  #include <iostream>
  #include <fstream>
  #include <string>
  #include <filesystem>
  #include <unistd.h>
  #include <stdio.h>
  #include <dirent.h>
  #include <sys/types.h>
  #include "utils.h"
  #include "heap.h"
  #include "hashlist.h"
  #include "trie.h"
  #include <sstream>

  using namespace std;

  class WordCounter {

    public:
      WordCounter(string filePath);
      void InsertListTime();
      Hashlist *list;
      Trie *tr;

    private:
      void OpenFile(string filePath);
      void InsertIntoStructure(string filepath, void (WordCounter::*)(string insertWord));
      void InsertIntoTrie(string filepath);

      void InsertIntoList (string word);

      void (WordCounter::*InsertFn) (string word);


  };

#endif
