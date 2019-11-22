#include <stdio.h>
#include <stdlib.h>
#include "filas.h"

int main()
{
    TipoFila fila1, fila2;
    TipoFila intercecao;;
    TipoItem usuario;
    int qtd;

    FFVazia(&fila1);
    FFVazia(&fila2);
    FFVazia(&intercecao);

    printf("\n ---> Digite quantos usuario deseja cadastrar na Fila 1: ");
    scanf("%d", &qtd);
    for(int i=0; i<qtd; ++i)
        Cadastrar(&fila1,&usuario);

    printf("\n ---> Digite quantos usuario deseja cadastrar na Fila 2: ");
    scanf("%d", &qtd);
    for(int i=0; i<qtd; ++i)
        Cadastrar(&fila2,&usuario);
    printf("\n\n");
    ImprimirCadastrados(fila1);
    printf("\n\n");
    ImprimirCadastrados(fila2);
    printf("\n\n");
    novaFilaComIntercecao(&fila1,&fila2,&intercecao);
    ImprimirCadastrados(intercecao);
    printf("\n\n");
    printf("--------------x--------------x--------------");
    Liberar(&fila1);
    Liberar(&fila2);
    Liberar(&intercecao);

    if(Vazia(fila1))
        printf("\n\tFila 1 Vazia!");
    if(Vazia(fila1))
        printf("\n\tFila 2 Vazia!");
    if(Vazia(intercecao))
        printf("\n\tFila Intercecao Vazia!");

    return 0;
}
