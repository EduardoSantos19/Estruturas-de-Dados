#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//QuickSort
void QuickSort(int* v , int tam){
    int j = tam, k;
    if (tam <=1) {
        return;
    }else{
        int x=v[0];
        int a=1;
        int b=tam-1;

        do {
            while ((a<tam) && (v[a] <= x)){
                a++;
            }

            while (v[b] > x){
                b--;
            }

            if (a < b) { //faz troca
                int temp = v[a];
                v[a] = v[b];
                v[b] = temp;
                a++;
                b--;
            }

            for (k = 0; k<j; k++){
                printf("%d ", v[k]);
            }
            printf("\n");
        }while (a <= b);

        //troca pivo

        v[0] = v[b];
        v[b] = x;

        //Ordena subv-vetores restantes
        //Recursividade

        QuickSort(v, b);
        QuickSort(&v[a], tam -a);
        for (k=0; k<j; k++){
            printf("%d ", v[k]);
        }
        printf("\n");
    }    
}



void SelectionSort(int* v, int tam){
    int i, j, k, min;
    for (i =0; i<(tam -1); i++){
        min = i;
        for(j = (i+1); j<tam; j++){
            if (v[j] < v[min]) {
                min = j;
            }
        }
        if (i != min){
            int swap = v[i];
            v[min] = swap;
            for (k =0; k <tam; k++){
                printf("%d ", v[k]);
            }
            printf("\n");
        }
    }
}


void BubbleSort(int* v, int tam) {
    int i, j = tam, k;
    int trocou;
    do {
        tam--;
        trocou = 0;
        for (i=0; i<tam; i++) {
            if (v[i]>v[i+1]){
                int aux=0;
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                trocou = 1;
                for (k = 0; k<j; k++){
                    printf("%d ", v[k]);
                }
                printf("\n");
            }

            
        }
    }while (trocou);
}