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
            break;
        case 2:
            selection_sort(nomes);
            mostrar_nomes(nomes);
            break;
        case 3:
            insertion_sort(nomes);
            mostrar_nomes(nomes);
            break;
        case 4:
            merge_sort(nomes, 0, (QTD_LINHAS - 1));
            mostrar_nomes(nomes);
            break;
        case 5:
            break;
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
    for(int i = 0; i < (QTD_LINHAS - 1); i++){
        for(int j = i + 1; j < QTD_LINHAS; j++){
            if(strcmp(nomes[i], nomes[j]) > 0){
                trocar(nomes, i, j);
            }
        }
    }
}

void insertion_sort(char nomes[][TAM_NOME]){
    int j = 0;
    char *key;
    for(int i = 1; i < QTD_LINHAS; i++){
        strcpy(key, nomes[i]);
        for(j = i - 1; j >= 0 && (strcmp(nomes[j], key) > 0); j--){
            strcpy(nomes[j + 1], nomes[j]);
        }
        strcpy(nomes[j + 1], key);
    }
}

void merge(char nomes[][TAM_NOME], int inicio, int meio, int fim){
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    char left[n1][TAM_NOME];
    char right[n2][TAM_NOME];

    int i, j, k;

    for(i = 0; i < n1; i++){
        strcpy(left[i], nomes[inicio + i]);
    }
    for(j = 0; j < n2; j++){
        strcpy(right[j], nomes[meio + 1 + j]);
    }

    i = 0;
    j = 0;
    k = inicio;

    while(i < n1 && j < n2){
        if(strcmp(left[i], right[j]) <= 0){
            strcpy(nomes[k], left[i]);
            i++;
        }else{
            strcpy(nomes[k], right[j]);
            j++;
        }
        k++;
    }

    while(i < n1){
        strcpy(nomes[k], left[i]);
        i++;
        k++;
    }

    while(j < n2){
        strcpy(nomes[k], right[j]);
        j++;
        k++;
    }
}

void merge_sort(char nomes[][TAM_NOME], int inicio, int fim){
    if(inicio < fim){
        int meio = (inicio + fim) / 2;
        merge_sort(nomes, inicio, meio);
        merge_sort(nomes, (meio + 1), fim);
        merge(nomes, inicio, meio, fim);
    }
}

int main(){
    char nome_arquivo[] = "nomes2.txt";
    char nomes[QTD_LINHAS][TAM_NOME];

    ler_arquivo(nome_arquivo, nomes);
    mostrar_menu(nomes);

    return 0;
}
