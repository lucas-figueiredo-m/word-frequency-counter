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
  #include <sstream>

  using namespace std;

  class WordCounter {

    public:
      WordCounter(string filePath);
      void InsertListTime();

    private:
      void OpenFile(string filePath);
      void InsertIntoList(string filepath);
      void InsertIntoTrie(string filepath);


      Hashlist *list;
  };

#endif
