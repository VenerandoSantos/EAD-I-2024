/*
Com base na tabela abaixo, escreva um programa que leia o código de um item e a quantidade deste item. A seguir, calcule e mostre o valor da conta a pagar.



Entrada
O arquivo de entrada contém dois valores inteiros correspondentes ao código e à quantidade de um item conforme tabela acima.

Saída
O arquivo de saída deve conter a mensagem "Total: R$ " seguido pelo valor a ser pago, com 2 casas após o ponto decimal.
*/
#include <stdio.h>

int main()
{
    int item,quantI;
    scanf("%d %d",&item,&quantI);
    float quantF = quantI*1;
    switch(item){
        case 1:
            printf("Total: R$ %.2f\n",quantF*4);
            break;
        
        case 2:
            printf("Total: R$ %.2f\n",quantF*4.5);
            break;
        
        case 3:
            printf("Total: R$ %.2f\n",quantF*5);
            break;
        
        case 4:
            printf("Total: R$ %.2f\n",quantF*2);
            break;
        
        case 5:
            printf("Total: R$ %.2f\n",quantF*1.5);
            break;
        
        
    }
    return 0;
}
