#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int ler_arquivo(char* nome_arquivo, char* nomes){
    FILE* arquivo = fopen(nome_arquivo, "r");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    int i = 0;
    while(fgets(nomes, 100, arquivo) != NULL){
        nomes[strcspn(nomes, "\n")] = '\0';
        i++;
    }

    fclose(arquivo);

    return 0;
}

void mostrar_nomes(char* nomes){

}

void mostrar_menu(char* nomes){
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
            exit(0);
        case 2:
            selection_sort();
            exit(0);
        case 3:
            insertion_sort();
            exit(0);
        case 4:
            merge_sort();
            exit(0);
        case 5:
            exit(0);
        default:
            printf("Opcao invalida!\n\n");
            break;
        }
    }while(op != 5);
}

void bubble_sort(char* nomes){
    char temp;

    for(int i = 0; i < 100 - 1; i++){
        for(int j = 0; j < 100 - i - 1; j++){
            if(nomes[j] < nomes[j+1]){
                temp = nomes[j+1];
                nomes[j] = nomes[j+1];
                nomes[j+1] = temp;
            }
        }
    }
}

void selection_sort(){

}

void insertion_sort(){

}

void merge_sort(){

}

int main(){
    //mostrar_menu();
    char nome_arquivo[] = "nomes2.txt";
    char nomes[100];

    ler_arquivo(nome_arquivo, nomes);
    //mostrar_menu(nomes);
    mostrar_nomes(nomes);

    return 0;
}
