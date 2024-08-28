/*
Tia Joana é uma respeitada professora e tem vários alunos. Em sua última aula, ela prometeu que iria sortear um aluno para ganhar um bônus especial na nota final: ela colocou N pedaços de papel numerados de 1 a N em um saquinho e sorteou um determinado número K; o aluno premiado foi o K-ésimo aluno na lista de chamada.

O problema é que a Tia Joana esqueceu o diário de classe, então ela não tem como saber qual número corresponde a qual aluno. Ela sabe os nomes de todos os alunos, e que os números deles, de 1 até N, são atribuídos de acordo com a ordem alfabética, mas os alunos dela estão muito ansiosos e querem logo saber quem foi o vencedor.

Dado os nomes dos alunos da Tia Joana e o número sorteado, determine o nome do aluno que deve receber o bônus.

Entrada
A primeira linha contém dois inteiros N e K separados por um espaço em branco (1 ≤ K ≤ N ≤ 100). Cada uma das N linhas seguintes contém uma cadeia de caracteres de tamanho mínimo 1 e máximo 20 representando os nomes dos alunos. Os nomes são compostos apenas por letras minúsculas de 'a' a 'z'.

Saída
Seu programa deve imprimir uma única linha, contendo o nome do aluno que deve receber o bônus.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista {
    char nome[200];
    struct lista* prox;
} Lista ;

void alfabetica(Lista **lista_chamada){
    if (*lista_chamada == NULL || (*lista_chamada)->prox == NULL) {
        return;
    }

    Lista* auxiliar = *lista_chamada, *t = *lista_chamada;

    for  ( ; auxiliar->prox != NULL ; auxiliar = auxiliar->prox){
        if (auxiliar-> prox != NULL)
            t = auxiliar;
    }

    while (auxiliar != *lista_chamada){

        int a = strcmp(auxiliar->nome, t->nome);
        if (a < 0){
              Lista *ajuda;
              if (t == *lista_chamada){
                  *lista_chamada = auxiliar;
                  t-> prox = auxiliar->prox;
                  auxiliar-> prox = t;                  
              } else {
                  for(ajuda = *lista_chamada   ;    ajuda->prox != t ;      ajuda = ajuda->prox);
                  t->prox = auxiliar->prox;
                  ajuda -> prox = auxiliar;
                  auxiliar->prox = t;
                  auxiliar = t;
              }          
              if (t->prox != NULL) auxiliar = t->prox;

        }
        else {
              auxiliar = t;
              if(auxiliar != *lista_chamada)
                  for (t = *lista_chamada ; t->prox != auxiliar ; t = t->prox);
        }         
    }   

    return;
}

void order(Lista **lista) {

    if(*lista == NULL || (*lista)->prox == NULL) return; //se for nulo(vazio), ou apenas 1 elemento
    Lista *aux = *lista, *t;
    char s[100]; //precisa de espacao suficiente para armazenar o item

    while(aux != NULL) {
      t = aux->prox;
      while(t != NULL) {
        if(strcmp(aux->nome, t->nome ) > 0) { //se vir depois
            strcpy(s, aux->nome);
            strcpy(aux->nome, t->nome);
            strcpy(t->nome, s);
        }
        t = t->prox;
      }
      aux = aux->prox;
    }
}

Lista* CriaListaChamada (Lista *Lista_chamada, char palavra[200]) {
    Lista* NOVO = (Lista*)malloc( sizeof(Lista));
    strcpy(NOVO->nome,palavra);
    if (Lista_chamada == NULL){
        NOVO->prox = NULL;
        return NOVO;
    } else {
        NOVO->prox = Lista_chamada;  
    }
    return NOVO;
}

int main(void) {
    Lista *NomeSorteado,*lista_chamada = NULL;
    int N,Nsorteado;
    scanf("%d",&N);
    scanf("%d",&Nsorteado);
    for (int i = 0 ; i < N ; i ++){
        char nomezinho[200];
        scanf("%s",nomezinho);
        lista_chamada = CriaListaChamada(lista_chamada, nomezinho);
    }
    order(&lista_chamada);
    NomeSorteado = lista_chamada;
    for (int i = 1 ; i < Nsorteado; i++){
        NomeSorteado = NomeSorteado->prox;
    }
    printf("%s\n",NomeSorteado->nome);
    return 0;
}
