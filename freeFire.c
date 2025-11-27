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


int buscarItemPeloNome(Item *itens, int quantidade, const char *nome) {
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(itens[i].nome, nome) == 0) {
            printf("\nItem encontrado:\n");
            printf("Nome: %s\n", itens[i].nome);
            printf("Tipo: %s\n", itens[i].tipo);
            printf("Quantidade: %d\n", itens[i].quantidade);
            return i;
        }
    }
    return -1; //não encontrado
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

int inserirItensParaTeste(Item *itens) {

    strcpy(itens[0].nome, "AK47");
    strcpy(itens[0].tipo, "Arma");
    itens[0].quantidade = 1;

    strcpy(itens[1].nome, "MunicaoAR");
    strcpy(itens[1].tipo, "Municao");
    itens[1].quantidade = 180;

    strcpy(itens[2].nome, "Colete");
    strcpy(itens[2].tipo, "Protecao");
    itens[2].quantidade = 1;

    strcpy(itens[3].nome, "Capacete");
    strcpy(itens[3].tipo, "Protecao");
    itens[3].quantidade = 1;

    strcpy(itens[4].nome, "KitMedico");
    strcpy(itens[4].tipo, "Cura");
    itens[4].quantidade = 3;

    return 5; // quantidade preenchida
}

int main(){

    int quantidade;
    char nomeDoItemParaRemover[30];
    char nomeDoItemParaBuscar[30];
    
    printf("Quantos Itens deseja cadastrar?");
    scanf("%d", &quantidade);

    Item *itens = malloc(quantidade * sizeof(Item));

    inserirItens(itens,quantidade);
    listarItens(itens,quantidade);

    //    TESTE    //
    /*
    quantidade = 5;
    Item *itens = malloc(quantidade * sizeof(Item));
    inserirItensParaTeste(itens);
    listarItens(itens,quantidade); 
    */
    //    FIM DO TESTE    //

    printf("Qual item que deseja remover?");
    scanf("%19s", nomeDoItemParaRemover);

   if (removerItemPeloNome(itens,quantidade, nomeDoItemParaRemover)) {
        printf("Item removido com sucesso.\n");
        quantidade--;
    } else {
        printf("Item nao encontrado.\n");
    }
    listarItens(itens,quantidade);

    printf("Qual item que deseja buscar?");
    scanf("%19s", nomeDoItemParaBuscar);

    buscarItemPeloNome(itens,quantidade, nomeDoItemParaBuscar);
    listarItens(itens,quantidade);

    free(itens);
    return 0;
}