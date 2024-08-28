/*
Sam encontrou um conjunto de mapas do velho Meistre Aemon que, a princípio, deviam mostrar, cada um, a localização de um baú com obsidiana. Entretanto, ao analisar, Sam percebeu que alguns mapas possuíam erros óbvios, e outros só mandando uma equipe para explorar para saber.

É certo que alguns mapas apontam para uma localização absurda fora do mapa e alguns terminam em círculos, tornando estes mapas completamente inúteis.

Como são muitos mapas, os irmãos da patrulha da noite são poucos e o inverno está chegando, o seu trabalho é fazer um programa para verificar se um mapa leva ou não a um ponto com um baú de obsidiana.

Os mapas tem as seguintes características:

O ponto de partida de todos os mapas é o canto superior esquerdo.

São retangulares e em cada ponto apresenta um destes símbolos:

Um espaco de terreno atravessável.

Uma flecha, representando uma possível troca de direção;

Um baú.

Como os lugares que estes mapas descrevem são cheios de perigos, é vital que se siga o caminho descrito no mapa.

Entrada
Na primeira linha, está um inteiro positivo x < 100 que simboliza a largura do mapa.

Na segunda linha, está um inteiro positivo y < 100 que simboliza a altura do mapa.

As linhas seguintes contêm diversos caracteres respeitando as dimensões do mapa.
Os caracteres válidos são:

Uma flecha para a direita: >

Uma flecha para a esquerda: <

Uma flecha para baixo: v

Uma flecha para cima: ^

Um espaco de terreno atravessável: .

Um baú: *
Saída
A saída deve consistir de uma única linha com um único caracter ! ou *.

! significa que o mapa é inválido. * significa que o mapa é válido.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char mapa[105][105], ant;
    int x = 0, y = 0, i = 0, j = 0;
    int bau = 0;

    scanf("%d %d", &x, &y);
    for (i = 0; i < y; ++i)
    {
        fflush(stdin);
        scanf("%s", mapa[i]);

        /*for (j = 0; j < x; ++j)
            scanf("%c", &mapa[i][j]);*/
    }

    i = 0; j = 0;
    while (mapa[0][0] != '.')
    {
        if (mapa[i][j] == 'x') break;
        else if (mapa[i][j] == '*') { bau = 1; break; }
        else if (i >= y || i < 0 || j >= x || j < 0) break;
        else if (mapa[i][j] == '^') { ant = mapa[i][j]; mapa[i][j] = 'x'; i--; }
        else if (mapa[i][j] == '>') { ant = mapa[i][j]; mapa[i][j] = 'x'; j++; }
        else if (mapa[i][j] == 'v') { ant = mapa[i][j]; mapa[i][j] = 'x'; i++; }
        else if (mapa[i][j] == '<') { ant = mapa[i][j]; mapa[i][j] = 'x'; j--; }
        else if (mapa[i][j] == '.') {
                 if (ant == '^') { mapa[i][j] = 'x'; i--; }
            else if (ant == '>') { mapa[i][j] = 'x'; j++; }
            else if (ant == 'v') { mapa[i][j] = 'x'; i++; }
            else if (ant == '<') { mapa[i][j] = 'x'; j--; }
        }

    }
    printf("%c\n", bau ? '*' : '!');
    return 0;
}
