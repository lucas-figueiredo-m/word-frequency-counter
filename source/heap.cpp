#include "heap.h"

Heap::Heap(int size) {
  fp = (heap_t *) malloc(sizeof(heap_t));
  max = size;
  fp->amount = 0;
  fp->data = (heap_data_t *) malloc(size * sizeof(heap_data_t));
}

void Heap::Print() {
  int i;

  cout << "Priority: \" ";
  for (i = 0; i < fp->amount; i++) {
    if ( fp->data[i].prio != NULL )
      cout << fp->data[i].name << "(" << fp->data[i].prio << ") -> ";
    else
      cout << "NULL -> ";
  }
  cout << "FIM \"" << endl;
}

void Heap::Promote() {
  int father, son;
  heap_data_t temp;

  son = fp->amount;

  father = (fp->amount - 1) / 2;

  while ( (son > 0) && (fp->data[father].prio <= fp->data[son].prio) ) {
    temp = fp->data[son];
    fp->data[son] = fp->data[father];
    fp->data[father] = temp;

    son = father;
    father = (father - 1) / 2;
  }
}

boolean_t Heap::Insert (string name, int prio) {
  if (fp == NULL)
    return false;

  if (fp->amount == max)
    return false;

  fp->data[fp->amount].name.assign(name);
  fp->data[fp->amount].prio = prio;
  Promote();
  fp->amount++;

  return true;
  
}

void Heap::Demote () {
  heap_data_t temp;

  int father = 0;
  int son = 2 * father + 1;

  while (son < fp->amount) {
    // Pai tem 2 filhos? quem e maior?
    if (son < fp->amount - 1)
      if (fp->data[son].prio < fp->data[son + 1].prio)
        son++;

    // pai >= filho? terminar processo
    if (fp->data[father].prio >= fp->data[son].prio)
      break;

    // Troca pai e filho de lugar ecalcular novo filho
    temp = fp->data[father];
    fp->data[father] = fp->data[son];
    fp->data[son] = temp;

    father = son;

    son = 2 * father + 1;
  }
}

boolean_t Heap::Remove () {
  if (fp == NULL)
    return false;
  
  if (fp->amount == 0)
    return false;

  fp->amount--;
  fp->data[0] = fp->data[fp->amount];
  Demote();

  return true;
}

boolean_t Heap::Read(string *str) {
  if (fp == NULL || fp->amount == 0)
    return false;

  str->assign(fp->data[0].name);

  return true;
}
