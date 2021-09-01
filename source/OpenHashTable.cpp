#include "OpenHashTable.h"

OpenHashTable::OpenHashTable (uint m) {
  length = m;
  hashList = (hash_element_t *) malloc(m * sizeof(hash_element_t));

  int i;
  for (i = 0; i < m; i++) {
    hashList[i].key = NULL;
    hashList[i].isDeleted = false;
  }
}

void OpenHashTable::Print() {
  int i;

  for (i = 0; i < length; i++) {
    if (hashList[i].isDeleted) {
      printf("[%d]: X\n", i);
    } else {
      if (hashList[i].key == NULL) {
        printf("[%d]: NULL\n", i);
      } else {
        printf("[%d]: %d\n", i, hashList[i].key);
      }
    }
    
  }
}

// void OpenHashTable::Print() {
//   int i;

//   for (i = 0; i < length; i++) {
//     if (hashList[i].isDeleted) {
//       printf("[%d]: X\n", i);
//     } else {
//       if (hashList[i].key == NULL) {
//         printf("[%d]: NULL\n", i);
//       } else {
//         printf("[%d]: %c\n", i, hashList[i].key);
//       }
//     }
    
//   }
// }

uint OpenHashTable::h1(uint k) {
  return k % length;
}

uint OpenHashTable::h2(uint k) {
  return (k % (length-1)) + 1;
}

uint OpenHashTable::h(uint k, uint i) {
  return (h1(k) + i * h2(k)) % length;
}

uint OpenHashTable::linearHash(uint k, uint i) {
  return (k + i) % length;
}

uint OpenHashTable::hash(uint k) {
  return k % length;
}

uint OpenHashTable::charHash1(char c) {
  return (int) (c-64) % length;
}

uint OpenHashTable::charHash2(char c) {
  return (int) 8 - ((c - 64) % 8);
}

uint OpenHashTable::charHash(char c, uint i) {
  return (charHash1(c) + i * charHash2(c)) % length;
}

void OpenHashTable::Insert(uint k) {
  int i;
  int index;

  for (i = 0; i < length; i++) {
    index = linearHash(k, i);
    if (hashList[index].key == NULL) {
      hashList[index].key = k;
      hashList[index].isDeleted = false;
      break;
    }
  }

  index = h(k, length - 1);
  if (i == length && hashList[index].key != k) {
    printf("Falha ao inserir o valor %d\nHashTable sem espaço disponível\n", k);
  }
}

void OpenHashTable::Remove(uint k) {
  int i;
  int index;

  for (i = 0; i < length; i++) {
    index = linearHash(k, i);
    if (hashList[index].key == k) {
      hashList[index].key = NULL;
      hashList[index].isDeleted = true;
      break;
    }
  }
}

// void OpenHashTable::Insert(char k) {
//   int index;

//   index = charHash1(k);
//   hashList[index].key = k;
//   hashList[index].isDeleted = false;
    
// }

// void OpenHashTable::Insert(char k) {
//   int i;
//   int index;

//   for (i = 0; i < length; i++) {
//     index = charHash(k, i);
//     if (hashList[index].key == NULL) {
//       hashList[index].key = k;
//       hashList[index].isDeleted = false;
//       break;
//     }
//   }

//   index = h(k, length - 1);
//   if (i == length && hashList[index].key != k) {
//     printf("Falha ao inserir o valor %d\nHashTable sem espaço disponível\n", k);
//   }
// }