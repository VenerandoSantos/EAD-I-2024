/*
Leia os quatro valores correspondentes aos eixos x e y de dois pontos quaisquer no plano, p1(x1,y1) e p2(x2,y2) e calcule a distância entre eles, mostrando 4 casas decimais, segundo a fórmula:

Distancia =

Entrada
O arquivo de entrada contém duas linhas de dados. A primeira linha contém dois valores de ponto flutuante: x1 y1 e a segunda linha contém dois valores de ponto flutuante x2 y2.

Saída
Calcule e imprima o valor da distância segundo a fórmula fornecida, considerando 4 casas decimais.
*/
#include <iostream>
#include <math.h>
 
using namespace std;
 
int main() {
    int i;
    float x[2] , y[2],resul;
    for ( i = 0 ; i < 2 ; i++){
        scanf("%f %f" , &x[i] , &y[i]);
    }
    resul = sqrt ( pow ( x[1] - x[0] , 2) + pow ( y[1] - y[0] , 2)  );
    printf("%.4f\n",resul);
    return 0;
}
