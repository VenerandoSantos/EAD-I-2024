/*
Faça um programa que leia um vetor N[20]. Troque a seguir, o primeiro elemento com o último, o segundo elemento com o penúltimo, etc., até trocar o 10º com o 11º. Mostre o vetor modificado.

Entrada
A entrada contém 20 valores inteiros, positivos ou negativos.

Saída
Para cada posição do vetor N, escreva "N[i] = Y", onde i é a posição do vetor e Y é o valor armazenado naquela posição.
*/
#include <stdio.h>

int main()
{
    int N[20];
    int n=0,m=19,temp;
    for (int i=0;i<20;i++)
    {
        scanf("%d",&N[i]);
    }
    for (int i=0;i<10;i++)
    {
        
        temp = N[n];
        N[n]= N[m];
        N[m] = temp;
        m--;
        n++;
    }
    for (int i=0;i<20;i++)
    {
        printf("N[%d] = %d\n",i,N[i]);
    }

    return 0;
}
