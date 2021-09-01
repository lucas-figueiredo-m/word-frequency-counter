
#define LINKEDLIST_H

#include "common.h"

typedef int key_type_t;

typedef struct reg_t {
  key_type_t key;
  // outros campos
} reg_t;

typedef struct element_t {
  reg_t reg;
  struct element_t *next;
} element_t, *pointer_t;

typedef struct queue_t {
  pointer_t begin; // Equivalente ao lado1. 
  pointer_t end;   // Equivalente do lado2.
  int size;
} queue_t;


class LinkedList {

  queue_t *q;

  public:
    LinkedList();
    void Insert(reg_t reg);
    reg_t Search(reg_t reg);
    reg_t Delete(reg_t reg);
    void Print();
};
