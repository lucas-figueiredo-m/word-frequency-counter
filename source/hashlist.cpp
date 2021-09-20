#include "hashlist.h"

Hashlist::Hashlist(uint m) {
  length = m;
  unrepeatedWords = 0;
  totalWords = 0;
  table = (HashNode_t **) malloc(m * sizeof(HashNode_t));
}

uint Hashlist::hashString (string k) {
  hash<string> h1;
  size_t h = h1(k);
  return (uint) (h % length);
}

void Hashlist::Insert(string word) {
  uint h = hashString( word );

  HashNode_t *newNode = (HashNode_t *) malloc( 4*sizeof(HashNode_t) );
  newNode->count = 1;
   
  newNode->info.assign( word );
  totalWords += 1;
  
  if ( table[h] == nullptr) {
    newNode->next = nullptr;
    table[h] = newNode;
    unrepeatedWords += 1;
  } else {
    HashNode_t *node = table[h];
    while (node != nullptr) {
      if (node->info == newNode->info){
        node->count += 1;
        break;
      } 
      node = node->next;
    }

    if (node == nullptr) {
      newNode->next = table[h];
      table[h] = newNode;
      unrepeatedWords += 1;
    }
  }
}

void Hashlist::Print() {
  uint i;
  HashNode_t *aux;
  for (i = 0; i < length; i++) {
    printf("[%d] -> ", i);
    aux = table[i];

    while (aux != nullptr) {
      printf("%s(%d) ->  ", aux->info.c_str(), aux->count);
      aux = aux->next;
    }

    printf("NULL\n");
  }
  printf("\nWords: %d\n", unrepeatedWords);
}
