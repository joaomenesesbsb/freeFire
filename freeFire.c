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

int removerItemPeloNome(Item *itens, int quantidade, const char *nome){
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(itens[i].nome, nome) == 0) {
            // Move tudo para a esquerda
            for (int j = i; j < quantidade - 1; j++) {
                itens[j] = itens[j + 1];
            }
            // Reduzir tamanho lógico
            (quantidade)--;
            return 1; // sucesso - removeu apenas a primeira ocorrência
        }
    }
    return 0; // nao encontrado
}


void buscarItem(){

}

void listarItens(Item *itens, int quantidade){
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

    inserirItens(itens,quantidade);
    listarItens(itens,quantidade);

    char nomeDoItemParaRemover[30];
    printf("Qual item que deseja remover?");
    scanf("%19s", nomeDoItemParaRemover);

   if (removerItemPeloNome(itens,quantidade, nomeDoItemParaRemover)) {
        printf("Item removido com sucesso.\n");
        quantidade--;
    } else {
        printf("Item nao encontrado.\n");
    }
    listarItens(itens,quantidade);

    free(itens);
    return 0;
}