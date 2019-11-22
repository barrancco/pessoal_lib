#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED



typedef struct {
  char caractere;
} TipoItem;

typedef struct celula {
  TipoItem item;
  struct celula* prox;
} TCelula;

typedef struct {
  TCelula *fundo;
  TCelula *topo;
  int tamanho;
} TPilha;

void FPVazia(TPilha *Pilha);
int Vazia(TPilha Pilha);
void Empilha(TipoItem x, TPilha *Pilha);
void Desempilha(TPilha *Pilha, TipoItem *Item);
int Tamanho(TPilha Pilha);
void Liberar(TPilha *pilha);

#endif // PILHA_H_INCLUDED
