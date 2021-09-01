#include "ArvoreAVL.h"

int alt_NO(struct NO* no) {
  if (no == NULL) return -1;
  else return no->alt;
}

int fatorBalancemaneto_NO(struct NO *no) {
  return labs(alt_no(no->esq) - alt_NO(no->dir));
}

int maior (int x, int y) {
  if (x > y) return x;
  else return y;
}

// ArvAVL *raiz -> nó desbalanceado
void RotacaoLL (ArvAVL *raiz) {
  struct NO *no;
  no = (*raiz)->esq;
  (*raiz)->esq = no->dir;
  no->dir = *raiz;
  (*raiz)->alt = maior( alt_NO((*raiz)->esq),
                        alt_NO((*raiz)->dir)) + 1;
  
  no->alt = maior( alt_NO(no->esq), (*raiz)->alt) + 1;

  *raiz = no;
}

void RotacaoRR (ArvAVL *raiz) {
  struct NO *no;
  no = (*raiz)->dir;
  (*raiz)->dir = no->esq;
  no->esq = *raiz;
  (*raiz)->alt = maior( alt_NO((*raiz)->esq),
                        alt_NO((*raiz)->dir)) + 1;
  
  no->alt = maior( alt_NO(no->dir), (*raiz)->alt) + 1;

  *raiz = no;
}

void RotacaoLR (ArvAVL *raiz) {
  RotacaoRR(&(*raiz)->esq);
  RotacaoLL(raiz);
}

void RotacaoRL (ArvAVL *raiz) {
  RotacaoLL(&(*raiz)->dir);
  RotacaoRR(raiz);
}

int insere_ArvAVL(ArvAVL *raiz, int valor) {
  int res;
  if (*raiz == NULL) { // arvore vazia ou nó folha
    struct NO *novo;
    novo = (struct no*) malloc(sizeof(struct NO));
    if (novo == NULL)
      return 0;
    
    novo->info = valor;
    novo->alt = 0;
    novo->esq = NULL;
    novo->dir = NULL;
    *raiz = novo;

    return 1;
  }

  struct NO *atual = *raiz;

  if (valor < atual->info) {
    if ( (res = insere_ArvAVL(&(atual->esq), valor)) == 1 ) {
      if (fatorBalancemaneto_NO(atual) >= 2) {
        if (valor < (*raiz)->esq->info ) {
          RotacaoLL(raiz);
        } else {
          RotacaoLR(raiz);
        }
      }
    }
  } else {
    if (valor > atual->info) { // desnecessário
      if ( (res = insere_ArvAVL(&(atual->dir), valor)) == 1) {
        if (fatorBalancemaneto_NO(atual) >= 2) {
          if ( (*raiz)->dir->info < valor) {
            RotacaoRR(raiz);
          } else {
            RotacaoRL(raiz);
          }
          
        }
      }
    } else {
      printf("Valor duplicado!!\n");
      return 0;
    }
  }

  atual->alt = maior(alt_NO(atual->esq), alt_NO(atual->dir)) + 1;

  return res;
}