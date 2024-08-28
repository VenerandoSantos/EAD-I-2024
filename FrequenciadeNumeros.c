/*
Neste problema sua tarefa será ler vários números e em seguida dizer quantas vezes cada número aparece na entrada de dados, ou seja, deve-se escrever cada um dos valores distintos que aparecem na entrada por ordem crescente de valor.

Entrada
A entrada contém apenas 1 caso de teste. A primeira linha de entrada contem um único inteiro N, que indica a quantidade de valores que serão lidos para X (1 ≤ X ≤ 2000) logo em seguida. Com certeza cada número não aparecerá mais do que 20 vezes na entrada de dados.

Saída
Imprima a saída de acordo com o exemplo fornecido abaixo, indicando quantas vezes cada um deles aparece na entrada por ordem crescente de valor.
*/
#include <stdio.h>

int main(void) {
    int q, i, n;
    int lista[2000];

    for (i = 0; i < 2000; ++i)
        lista[i] = 0;

    scanf("%d", &q);
    for (i = 0; i < q; ++i) {
        scanf("%d", &n);
        ++lista[n-1];
    }

    for (i = 0; i < 2000; ++i)
        if (lista[i] != 0)
        printf("%d aparece %d vez(es)\n", i+1, lista[i]);
    return 0;
}
