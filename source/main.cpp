#include<string>
#include<iostream>

// #include "OpenHashTable.h"
// #include "LinkedList.h"
#include "AVLTree.h"

using namespace std;

int main() {

  AVLTree root;

  root.insert(1);
  root.insert(2);
  root.insert(3);
  root.insert(4);
  root.insert(5);

  root.print();

  printf("\n");

  // root.search(5);



  return 0;
}
