/*
Seu professor de português não para de trazer coisas novas para a sala, e hoje não foi diferente. Existe uma cidade, segundo seu professor, onde as pessoas levam muito a sério a forma como elas se comunicam. Em especial, quando duas pessoas estão conversando, elas pensam muito nas frases antes de dizê-las, de forma a garantir que tal frase seja uma “frase completa”, ou talvez uma “frase quase completa”.

Considerando o nosso alfabeto de 26 letras, uma frase é dita “completa” quando ela contém todas as letras do alfabeto contidas nela. De modo semelhante, uma frase é dita “quase completa” se ela não é completa, porém contém ao menos metade das letras do alfabeto contidas nela. Quando uma frase não é “completa” e nem “quase completa”, ela é dita “mal elaborada”.

Seu professor lhe deu uma tarefa muito difícil: dadas várias frases trocadas entre vários habitantes da cidade citada, diga em qual das categorias acima a frase se encaixa.

Entrada
A primeira linha contém um inteiro N, indicando o número de casos de teste a seguir.

Cada caso de teste contém uma linha, contendo letras minúsculas, espaços em branco e/ou vírgulas. O número de caracteres de cada linha é no mínimo 3 e no máximo 1000, contando com os espaços.

Saída
Para cada caso de teste, imprima uma linha contendo uma das seguintes frases: “frase completa”, quando a frase é considerada completa; “frase quase completa”, quando a frase não é completa, mas é considerada quase completa; ou “frase mal elaborada”, quando ela não é completa e nem quase completa.
*/
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main(){
    char frase[1001];
    int N, diferentes, contagem[26];

    scanf("%d\n", &N);

    for(int k = 0; k < N; ++k){
        memset(contagem, 0, sizeof(contagem));

        scanf("%[^\n]\n", &frase);

        for(int i = 0; i < strlen(frase); ++i){
            if(isalpha(frase[i])){
                contagem[frase[i] - 'a'] = 1;
            }
        }

        diferentes = 0;
        for(int i = 0; i < 26; ++i){
            if(contagem[i]) ++diferentes;
        }

        if(diferentes == 26)        printf("frase completa\n");
        else if(diferentes > 12)    printf("frase quase completa\n");
        else                        printf("frase mal elaborada\n");
    }

    return 0;
}
