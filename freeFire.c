#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Definicao de struct

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

//Funcoes
void inserirItens(Item *itens, int quantidade){
    //Valida se tem menos de 11 itens
    if(quantidade < 10){
        //Cadastrar o item em memoria
        for(int i = 0; i < quantidade; i++){
            printf("\nItem %d:\n", i + 1);

            //leitor do nome
            printf("Nome: ");
            scanf("%29s", itens[i].nome);

            //leitor da tipo
            printf("tipo: ");
            scanf("%19s", itens[i].tipo);

            //leitor de quantidade
            printf("quantidade: ");
            scanf("%d", &itens[i].quantidade);
        }

    }
}

void removerItem(){

}

void listarItens(){

}

void buscarItem(){

}

void mostrarItens(Item *itens, int quantidade){
    if(quantidade < 10){
        //mostrar dados
        printf("\n--- Dados dos Itens ---\n");

        //ler todos os dados de de cada posicao do vetor
        for (int i = 0; i < quantidade; i++) {
            printf("Item %d : -- nome: %s -- tipo:  %s -- %d quantidade --\n",
                i + 1,
                itens[i].nome,
                itens[i].tipo,
                itens[i].quantidade
            );
        }
    }
}

int main(){

    int quantidade;
    printf("Quantos Itens deseja cadastrar?");
    scanf("%d", &quantidade);

    Item *itens = malloc(quantidade * sizeof(Item));

    cadastrarItens(itens,quantidade);
    mostrarItens(itens,quantidade);

    return 0;
}