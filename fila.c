/*
Com a proximidade da Copa do Mundo, o fluxo de pessoas nas filas para compra de ingressos aumentou consideravelmente. Como as filas estão cada vez maiores, pessoas menos pacientes tendem a desistir da compra de ingressos e acabam deixando as filas, liberando assim vaga para outras pessoas. Quando uma pessoa deixa a fila, todas as pessoas que estavam atrás dela dão um passo a frente, sendo assim nunca existe um espaço vago entre duas pessoas. A fila inicialmente contém N pessoas, cada uma com um identificador diferente. Joãozinho sabe o estado inicial dela e os identificadores em ordem das pessoas que deixaram a fila. Sabendo que após o estado inicial nenhuma pessoa entrou mais na fila, Joãozinho deseja saber o estado final da fila.

Entrada
A primeira linha contém um inteiro N (1 ≤ N ≤ 50000) representando a quantidade de pessoas inicialmente na fila. A segunda linha contém N inteiros representando os identificadores das pessoas na fila. O primeiro identificador corresponde ao identificador da primeira pessoa na fila. É garantido que duas pessoas diferentes não possuem o mesmo identificador. A terceira linha contém um inteiro M (1 ≤ M ≤ 50000 e M < N) representando a quantidade de pessoas que deixaram a fila. A quarta linha contém M inteiros representando os identificadores das pessoas que deixaram a fila (cada identificador está entre 1 e 100000), na ordem em que elas saíram. É garantido que um mesmo identificador não aparece duas vezes nessa lista.

Saída
Seu programa deve imprimir uma linha contedo N − M inteiros com os identificadores das pessoas que permaneceram na fila, em ordem de chegada.
*/

#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef struct fila {
    int N;
    struct fila *prox;
} Fila;

Fila* retira (Fila *P, int T ){
    int confirma = false;
    if (P == NULL){
        return P;
    }
    Fila *procura = P,*aux;
    do {
        aux = procura;
        procura = procura->prox;
        if (procura->N == T) confirma = true;
    } while (procura != P && procura->N != T); 
    if (confirma == true){
        if ( procura == P ) {
            aux-> prox = procura -> prox;
            free (procura);
            return aux;
        }
        aux->prox = procura->prox;
        free (procura);
    }
    
    return P;
 }

void imprimir (Fila* P){
    Fila *aux = P;
    do {
        aux = aux-> prox;
        printf("%d",aux->N);
        if (aux != P){
        printf(" ");
        }
    } while (P != aux );

    printf("\n");
    return;
}

Fila* InsereFila(Fila *P, int ticket){
    Fila* NOVO = (Fila*)malloc(sizeof(Fila));
    NOVO->N = ticket;
    if (P == NULL){
        NOVO->prox = NOVO; //fila circular
        return NOVO;
    }
    NOVO -> prox = P -> prox;
    P->prox = NOVO;
    return NOVO;
}

int main(void) {
  Fila* ultimoFila = NULL;
  int N_pessoasNaFila;
  int ticket;
  int quantidadeInicial = 0; 
  int quantidadeSaiu = 0;
  int N_pessoasSaiu;
  
  scanf("%d",&N_pessoasNaFila);

  while (quantidadeInicial < N_pessoasNaFila && scanf("%d",&ticket) == 1){
      ultimoFila = InsereFila(ultimoFila, ticket);
      quantidadeInicial++;
  }
  
  scanf("%d",&N_pessoasSaiu);
  
  while (quantidadeSaiu < N_pessoasSaiu && scanf("%d",&ticket) == 1){
      ultimoFila = retira (ultimoFila,ticket); 
      quantidadeSaiu++;
  }
  
  imprimir(ultimoFila);
  
  return 0;
}
