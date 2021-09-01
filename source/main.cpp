#include<string>
#include<iostream>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

// #include "utils.h"
#include "WordCounter.h"
#include "utils.h"

using namespace std;


int main() {

  // list_dir("folder");
  string filePath;
  filePath = getFilePath();
  WordCounter Counter(filePath);

  // string a = "aaad", b = "aacd";

  // if (a < b) {
  //   cout << "a vem primeiro" << endl;
  // } else {
  //   cout << "b vem primeiro" << endl;
  // }

  return 0;
}
