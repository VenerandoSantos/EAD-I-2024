/*
Leia um valor inteiro. A seguir, calcule o menor número de notas possíveis (cédulas) no qual o valor pode ser decomposto. As notas consideradas são de 100, 50, 20, 10, 5, 2 e 1. A seguir mostre o valor lido e a relação de notas necessárias.

Entrada
O arquivo de entrada contém um valor inteiro N (0 < N < 1000000).

Saída
Imprima o valor lido e, em seguida, a quantidade mínima de notas de cada tipo necessárias, conforme o exemplo fornecido. Não esqueça de imprimir o fim de linha após cada linha, caso contrário seu programa apresentará a mensagem: “Presentation Error”.
*/

#include <iostream>
 
using namespace std;
 
int main()
{
    int N;
    scanf("%d",&N);
    int n100,n50,n20,n10,n5,n2,n1;
    n100 = N/100;
    n50 = (N-(n100*100))/50;
    n20 = (N-(n100*100)-(n50*50))/20;
    n10 = (N-(n100*100)-(n50*50)-(n20*20))/10; 
    n5 = (N-(n100*100)-(n50*50)-(n20*20)-(n10*10))/5;
    n2 = (N-(n100*100)-(n50*50)-(n20*20)-(n10*10)-(n5*5))/2;
    n1 = (N-(n100*100)-(n50*50)-(n20*20)-(n10*10)-(n5*5))%2;
    printf("%d\n%d nota(s) de R$ 100,00\n%d nota(s) de R$ 50,00\n%d nota(s) de R$ 20,00\n%d nota(s) de R$ 10,00\n%d nota(s) de R$ 5,00\n%d nota(s) de R$ 2,00\n%d nota(s) de R$ 1,00\n",N,n100,n50,n20,n10,n5,n2,n1);

    return 0;
}
