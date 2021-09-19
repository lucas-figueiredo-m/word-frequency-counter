#ifndef HEAP_H
  #define HEAP_H

  #include <stddef.h>
  #include <stdlib.h>
  #include <string>
  #include <stdio.h>
  #include <iostream>

  #define true 1
  #define false 0

  #define MAXHEAP 1
  #define MINHEAP 0

  using namespace std;

  typedef int boolean_t;

  typedef struct heap_data_t {
    string name;
    int prio;
  } heap_data_t;

  typedef struct heap_t {
    int amount;
    heap_data_t *data;
  } heap_t;

  class Heap {
    public:
      Heap(int size);
      boolean_t Insert (string name, int prio);
      boolean_t Remove ();
      void Print();
      boolean_t Read(string *str);

    private:
      heap_t *fp;
      int max;
      void Promote();
      void Demote();

  };

#endif
