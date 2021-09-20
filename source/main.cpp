#include<string>
#include<iostream>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

// #include "utils.h"
#include "WordCounter.h"
#include "utils.h"

using namespace std;

// void display(void (*p)(int num));
// void print_numbers(int num);

// void display(void (*p)(int num)) {  
//     for(int i=1;i<=5;i++)  
//     {  
//         p(i);  
//     }  
// }  

// void print_numbers(int num) {  
//     cout<<num;  
// }

// int main() {  

//   printf("The values are :");  
//   display(print_numbers);  
//   return 0;  
// }  


int main() {

  // list_dir("folder");

  string filePath;
  // // filePath = "/Users/lucasfigueiredo/Dropbox/Mestrado DCC/2º Trimestre/AED/Trabalho final/teste.txt";

  filePath = getFilePath();
  // // cout << filePath << endl;
  WordCounter Counter(filePath);

  // Counter.InsertListTime();
  // Counter.InsertTrieTime();


  // fstream file;
  // file.open("teste.csv", ios::out | ios::trunc);
  // file << "1,2,3" << "\n";
  // file << "4,5,6" << "\n";
  // file << "7,8,9" << "\n";
  // file.close();


  return 0;
}
