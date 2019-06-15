#include <locale.h>


void vetorLeitura(int vetor[], int size){
    int i;
    for(i=0; i<size; i++)
    {
        printf("\nDigite o valor na posicao %d: ",i);
        scanf("%d",&vetor[i]);
    }
}

void vetorExibe(int vetor[], int size){
    printf("\n\n");
    printf("[");
    for(int i=0; i<size; i++)
    {
        if(i==size-1)
            printf("%d",vetor[i]);
        else
            printf("%d,",vetor[i]);
    }
    printf("]");
    printf("\n");
}

void vetorMultiplica(int VetorA[],int VetorB[],int size){
    int i;
    int VetorProduto[size];
    int produto;
    for(i=0; i<size; i++)
        VetorProduto[i]=VetorA[i]*VetorB[i];

    vetorExibe(VetorProduto,size);
}

void tecladoABNT(){
    setlocale(LC_ALL,"");
}

void menu(){

    int opcao;

    printf("\n\t Titulo do Menu \n");
    printf("\n Escolha uma opcao");

    printf("\n1.Opção Um");
    printf("\n2.Opção Dois");


    printf("\nOpção: ");
    scanf("%d",&opcao);


    switch(opcao)
    {
    case 1:
        printf("PRIMEIRA");
        break;
    case 2:
        printf("SEGUNDA");
        break;
    }
}
