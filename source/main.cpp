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
  // filePath = "/Users/lucasfigueiredo/Dropbox/Mestrado DCC/2º Trimestre/AED/Trabalho final/teste.txt";

  filePath = getFilePath();
  // cout << filePath << endl;
  WordCounter Counter(filePath);

  // Hashlist hashlist(20);
  // hashlist.Insert("Lorem");
  // hashlist.Insert("Ipsum");
  // hashlist.Insert("Lorem");
  // hashlist.Insert("Lorem");
  // hashlist.Insert("Lorem");
  // hashlist.Insert("sit");
  // hashlist.Insert("sit");
  // hashlist.Insert("dolor");
  // hashlist.Insert("amet");
  // hashlist.Print();


  return 0;
}
