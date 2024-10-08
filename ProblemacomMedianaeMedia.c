/*
A média de três inteiros A, B e C é (A + B + C)/3. A mediana de três números inteiros seria então aquela que estaria no meio, se forem ordenados em ordem não decrescente. Dados dois números inteiros A e B, retornar o mínimo inteiro possível C, tal que a média e a mediana de A, B e C, sejam iguais.

Entrada
Cada caso de teste é dado em uma única linha que contém dois inteiros A e B (1 ≤ A ≤ B ≤ 109). O último caso de teste é seguido por uma linha contendo dois zeros.

Saída
Para cada caso de teste, imprima uma linha que contenha o mínimo inteiro possível C, de forma que a média e a mediana de A, B e C sejam iguais.
*/
#include <stdio.h>

int main(void) {
    int a, b;
    while (scanf("%d %d", &a, &b) == 2) {
        if (a == 0 && b == 0) break;
        printf("%d\n", 2 * a - b);
    }
    return 0;
}
