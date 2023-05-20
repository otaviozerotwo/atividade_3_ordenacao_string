#include<stdio.h>
#include<stdlib.h>

void mostrar_menu(){
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
            bubble_sort();
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

void bubble_sort(){

}

void selection_sort(){

}

void insertion_sort(){

}

void merge_sort(){

}

int main(){

    mostrar_menu();

    return 0;
}
