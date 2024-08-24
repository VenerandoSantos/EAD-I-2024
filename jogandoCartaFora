/*Dada uma pilha de n cartas enumeradas de 1 até n com a carta 1 no topo e a carta n na base.  A seguinte operação é ralizada enquanto tiver 2 ou mais cartas na pilha.

Jogue fora a carta do topo e mova a próxima carta (a que ficou no topo) para a base da pilha.

Sua tarefa é encontrar a sequência de cartas descartadas e a última carta remanescente.

Cada linha de entrada (com exceção da última) contém um número n ≤ 50. A última linha contém 0 e não deve ser processada. Cada número de entrada produz duas linhas de saída. A primeira linha apresenta a sequência de cartas descartadas e a segunda linha apresenta a carta remanescente.

Entrada
A entrada consiste em um número indeterminado de linhas contendo cada uma um valor de 1 até 50. A última linha contém o valor 0.

Saída
Para cada caso de teste, imprima duas linhas. A primeira linha apresenta a sequência de cartas descartadas, cada uma delas separadas por uma vírgula e um espaço. A segunda linha apresenta o número da carta que restou. Nenhuma linha tem espaços extras no início ou no final. Veja exemplo para conferir o formato esperado.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
     int N;
     struct pilha *prox;
} Pilha;

Pilha *insere(Pilha *p, int A) {

     Pilha *NOVO = (Pilha *)malloc(sizeof(Pilha));
     NOVO -> N = A;
     if (p == NULL) {
               NOVO->prox = NOVO;
               return NOVO;
     }
     NOVO->prox = p->prox;
     p->prox = NOVO;
     return NOVO;
}


Pilha *remover(Pilha *u) {
     Pilha *lixo = u->prox;
     if (u == NULL)
          return u;
     if (u->prox == u) {
          free(u);
          return NULL;
     }
     u->prox = lixo->prox;
     free(lixo);
     return u;
}

int main(void) {
     int verifica;
     scanf("%d", &verifica);

     while (verifica != 0) {
          Pilha *ultimoBaralho = NULL;
          // Pilha* ultimodescarta = NULL;
          for (int i = 1; i <= verifica; i++) {
               ultimoBaralho = insere(ultimoBaralho, i);
          }
          printf("Discarded cards:");
          for (; ultimoBaralho->prox != ultimoBaralho;) {
               printf(" %d", ultimoBaralho->prox->N);
               ultimoBaralho = remover(ultimoBaralho);
               ultimoBaralho = ultimoBaralho->prox;
               if (ultimoBaralho->prox != ultimoBaralho) {
                    printf(",");
               }
          }
          printf("\nRemaining card: %d\n", ultimoBaralho->N);
          scanf("%d", &verifica);
     }

     return 0;
}
