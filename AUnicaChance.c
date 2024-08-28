/*Todo mundo sabe que as decisões que são tomadas fazem toda a diferença no resultado obtido. Um exemplo bastante conhecido é o paradoxo de Monty Hall, que é composto por três etapas e, na terceira, o concorrente dá a cartada final e, dependendo da sua escolha, pode ou não ganhar um carro.

Você deseja obter um “Accepted” e, para isso, terá que escrever um programa que verifique se uma única troca de posição entre duas letras resultará em uma sequência ordenada. Considere as seguintes sequências:

ABCDFGHIEJ

ABCDEFGHJIKLMNO

Para que a primeira sequência seja ordenada, é necessário mais de uma troca entre a posição das letras. Na segunda, por outro lado, basta que o I e o J mudem de posição. Sua missão é verificar se para cada sequência recebida existe uma única troca entre duas letras que a faça ordenada.

Entrada
A entrada é composta por um inteiro N, que representa a quantidade de casos de teste (1 <= N <= 100). Cada caso de teste é composto por um inteiro M, que representa a quantidade de letras de uma sequência (2 <= M <= 26) e por uma sequência alfabética composta por M letras. As letras são sempre maiúsculas e não se encontram em um índice superir a M. Caso M seja 4, as únicas letras possíveis para a sequência são: A, B, C ou D, em qualquer ordem. Todas as letras são distinstas, ou seja, não existem letras repetidas em cada sequencia alfabética.

Saída
Para cada sequência informada, o programa deve retornar uma única linha que apresentará “There are the chance.” se a sequência obedecer a regra de ordenação mencionada, ou “There aren't the chance.” caso contrário.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   short n, m, i, j, c, s;

   scanf("%hd", &n);
   for (j = 0; j < n; ++j) {
      scanf("%hd", &m);
      while (getchar() != '\n');
      c = 0;
      for (i = 0; i < m; ++i) {
         scanf("%c", &s);
         if (s != i+65)
            ++c;
      }
      printf((c == 2) ?
             "There are the chance.\n" :
             "There aren't the chance.\n");
   }

   return 0;
}
