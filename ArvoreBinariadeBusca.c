/*
Em computação, a árvores binária de busca ou árvore binária de pesquisa é uma estrutura baseada em nós (nodos), onde todos os nós da subárvore esquerda possuem um valor numérico inferior ao nó raiz e todos os nós da subárvore direita possuem um valor superior ao nó raiz (e assim sucessivamente). O objetivo desta árvore é estruturar os dados de forma flexível, permitindo a busca binária de um elemento qualquer da árvore.

A grande vantagem das árvores de busca binária sobre estruturas de dados convencionais é que os algoritmos de ordenação (percurso infixo) e pesquisa que as utilizam são muito eficientes.

Para este problema, você receberá vários conjuntos de números e a partir de cada um dos conjuntos, deverá construir uma árvore binária de busca. Por exemplo, a sequência de valores: 8 3 10 14 6 4 13 7 1 resulta na seguinte árvore binária de busca:



Entrada
A entrada contém vários casos de teste. A primeira linha da entrada contém um inteiro C (C ≤ 1000), indicando o número de casos de teste que virão a seguir. Cada caso de teste é composto por 2 linhas. A primeira linha contém um inteiro N (1 ≤ N ≤ 500) que indica a quantidade de números que deve compor cada árvore e a segunda linha contém N inteiros distintos e não negativos, separados por um espaço em branco.

Saída
Cada linha de entrada produz 3 linhas de saída. Após construir a árvore binária de busca com os elementos de entrada, você deverá imprimir a mensagem "Case n:", onde n indica o número do caso de teste e fazer os três percursos da árvore: prefixo, infixo e posfixo, apresentando cada um deles em uma linha com uma mensagem correspondente conforme o exemplo abaixo, separando cada um dos elementos por um espaço em branco.

Obs: Não deve haver espaço em branco após o último item de cada linha e há uma linha em branco após cada caso de teste, inclusive após o último.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int v;
   struct node *d, *e;
} lista;

lista *novo(int n) {
   lista *nv = (lista *) malloc(sizeof(lista));
   nv->v = n;
   nv->e = nv->d = 0;
   return nv;
}

void antes(lista *r) {
   if (r) {
      printf(" %d", r->v);
      antes(r->e);
      antes(r->d);
   }
}

void cria(lista *r) {
   if (r) {
      cria(r->e);
      printf(" %d", r->v);
      cria(r->d);
   }
}
void anda(lista *r) {
   if (r) {
      anda(r->e);
      anda(r->d);
      printf(" %d", r->v);
   }
}

void inserir(int n, lista *r) {
   if (n < r->v)
      if (r->e != NULL) inserir(n, r->e);
      else r->e = novo(n);
   else
      if (r->d != NULL) inserir(n, r->d);
      else r->d = novo(n);
}

int main(void) {
   int c, n, i, j, v;
   scanf("%d", &c);
   for (i = 1; i <= c; ++i) {
      scanf("%d", &n);
      scanf("%d", &v);
      lista *r = novo(v);
      for (j = 0; j < n-1; ++j) {
         scanf("%d", &v);
         inserir(v, r);
      }
      printf("Case %d:", i);
      printf("\nPre.:"); antes(r);
      printf("\nIn..:"); cria(r);
      printf("\nPost:"); anda(r);
      printf("\n\n");
   }

   return 0;
}
