#ifndef UTILS_H
  #define UTILS_H

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

  void OpenFile(string fileName);

  string getFilePath();

#endif
