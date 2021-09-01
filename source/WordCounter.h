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

  using namespace std;

  class WordCounter {

    public:
      WordCounter();

    private:
      void OpenFile();
  };

#endif
