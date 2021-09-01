#include <stddef.h>
#include <stdlib.h>

typedef struct NO* ArvAVL;

struct NO {
  int info;
  int alt;
  struct NO *esq;
  struct NO *dir;
};

ArvAVL *raiz;

int insere_ArvAVL(ArvAVL *raiz, int valor);