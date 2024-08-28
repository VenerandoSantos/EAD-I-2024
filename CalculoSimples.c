/*
Neste problema, deve-se ler o código de uma peça 1, o número de peças 1, o valor unitário de cada peça 1, o código de uma peça 2, o número de peças 2 e o valor unitário de cada peça 2. Após, calcule e mostre o valor a ser pago.

Entrada
O arquivo de entrada contém duas linhas de dados. Em cada linha haverá 3 valores, respectivamente dois inteiros e um valor com 2 casas decimais.

Saída
A saída deverá ser uma mensagem conforme o exemplo fornecido abaixo, lembrando de deixar um espaço após os dois pontos e um espaço após o "R$". O valor deverá ser apresentado com 2 casas após o ponto.
*/
#include <iostream>
 
using namespace std;
 
int main() {

    int i , peca[2] , unidade[2] ;
    float valor[2] ,  total = 0;

    scanf ("%d %d %f %d %d %f",&peca[0] , &unidade[0] , &valor[0],&peca[1] , &unidade[1] , &valor[1] );   
    

    total = unidade[0] * valor[0] + unidade[1] * valor[1];
    
    
    printf ("VALOR A PAGAR: R$ %.2f\n",total) ; 
    return 0;
}
