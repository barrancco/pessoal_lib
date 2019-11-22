#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "pilha.h"

void FPVazia(TPilha *Pilha){
  Pilha->topo = (TCelula*) malloc(sizeof(TCelula));
  Pilha->fundo = Pilha->topo;
  Pilha->topo->prox = NULL;
  Pilha->tamanho = 0;
}

int Vazia(TPilha Pilha){
 return (Pilha.topo == Pilha.fundo);
}

void Empilha(TipoItem x, TPilha *Pilha){
  TCelula* Aux;
  Aux = (TCelula*) malloc(sizeof(TCelula));
  Pilha->topo->item = x;
  Aux->prox = Pilha->topo;
  Pilha->topo = Aux;
  Pilha->tamanho++;
}

void Desempilha(TPilha *Pilha, TipoItem *Item){
  TCelula* q;
  if (Vazia(*Pilha)) {
      printf("Erro: lista vazia\n");
      return;
  }
  q = Pilha->topo;
  Pilha->topo = q->prox;
  *Item = q->prox->item;
  free(q);
  Pilha->tamanho--;
}

int Tamanho(TPilha Pilha){
 return (Pilha.tamanho);
}

void Liberar(TPilha *pilha){
    TipoItem lixo;
    while(!Vazia(*pilha))
        Desempilha(pilha,&lixo);
    free(pilha->fundo);
}
//------------------------------------------------------//
