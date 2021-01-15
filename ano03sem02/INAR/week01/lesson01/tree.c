
#include <stdio.h>

#include <stdlib.h>

#include <time.h>

/* estrutura autorreferenciada */
struct noArvore {
  struct noArvore * ptrEsquerdo; /* ponteiro para subárvore esquerda */
  int dado; /* valor do nó */
  struct noArvore * ptrDireito; /* ponteiro para subárvore direita */
}; /* fim da estrutura noArvore */
typedef struct noArvore NoArvore; /* sinônimo para struct NoArvore */
typedef NoArvore * PtrNoArvore; /* sinônimo para NoArvore* */
/* protótipos */
void inserirNo(PtrNoArvore * ptrArvore, int valor);
void emOrdem(PtrNoArvore ptrArvore);
void preOrdem(PtrNoArvore ptrArvore);
void posOrdem(PtrNoArvore ptrArvore);

/* função main inicia execução do programa */
int main(void) {
  int i; /* contador para loop de 1 a 10 */
  int item; /* variável para manter valores aleatórios */
  PtrNoArvore rootPtr = NULL; /* árvore inicialmente vazia */
  srand(time(NULL));
  printf("Os números sendo colocados na árvore são:\n");
  /* insere valores aleatórios entre 0 e 14 na árvore */
  for (i = 1; i <= 10; i++) {
    item = rand() % 15;
    printf("%3d", item);
    inserirNo( & rootPtr, item);
  } /* fim laço for */
  /* busca a árvore preOrdem */
  printf("\n\nA travessia na pré-ordem é:\n");
  preOrdem(rootPtr);
  /* busca a árvore emOrdem */
  printf("\n\nA travessia na ordem é:\n");
  emOrdem(rootPtr);
  /* busca a árvore posOrdem */
  printf("\n\nA travessia na pós-ordem é:\n");
  posOrdem(rootPtr);
  printf("\n\n");
  return 0; /* indica conclusão bem-sucedida */
} /* fim do main */

/* insere nó na árvore */
void inserirNo(PtrNoArvore * ptrArvore, int valor) {
  /* se árvore estiver vazia */
  if ( * ptrArvore == NULL) {
    * ptrArvore = malloc(sizeof(NoArvore));
    /* se a memória foi alocada, então atribui dados */
    if ( * ptrArvore != NULL) {
      ( * ptrArvore) -> dado = valor;
      ( * ptrArvore) -> ptrEsquerdo = NULL;
      ( * ptrArvore) -> ptrDireito = NULL;
    }
    else {
      printf("%d não inserido. Não há memória disponível.\n", valor);
    }
  }
  else {
    /* árvore não está vazia */
    /* dado a inserir é menor que dado no nó atual */
    if (valor < ( * ptrArvore) -> dado) {
      inserirNo( & (( * ptrArvore) -> ptrEsquerdo), valor);
    }
    /* dado a inserir é maior que dado no nó atual */
    else if (valor > ( * ptrArvore) -> dado) {
      inserirNo( & (( * ptrArvore) -> ptrDireito), valor);
    }
    else {
      /* valor de dado duplicado é ignorado */
      printf("dup");
    }
  }
}

/* inicia travessia da árvore na ordem*/
void emOrdem(PtrNoArvore ptrArvore) {
  /* se árvore não está vazia, então busca */
  if (ptrArvore != NULL) {
    emOrdem(ptrArvore -> ptrEsquerdo);
    printf("%3d", ptrArvore -> dado);
    emOrdem(ptrArvore -> ptrDireito);
  }
}

/* inicia travessia da árvore na pré-ordem*/
void preOrdem(PtrNoArvore ptrArvore) {
  /* se a árvore não está vazia, então busca */
  if (ptrArvore != NULL) {
    printf("%3d", ptrArvore -> dado);
    preOrdem(ptrArvore -> ptrEsquerdo);
    preOrdem(ptrArvore -> ptrDireito);
  }
}

/* inicia travessia da árvore na pós-ordem */
void posOrdem(PtrNoArvore ptrArvore) {
  /* se a árvore não está vazia, então busca */
  if (ptrArvore != NULL) {
    posOrdem(ptrArvore -> ptrEsquerdo);
    posOrdem(ptrArvore -> ptrDireito);
    printf("%3d", ptrArvore -> dado);
  }
}