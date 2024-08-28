/*
Hoje é a inauguração de um grande supermercado em sua cidade, e todos estão muito excitados com os baixos preços prometidos.

Este supermercado tem N funcionários que trabalham no caixa, identificados por números de 1 a N, onde cada funcionário leva um determinado tempo vi para processar um item de um cliente. Ou seja, se um cliente tem cj itens em sua cesta, um determinado funcionário levará vi*cj segundos para processar todos os itens deste cliente.

Quando um cliente entra na fila para ser atendido ele espera até que um funcionário esteja livre para o atendê-lo. Se mais de um funcionário estiverem livres ao mesmo tempo, o cliente será atendido pelo funcionário de menor número de identificação. Tal funcionário só estará livre novamente após processar todos os itens deste cliente.

Há M clientes na fila para serem atendidos, cada um com um determinado número de itens na sua cesta. Dadas as informações sobre os funcionários nos caixas e os clientes, o gerente pediu sua ajuda para descobrir quanto tempo levará para que todos os clientes sejam atendidos.

Entrada
A primeira linha conterá dois inteiros N e M, indicando o número de funcionários no caixa e o número de clientes, respectivamente (1 ≤ N ≤ M ≤ 104).

Em seguida haverá N inteiros vi, indicando quanto tempo leva para o i-ésimo funcionário processar um item (1 ≤ vi ≤ 100, para todo 1 ≤ i ≤ N).

Em seguida haverá M inteiros cj, indicando quantos itens o j-ésimo cliente tem em sua cesta (1 ≤ cj ≤ 100, para todo 1 ≤ j ≤ M).

Saída
Imprima uma linha contendo um inteiro, indicando quanto tempo levará para que todos os clientes sejam atendidos.
*/#include <stdio.h>
#include <stdlib.h>

typedef struct fila{
      int produtos,pessoa;
      struct fila* prox;
} filas;

typedef struct lista{
    int produtividade,balcao,Ncaixa;
    struct lista *prox;
}listas;

int liberarFila (filas** ultimo){
    int quantidadeMercadoria; 
    filas *lixo = (*ultimo)->prox;
    quantidadeMercadoria = lixo->produtos;
    if (lixo->prox == *ultimo){
        free(lixo);
        lixo->prox = NULL;
        *ultimo = NULL;
        return quantidadeMercadoria;
    }
    (*ultimo)->prox = lixo->prox;
    free(lixo);
    return quantidadeMercadoria;
}

void CriaListaCaixa (listas** caixas, int produtividadeDoCaixa,int Ncaixa){
    listas *NOVO = (listas*)malloc(sizeof(listas));
    NOVO->produtividade = produtividadeDoCaixa;
    NOVO->prox = NULL;
    NOVO->Ncaixa = Ncaixa;
    NOVO->balcao = 0;
    if (*caixas == NULL){
        *caixas = NOVO;        
    } else {
      listas* aux;
      for (aux = *caixas ; aux -> prox != NULL ; aux = aux->prox );
      aux->prox = NOVO;      
    }
    
    return;
}

filas *CriafilaCliente(filas* ultimo, int produtos,int pessoa){
    filas* NOVO = (filas*)malloc(sizeof(filas));
    NOVO->produtos = produtos;
    NOVO->pessoa = pessoa;
    if (ultimo == NULL){
        NOVO->prox = NOVO;
        return NOVO;
    }
    NOVO -> prox = ultimo -> prox;
    ultimo -> prox = NOVO;
    return NOVO;
}

void printarfila (filas *ultimo){
    if (ultimo == NULL) return;
    filas *aux = ultimo;
    do {
      aux = aux->prox;
      printf(" %d",aux->pessoa);
    } while (aux != ultimo);
    return;
}

void printar (listas *lista){

    if (lista == NULL){    
        return;
    }

    printf(" produ = %d \n",lista->Ncaixa);
    printar (lista->prox);
    return;
}

int atendimento (filas* ultimo, listas* caixas){
    int tempo = 0 , filavazia = 1 ;
    filas *auxcliente = ultimo->prox;
    do  {      
        for ( listas* auxcaixas = caixas ; auxcaixas != NULL ; auxcaixas = auxcaixas->prox ){
            if (ultimo != NULL && auxcaixas->balcao == 0) {
                //printf("\npessoa = %d no caixa %d\n",auxcliente->pessoa, auxcaixas->Ncaixa );
                int produtoCliente = auxcliente->produtos;
                auxcliente->produtos = 0;
                auxcaixas->balcao = auxcaixas->produtividade * produtoCliente;
                //printarfila(ultimo);
                //printf("\n");
                //printf("caixa(%d) %d recebeu %d, tempo estimado de %d\n" , auxcaixas->produtividade, auxcaixas->Ncaixa, produtoCliente , auxcaixas->balcao);
              auxcliente = auxcliente->prox;
              if (auxcliente == ultimo->prox) filavazia = 0;
            }
        }
        if (auxcliente == ultimo->prox) filavazia = 0;
        int verificacao = 1;
        while (verificacao != 0){ 
            for ( listas* auxcaixas = caixas ; auxcaixas != NULL ;auxcaixas = auxcaixas->prox ){
                auxcaixas->balcao -= 1;              
                if (auxcaixas->balcao == 0) verificacao = 0;
            }
            tempo++;
        }
    if (auxcliente == ultimo->prox) filavazia = 0;
    } while (filavazia != 0);
    int tempofinal = caixas->balcao;
    for ( listas* auxcaixas = caixas ; auxcaixas != NULL ;auxcaixas = auxcaixas->prox ){
        if (tempofinal < auxcaixas->balcao) tempofinal = auxcaixas->balcao;
    }
    
    return  tempo+tempofinal;
}

int main(){
  int clientes = 1, funcionarios = 1,tempo;
  scanf("%d %d",&funcionarios,&clientes);
  listas *caixas = NULL;
  filas *ultimo = NULL;
  
  for (int i = 0 ; i < funcionarios ;i++){
      int produtividade;
      scanf("%d",&produtividade);
      CriaListaCaixa(&caixas,produtividade,i+1);      
  }

  for (int i = 0 ; i < clientes ; i++){
      int produtos;
      scanf("%d",&produtos);
      ultimo = CriafilaCliente(ultimo,produtos,i+1);
  }
  //printar(caixas);
  tempo = atendimento(ultimo, caixas);
  
  //printarfila(ultimo);
  printf("%d\n",tempo);
  
  
  return 0;
}
