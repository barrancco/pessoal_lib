#include <stdlib.h>
#include <stdio.h>
#include "filas.h"

void FFVazia(TipoFila *Fila){
    Fila->frente = (TipoCelula*) malloc(sizeof(TipoCelula));
    Fila->tras = Fila->frente;
    Fila->frente->prox = NULL;
    Fila->tamanho = 0;
}

int Vazia(TipoFila Fila){
    return (Fila.frente == Fila.tras);
}

void Enfileirar(TipoItem x, TipoFila *Fila){
    Fila->tras->prox = (TipoCelula*) malloc(sizeof(TipoCelula));
    Fila->tras = Fila->tras->prox;
    Fila->tras->item = x;
    Fila->tras->prox = NULL;
    Fila->tamanho++;
}

void Desenfileirar(TipoFila *Fila, TipoItem *Item){
    TipoCelula* aux;
    if (!Vazia(*Fila)){
    	aux = Fila->frente->prox;
    	Fila->frente->prox = aux->prox;
    	*Item = Fila->frente->item;
    	free(aux);
	if (Fila->frente->prox == NULL)
	    Fila->tras = Fila->frente;
        Fila->tamanho--;
    }
}

void Liberar(TipoFila *Fila){
    TipoItem usuario;
    while(!Vazia(*Fila))
        Desenfileirar(Fila,&usuario);

    free(Fila->frente);
}

void LerInt(char msg[],int *variavel){
    printf("\n%s: ", msg);
    scanf("%d", variavel);
}

void LerUsuario(TipoItem *usuario){
    int ID;
    LerInt("Digite 6 digitos do ID do Usuario", &ID);
    usuario->ID=ID;
}

void Cadastrar(TipoFila *Fila, TipoItem *usuario){
    LerUsuario(usuario);
    Enfileirar(*usuario, Fila);

}

void ImprimirCadastrados(TipoFila Fila){
    TipoCelula *aux;
    aux=Fila.frente->prox;

    for(int i=1; i<Fila.tamanho+1;i++){
        printf("\n Usuario - ID: %d",aux->item.ID);
        aux=aux->prox;
    }
}

void duplicaFila(TipoFila *fila1, TipoFila *novaFila) {
    TipoItem item;

    FFVazia(novaFila);

    while (fila1->frente->prox != NULL) {
        item = fila1->frente->prox->item;
        Enfileirar(item, novaFila);
    }
}

void novaFilaComIntercecao(TipoFila *fila1, TipoFila *fila2, TipoFila *filaIntercecao) {
    TipoFila filaAux1, filaAux2, filaAux3;
    TipoItem item;
    bool encontrouId = false;

    FFVazia(&filaAux3);

    duplicaFila(fila1, &filaAux1);
    duplicaFila(fila2, &filaAux2);

    while (Vazia(filaAux1)) {

        while (Vazia(filaAux2)) {

             if (!encontrouId && filaAux1.frente->prox->item.ID == filaAux2.frente->prox->item.ID) {
                Desenfileirar(&filaAux2, &item);
                Enfileirar(item, filaIntercecao);
                encontrouId = true;
            } else {
                Desenfileirar(&filaAux2, &item);
                Enfileirar(item, &filaAux3);
            }
        }

        Desenfileirar(&filaAux1, &item);
    }
}

