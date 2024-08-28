/*
Um dos esportes favoritos na Robolândia é o Rali dos Robôs. Este rali é praticado em uma arena retangular gigante de N linhas por M colunas de células quadradas. Algumas das células estão vazias, algumas contêm figurinhas da Copa (muito apreciadas pelas inteligências artificiais da Robolândia) e algumas são ocupadas por pilastras que sustentam o teto da arena. Em seu percurso os robôs podem ocupar qualquer célula da arena, exceto as que contém pilastras, que bloqueiam o seu movimento. O percurso do robô na arena durante o rali é determinado por uma sequência de instruções. Cada instrução é representada por um dos seguintes caracteres: ‘D’, ‘E’ e ‘F’, significando, respectivamente, “gire 90 graus para a direita”, “gire 90 graus para a esquerda” e “ande uma célula para a frente”. O robô começa o rali em uma posição inicial na arena e segue fielmente a sequência de instruções dada (afinal, eles são robôs!). Sempre que o robô ocupa uma célula que contém uma figurinha da Copa ele a coleta. As figurinhas da Copa não são repostas, ou seja, cada figurinha pode ser coletada uma unica vez. Quando um robô tenta andar para uma célula onde existe uma pilastra ele patina, permanecendo na célula onde estava, com a mesma orientação. O mesmo também acontece quando um robô tenta sair da arena.

Dados o mapa da arena, descrevendo a posição de pilastras e figurinhas, e a sequência de instruções de um robô, você deve escrever um programa para determinar o número de figurinhas coletadas pelo robô.

Entrada
A entrada contém vários casos de teste. A primeira linha de um caso de teste contém três números inteiros N, M e S (1 ≤ N, M ≤ 100, 1 ≤ S ≤ 5 × 104 ), separados por espaços em branco, indicando respectivamente o número de linhas e o número de colunas da arena e o número de instruções para o robô. Cada uma das N linhas seguintes da entrada descreve uma linha de células da arena e contém uma cadeia com M caracteres. A primeira linha que aparece na descrição da arena é a que está mais ao Norte; a primeira coluna que aparece na descrição de uma linha de células da arena é a que está mais a Oeste.

Cada célula da arena pode conter um dos seguintes caracteres:

‘.’ — célula normal;
‘*’ — célula que contém uma figurinha da Copa;
‘#’ — célula que contém uma pilastra;
‘N’, ‘S’, ‘L’, ‘O’ — célula onde o robô inicia o percurso (única na arena). A letra representa a orientação inicial do robô (Norte, Sul, Leste e Oeste, respectivamente).

A ultima linha da entrada contém uma sequência de S caracteres dentre ‘D’, ‘E’ e ‘F’, representando as instruções do robô.

O último caso de teste é seguido por uma linha que contém apenas três números zero separados por um espaço em branco.

Saída
Para cada rali descrito na entrada seu programa deve imprimir uma única linha contendo um único inteiro, indicando o número de figurinhas que o robô colecionou durante o rali.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int n, m, s, lin, col, pi, pj, fig, h, vi, vj;
   short proc;
   char mp[101][101];
   char it[50001];

   while (scanf("%d %d %d", &n, &m, &s) == 3 && n+m+s) {
      while (getchar() != '\n');
      proc = 1;
      for (lin = 0; lin < n; ++lin) {
         for (col = 0; col < m; ++col) {
            scanf("%c", &mp[lin][col]);

            if (proc && mp[lin][col] == 'N' || mp[lin][col] == 'S' || mp[lin][col] == 'L' || mp[lin][col] == 'O') {
               pi = lin; pj = col; proc = 0;
            }
         }
         while (getchar() != '\n');
      }
      scanf("%s", &it);
      fig = 0;
      for (h = 0; h < s; ++h) {
         if (it[h] == 'D' && mp[pi][pj] == 'N') mp[pi][pj] = 'L';
         else if (it[h] == 'D' && mp[pi][pj] == 'L') mp[pi][pj] = 'S';
         else if (it[h] == 'D' && mp[pi][pj] == 'S') mp[pi][pj] = 'O';
         else if (it[h] == 'D' && mp[pi][pj] == 'O') mp[pi][pj] = 'N';
         else if (it[h] == 'E' && mp[pi][pj] == 'N') mp[pi][pj] = 'O';
         else if (it[h] == 'E' && mp[pi][pj] == 'O') mp[pi][pj] = 'S';
         else if (it[h] == 'E' && mp[pi][pj] == 'S') mp[pi][pj] = 'L';
         else if (it[h] == 'E' && mp[pi][pj] == 'L') mp[pi][pj] = 'N';
         else {
            if (mp[pi][pj] == 'N') { vi = pi-1; vj = pj; }
            else if (mp[pi][pj] == 'O') { vi = pi; vj = pj-1; }
            else if (mp[pi][pj] == 'S') { vi = pi+1; vj = pj; }
            else if (mp[pi][pj] == 'L') { vi = pi; vj = pj+1; }
            if (0 <= vi && vi < n && 0 <= vj && vj < m && mp[vi][vj] != '#') {
               if (mp[vi][vj] == '*') ++fig;
               mp[vi][vj] = mp[pi][pj];
               mp[pi][pj] = '.';
               pi = vi; pj = vj;
            }
         }
      }
      printf("%d\n", fig);
   }
   return 0;
}
