#include "LinkedList.h"

LinkedList::LinkedList() {
  q->begin = NULL;
  q->end = NULL;
  q->size = 0;
}

void LinkedList::Insert (reg_t reg) {
  element_t *newElement = (element_t *) malloc(sizeof(element_t));
  newElement->reg = reg;
  newElement->next = NULL;

  if (q->begin == NULL) q->begin = newElement;
  else q->end->next = newElement;

  q->end = newElement;

}

void LinkedList::Print () {
  pointer_t end = q->begin;
  printf("Fila: \" ");
  while (end != NULL) {
    printf("v%i -> ", end->reg.key);
    end = end->next;
  }
  printf("FIM \"\n");
}

reg_t LinkedList::Search(reg_t reg) {
  return reg;
}

reg_t LinkedList::Delete(reg_t reg) {
  return reg;
}
