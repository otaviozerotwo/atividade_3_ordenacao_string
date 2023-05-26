#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM_NOME 100
#define QTD_LINHAS 1000

int ler_arquivo(char* nome_arquivo, char nomes[QTD_LINHAS][TAM_NOME]){
    FILE* arquivo = fopen(nome_arquivo, "r");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }
    int i = 0;
    while(!feof(arquivo)){
        fgets(nomes[i], TAM_NOME, arquivo);
        i++;
    }

    fclose(arquivo);

    return 0;
}

void mostrar_nomes(char nomes[][TAM_NOME]){
    for(int j = 0; j < QTD_LINHAS; j++){
        printf("%s", nomes[j]);
    }
}

void mostrar_menu(char nomes[][TAM_NOME]){
    int op = 0;

    do{
        printf("Escolha qual metodo de ordenacao deseja usar:\n\n");
        printf("1: Bubble Sort\n");
        printf("2: Selection Sort\n");
        printf("3: Insertion Sort\n");
        printf("4: Merge Sort\n");
        printf("5: Sair\n");
        scanf("%d", &op);

        switch(op){
        case 1:
            bubble_sort(nomes);
            mostrar_nomes(nomes);
            exit(0);
        case 2:
            selection_sort(nomes);
            mostrar_nomes(nomes);
            exit(0);
        case 3:
            insertion_sort(nomes);
            mostrar_nomes(nomes);
            exit(0);
        case 4:
            merge_sort(nomes);
            mostrar_nomes(nomes);
            exit(0);
        case 5:
            exit(0);
        default:
            printf("Opcao invalida!\n\n");
            break;
        }
    }while(op != 5);
}

void trocar(char nomes[][TAM_NOME], int i, int j){
    char temp[TAM_NOME];

    strcpy(temp, nomes[i]);
    strcpy(nomes[i], nomes[j]);
    strcpy(nomes[j], temp);
}

void bubble_sort(char nomes[][TAM_NOME]){
    for(int i = 0; i < (QTD_LINHAS - 1); i++){
        for(int j = 0; j < (QTD_LINHAS - i - 1); j++){
            if(strcmp(nomes[j], nomes[j+1]) > 0){
                trocar(nomes, j, j+1);
            }
        }
    }
}

void selection_sort(char nomes[][TAM_NOME]){

}

void insertion_sort(char nomes[][TAM_NOME]){

}

void merge_sort(char nomes[][TAM_NOME]){

}

int main(){
    char nome_arquivo[] = "nomes2.txt";
    char nomes[QTD_LINHAS][TAM_NOME];

    ler_arquivo(nome_arquivo, nomes);
    mostrar_menu(nomes);

    return 0;
}
