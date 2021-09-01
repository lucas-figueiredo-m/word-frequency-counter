#include "AVLTree.h"

AVLTree::AVLTree() {
  raiz = NULL;
}

Node* searchKey(key_type_t key, Node* node) {
  if (node == NULL)
    return NULL;
  
  if (node->key == key)
    return node;
  
  if (node->key > key)
    return searchKey(key, node->left);

  return searchKey(key, node->right);
}

Node* AVLTree::search(key_type_t key) {
  return searchKey(key, raiz);
}

int nodeHeight(Node* no) {
  if (no == NULL) return -1;
  else return no->height;
}

int fatorBalancemaneto_NO(Node *no) {
  return labs(nodeHeight(no->left) - nodeHeight(no->right));
}

int max (int x, int y) {
  if (x > y) return x;
  else return y;
}

Node *direita(Node *r) {
	Node *aux;
	aux = r->left;
	r->left = aux->right;
	aux->right = r;

	r->height = max(nodeHeight(r->right),nodeHeight(r->left)) +1;
	aux->height = max(nodeHeight(aux->left),r->height) +1;
	return(aux);
}

Node *esquerda(Node *r) {
	Node *aux;
	aux = r->right;
	r->right = aux->left;
	aux->left = r;

	r->height = max(nodeHeight(r->right),nodeHeight(r->left)) +1;
	aux->height = max(nodeHeight(aux->right),r->height) +1;
	return(aux);
}

Node *esquerdaDireita(Node *r) {
	r->left = esquerda(r->left);
	return(direita(r));
}


Node *direitaEsquerda(Node *r) {
	r->right = direita(r->right);
	return(esquerda(r));
}

Node *createNode(key_type_t ch){
	Node *novoNo = (Node*)malloc(sizeof(Node));
	novoNo->left = NULL;
	novoNo->right = NULL;
	novoNo->key = ch;
	novoNo->height = 0;
	return(novoNo);
}

Node *insertKey(Node *root, key_type_t ch) {
	if (!root) return(createNode(ch));
	// existe uma árvore
	if (ch < root->key) {
		root->left = insertKey(root->left,ch);
		// verifica se desbalanceou
		if ((nodeHeight(root->left) - nodeHeight(root->right)) == 2) {
			// se inseriu à esquerda, left-right só pode dar +2, se desbalanceado
			if (ch < root->left->key) {
				// incluiu à esquerda do filho da esquerda
				root = direita(root);
			}
			else {
				// incluiu à direita do filho da esquerda
				root = esquerdaDireita(root);
			}
		}
		// se não for 2, está ok, é AVL
	}
	else {
		if (ch > root->key) {
			root->right = insertKey(root->right, ch);
			if ((nodeHeight(root->right) - nodeHeight(root->left)) == 2) {
				// se inseriu à direita, right-left só pode dar +2, se desbalanceado
				if (ch > root->right->key) {
					// incluiu à direita do filho da direita
					root = esquerda(root);
				}
				else {
					// incluiu à esquerda do filho da direita
					root = direitaEsquerda(root);
				}
			}
		}
		// ignoro se igual a key
	}
	root->height = max(nodeHeight(root->left),nodeHeight(root->right))+1;
	return(root);
}

void AVLTree::insert(key_type_t valor) {
  raiz = insertKey(raiz, valor);
}

void printTree (Node *root) {
  if (root != NULL) {
    printf("%i[%i]", root->key, root->height);
    printf("(");
    printTree(root->left);
    printTree(root->right);
    printf(") ");
  }
}

void AVLTree::print() {
  printTree(raiz);
}