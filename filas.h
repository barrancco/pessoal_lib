#ifndef FILAS_H_INCLUDED
#define FILAS_H_INCLUDED

typedef enum{ false, true} bool;

typedef struct TipoItem{
    int ID;
    /* outros campos */
} TipoItem;

typedef struct celula{
    TipoItem item;
    struct celula* prox;
} TipoCelula;

typedef struct TipoFila{
    TipoCelula* frente;
    TipoCelula* tras;
    int tamanho;
} TipoFila;

void FFVazia(TipoFila *Fila);
int Vazia(TipoFila Fila);
void Enfileirar(TipoItem x, TipoFila *Fila);
void Desenfileirar(TipoFila *Fila, TipoItem *Item);
void LerInt(char msg[],int *variavel);
void LerUsuario(TipoItem *usuario);
void Cadastrar(TipoFila *Fila, TipoItem *usuario);
void ImprimirCadastrados(TipoFila Fila);
void duplicaFila(TipoFila *fila1, TipoFila *novaFila);
void novaFilaComIntercecao(TipoFila *fila1, TipoFila *fila2, TipoFila *filaIntercecao);

#endif // FILAS_H_INCLUDED
