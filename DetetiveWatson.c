/*
John Watson, mesmo após anos trabalhando ao lado de Sherlock Holmes, nunca conseguiu entender como ele consegue descobrir quem é o assassino com tanta facilidade. Em uma certa noite, porém, Sherlock bebeu mais do que devia e acabou contando o segredo a John.

“Elementar, meu caro Watson”, disse Sherlock Holmes. “Nunca é o mais suspeito, mas sim o segundo mais suspeito”. Após descobrir o segredo, John decidiu resolver um crime por conta própria, só para testar se aquilo fazia sentido ou se era apenas conversa de bêbado.

Dada uma lista com N inteiros, representando o quanto cada pessoa é suspeita, ajude John Watson a decidir quem é o assassino, de acordo com o método citado.

Entrada
Haverá diversos casos de teste. Cada caso de teste inicia com um inteiro N (2 ≤ N ≤ 1000), representando o número de suspeitos.

Em seguida haverá N inteiros distintos, onde o i-ésimo inteiro, para todo 1 ≤ i ≤ N, representa o quão suspeita a i-ésima pessoa é, de acordo com a classificação dada por John Watson. Seja V o valor do i-ésimo inteiro, 1 ≤ V ≤ 10000.

O último caso de teste é indicado quando N = 0, o qual não deverá ser processado.

Saída
Para cada caso de teste imprima uma linha, contendo um inteiro, representando o indice do assassino, de acordo com o método citado.
*/
#include <stdio.h>

int main(void) {
    int n, i, j, s, x, a;
    int e[1000], f[1000];

    while (scanf("%d", &n) == 1 && n != 0) {
        for (i = 0; i < n; ++i) {
            scanf("%d", &e[i]);
            f[i] = e[i];
        }
        for (i = 0; i < n-1; ++i)
            for (j = i+1; j < n; ++j)
                if (f[i] > f[j]) {
                    x = f[i];
                    f[i] = f[j];
                    f[j] = x;
                }
        s = f[n-2];
        for (i = 0; i < n; ++i)
            if (s == e[i])
                a = i + 1;
        printf("%d\n", a);
    }
    return 0;
}
