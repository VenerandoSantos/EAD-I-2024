/*
Leia 3 valores de ponto flutuante A, B e C e ordene-os em ordem decrescente, de modo que o lado A representa o maior dos 3 lados. A seguir, determine o tipo de triângulo que estes três lados formam, com base nos seguintes casos, sempre escrevendo uma mensagem adequada:

se A ≥ B+C, apresente a mensagem: NAO FORMA TRIANGULO
se A2 = B2 + C2, apresente a mensagem: TRIANGULO RETANGULO
se A2 > B2 + C2, apresente a mensagem: TRIANGULO OBTUSANGULO
se A2 < B2 + C2, apresente a mensagem: TRIANGULO ACUTANGULO
se os três lados forem iguais, apresente a mensagem: TRIANGULO EQUILATERO
se apenas dois dos lados forem iguais, apresente a mensagem: TRIANGULO ISOSCELES
Entrada
A entrada contem três valores de ponto flutuante de dupla precisão A (0 < A) , B (0 < B) e C (0 < C).

Saída
Imprima todas as classificações do triângulo especificado na entrada.

*/
#include <stdio.h>

int main()
{
    float A,B,C,D;
    //A=7,B=5,C=7;
    scanf("%f %f %f",&B,&C,&A);
    if (C>B){
        D = C;
        C = B;
        B = D;
    }
    if (B>A){
        D = B;
        B = A;
        A = D;
    }
    if (C>B){
        D = C;
        C = B;
        B = D;
    }
    //printf("%.2f %.2f %.2f",A,B,C);
    
    if (A>=B+C)
        printf("NAO FORMA TRIANGULO\n");
        
    else{
    if (A*A==B*B+C*C)
        printf("TRIANGULO RETANGULO\n");
        
    if (A*A>B*B+C*C)
        printf("TRIANGULO OBTUSANGULO\n");
        
    if (A*A<B*B+C*C)
        printf("TRIANGULO ACUTANGULO\n");
        
    if (A==B && B==C)
        printf("TRIANGULO EQUILATERO\n");
        
    else if (A==B || A==C || B==C)
        printf("TRIANGULO ISOSCELES\n");
        
    }
    return 0;
}
