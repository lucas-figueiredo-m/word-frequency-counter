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
  #include <sstream>

  using namespace std;

  class WordCounter {

    public:
      WordCounter(string filePath);

    private:
      void OpenFile(string filePath);
  };

#endif
