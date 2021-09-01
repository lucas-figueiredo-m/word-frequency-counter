#include "utils.h"

void OpenFile(string fileName) {
  string line;
  fstream file;
  file.open(fileName.append(".txt"));

  if (file.is_open()) {
    while (getline(file, line) ) {
      cout << line << "\n";
    }

    file.close();
  }
}