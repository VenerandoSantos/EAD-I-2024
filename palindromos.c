/*
Rener era um garoto que adorava palíndromos. Tanto que inventou um jogo com estes. Dada uma sequência de letras, quantas mais teriam que ser adicionadas, pelo menos, de modo que alguma permutação desta sequência formasse um palíndromo. Por exemplo, batata precisa adicionar um b no final, para virar o palíndromo batatab. Em outro exemplo, aabb, não precisa adicionar nenhuma letra, pois se faz o palíndromo abba ou baab. Em mais um exemplo, abc precisa de duas letras a mais, para formar um palíndromo, que pode ser abcba, acbca, bacab, bcacb, cabac ou cbabc. Escreva um programa que, dada uma sequência de letras, informe qual é o mínimo de letras que precisam ser adicionadas à sequência, para que haja, pelo menos, um anagrama que forme um palíndromo.

Entrada
Haverá diversos casos de teste. Em cada caso, é mostrada uma sequência de, no máximo, 1000 letras. Os casos de teste terminam com fim de arquivo.

Saída
Para cada caso de teste, imprima um valor inteiro, correspondente à quantidade mínima de letras a serem acrescentadas para que a sequência se torne um palíndromo, em uma de suas permutações.
*/

#include <stdio.h>
#include <string.h>

int main(void) {
    int valor = 0, count = 0;
    char v[1000];
    /*
    fará a leitura do arquivo até a ultima letra, onde q a cada letra repetida, eh descartado a letra e caso encontrado numero inpar, ele acrecenta mais uma unidade (valor + 1)
    */
    // Lê palavras até o final do arquivo (EOF)
    while (scanf("%s", v) != EOF) {
        for (int i = 0; v[i] != '\0'; i++) {
            count = 1;
            // Verifica caracteres repetidos
            for (int j = i + 1; v[j] != '\0'; j++) {
                if (v[i] == v[j]) {
                    // Remove caracteres repetidos
                    for (int k = j; v[k] != '\0'; k++) {
                        v[k] = v[k + 1];
                    }
                    j--;
                    count++;
                }
            }
            // Incrementa o contador se o número de ocorrências for ímpar
            if (count % 2 != 0) {
                valor++;
            }
        }
        // Imprime o resultado
        if (valor == 0) {
            printf("%d\n", valor);
        } else {
            printf("%d\n", valor - 1);
        }
    }
    printf("\n");

    return 0;
}
