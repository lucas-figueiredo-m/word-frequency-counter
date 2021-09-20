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
  // // filePath = "/Users/lucasfigueiredo/Dropbox/Mestrado DCC/2º Trimestre/AED/Trabalho final/teste.txt";

  filePath = getFilePath();
  // // cout << filePath << endl;
  WordCounter Counter(filePath);

  Counter.InsertListTime();
  // Counter.InsertTrieTime();


  // fstream file;
  // file.open("teste.csv", ios::out | ios::trunc);
  // file << "1,2,3" << "\n";
  // file << "4,5,6" << "\n";
  // file << "7,8,9" << "\n";
  // file.close();


  return 0;
}
