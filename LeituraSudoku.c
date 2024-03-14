/*programa para leitura de jogo sudoku, onde a entrada eh a quantidade de jogo
para analisar em sequencia as partidas de jogo, resultando se o jogo estah correto ou
nao*/
#include <stdio.h>

typedef struct intancia {
    int k;
    int sudoku[9][9];
} Tabela;

/*funcao onde recebe a struct do jogo (jogo[k]) e qual jogo(k) esta em analise,
retornado 1 para valido e 0 para errado */
int confere(Tabela jogo[], int k){
    int i , j , linha , coluna , soma , produto ;
    //verificacao por coluna
    for( linha = 0 ; linha < 9 ; linha++){
        soma = 0;
        produto = 1;
        for (coluna = 0 ; coluna < 9  ; coluna++ ){
            soma += jogo[k].sudoku[linha][coluna];
            produto = jogo[k].sudoku[linha][coluna]*produto;
        }
        if (soma != 45 || produto != 362880){
          return 0;
        }
    }

    //verificação por linha
    for( coluna = 0 ; coluna < 9 ; coluna++){
        soma = 0;
        produto = 1;
        for (linha = 0 ; linha < 9  ; linha++ ){
            soma += jogo[k].sudoku[linha][coluna];
            produto = jogo[k].sudoku[linha][coluna]*produto;
        }
        if (soma != 45 || produto != 362880){
          return 0;
        }
    }

    //verifcação por bloco
    for ( i = 0 ; i < 9 ; i +=3 ){
        for ( j = 0 ; j < 9; j +=3 ){
            soma = 0;
            produto = 1;
            for( linha = 0 ; linha < 3 ; linha++){
                for (coluna = 0 ; coluna < 3  ; coluna++ ){
                    soma += jogo[k].sudoku[linha+i][coluna+j];
                    produto = jogo[k].sudoku[linha+i][coluna+j]*produto;
                }
            }
            if (soma != 45 || produto != 362880){
              return 0;
            }
        }
    }
    return 1;
}

int main() {
    int  linha , i , coluna , k , instancia ;
  
    // leitura de numero de quantidade de jogo 
    scanf("%d",&k );

    //leitura de k jogos 
    struct intancia jogo[k];
    for ( i = 0 ; i < k ; i++ ){
        jogo[i].k = i;
        for (linha = 0; linha < 9 ; linha++){
            for (coluna = 0 ; coluna < 9 ; coluna ++){
                scanf("%d",&jogo[i].sudoku[linha][coluna]);
            }
        }
    }

    for ( i = 0 ; i < k ; i ++){
        instancia = confere (jogo, i);
        printf("Instancia %d\n",i+1);
        if (instancia == 1){
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }
  
    return 0;
  
}