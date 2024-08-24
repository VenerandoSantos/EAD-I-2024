/*
João está trabalhando em uma mina, tentando retirar o máximo que consegue de diamantes "<>". Ele deve excluir todas as particulas de areia "." do processo e a cada retirada de diamante, novos diamantes poderão se formar. Se ele tem como uma entrada .<...<<..>>....>....>>>., três diamantes são formados. O primeiro é retirado de <..>, resultando  .<...<>....>....>>>. Em seguida o segundo diamante é retirado, restando .<.......>....>>>. O terceiro diamante é então retirado, restando no final .....>>>., sem possibilidade de extração de novo diamante.

Entrada
Deve ser lido um valor inteiro N que representa a quantidade de casos de teste. Cada linha a seguir é um caso de teste que contém até 1000 caracteres, incluindo "<,>, ."

Saída
Você deve imprimir a quantidade de diamantes possíveis de serem extraídos em cada caso de entrada.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct pilha  {
     char c;
     struct pilha* prox;
} Pilha;

Pilha* desempilha(Pilha* P){
  Pilha* aux = P;
  P = P->prox;
  free(aux);
  return P;
}

Pilha* empilha (Pilha* P, char c ){
     Pilha* NOVO = (Pilha*)malloc(sizeof(Pilha));
     NOVO->c = c;
     
     if (P == NULL){
          NOVO->prox = NULL;
          return NOVO;
     }
     NOVO -> prox = P;
     return NOVO;
}

int main(void) {
     int N_testes;
     scanf("%d",&N_testes);
     int diamantes[N_testes];
     for (int i = 0 ; i < N_testes ; i++){
        diamantes[i] = 0 ;
     }
     
     /*para cada pedaço de '<' que ele encontrar, ele guardara na pilha e para cada '>' que ele encontrar, e retira a outra metade da pilha e contabiliza (diamante + 1) */
     for (int i = 0 ; i <  N_testes ; i++ ){
       char terra[1000];
       Pilha *P = NULL;
       scanf("%s",terra);
            for (int j = 0 ; terra[j] != '\0' ; j++){
                 if (terra[j] == '<'){
                      P = empilha(P,terra[j]);
                 }
                 if (terra[j] == '>' && P != NULL){
                      P = desempilha(P);
                      diamantes[i]++;
                 }   
            }
            
     }
     for (int i = 0 ; i < N_testes ; i++){
          printf("%d\n",diamantes[i]);
     }
     
     return 0;
}
