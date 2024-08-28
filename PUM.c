/*
Escreva um programa que leia um valor inteiro N. Este N é a quantidade de linhas de saída que serão apresentadas na execução do programa.

Entrada
O arquivo de entrada contém um número inteiro positivo N.

Saída
Imprima a saída conforme o exemplo fornecido.
*/

#include <stdio.h>
 
#include <stdio.h>

int main(){
    int i,seq,j=0,t=1;
    scanf("%d",&seq);
    for (j=1;j<=seq;j++){
        for (i=1;i<=4;i++){
            if (i%4==0){
                printf("PUM\n");
            }
            else
                printf("%d ",t);
            t++;
        }
    }
    return 0;
}
