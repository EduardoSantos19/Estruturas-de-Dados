#include "header.h"
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

//Algoritimos de Ordenação
void QuickSort(int *v, int tam){
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
            v[i] = v[min];
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


//Gerador de Dados
void Ger(){
     //variaveis de controle
    clock_t t=0;
    clock_t tmq=0;
    clock_t tmb=0;
    clock_t tms=0;
    int run= 50;
    
    //variaveis do vetor
    int tam=15;
    int vo[tam];
    int vq[tam];
    int vb[tam];
    int vs[tam];    

    //Gerador de Vetores
    int i=0;
    srand(time(NULL));
    for (i=0; i<tam; i++){
        vo[i] = rand() % 100;
    }

    //Run QuickSort
    int i2;
    for (i2=0; i2<run; i2++) {

        //Clona o Vetor Original
        int i;
        for (i=0; i<tam; i++){
            vq[i] = vo[i];
        }
        
        printf("\n\n\n===========================================\n");
        printf("Ordenacao QuickSort: \n");
        printf("===========================================\n");
        printf("Vetor Original: ");
        //Printa Vetor Original
        int i2;
        for(i2=0; i2<tam; i2++){
            printf("%d ", vq[i2]);
        }
        printf("\n-------------------------------------------\n");
        printf("Passos da Ordenacao: \n");
        printf("-------------------------------------------\n");

        t = clock();
        QuickSort(vq, tam);
        tmq += (clock() - t);
    } 

    //Run SelectionSort
    int i3;
    for (i3=0; i3<run; i3++){

        //Clona o Vetor Original
        int i;
        for (i=0; i<tam; i++){
            vs[i] = vo[i];
        }
        
        printf("\n\n\n===========================================\n");
        printf("Ordenacao SelectionSort: \n");
        printf("===========================================\n");
        printf("Vetor Original: ");
        //Printa Vetor Original
        int i3;
        for(i3=0; i3<tam; i3++){
            printf("%d ", vs[i3]);
        }
        printf("\n-------------------------------------------\n");
        printf("Passos da Ordenacao: \n");
        printf("-------------------------------------------\n");

        t = clock();
        SelectionSort(vs, tam);
        tms += (clock() - t);
    }

    //Run BobbleSort
    int i4;
    for (i4=0; i4<run; i4++){

        //Clona o Vetor Original
        int i;
        for (i=0; i<tam; i++){
            vb[i] = vo[i];
        }
        
        printf("\n\n\n===========================================\n");
        printf("Ordenacao BobbleSort: \n");
        printf("===========================================\n");
        printf("Vetor Original: ");
        //Printa Vetor Original
        int i4;
        for(i4=0; i4<tam; i4++){
            printf("%d ", vb[i4]);
        }
        printf("\n-------------------------------------------\n");
        printf("Passos da Ordenacao: \n");
        printf("-------------------------------------------\n");

        t = clock();
        BubbleSort(vb, tam);
        tmb += (clock() - t);
    }
    
    printf("\n\n\n\n\n\n\n\n*********************************************************************************************\n");
    printf("===========================================================================\n");
    printf("===========================================================================\n");
    printf("Execucao de algoritmos comcluida com sucesso, %d rodadas por algoritimo!", run);
    printf("\nTotal de execucoes: %d", (run*3));
    printf("\n===========================================================================\n");
    printf("===========================================================================");
    printf("\n*********************************************************************************************\n\n\n\n\n\n\n\n"); 
    printf("*****Pressione enter para exibir resultados*****:");
    getch();
    

    //Gerador de Ranking
    int i5;
    for (i5=1; i5<=3; i5++) {

        if (tmq<=tms) {
            if (tmq<=tmb){
                //Report Média QuickSort
                printf("\n\n\n===========================================\n");
                printf("Ordenacao QuickSort: N-%d",i5);
                printf("\n===========================================\n");
                printf("Vetor Original: ");
                //Printa Vetor Original
                int i;
                for(i=0; i<tam; i++){
                    printf("%d ", vq[i]);
                }
                printf("\n-------------------------------------------\n");
                printf("Tempo total de execucao: %.2lfms", (double)tmq);
                printf("\n-------------------------------------------\n");
                printf("-------------------------------------------\n");
                printf("Tempo medio de execucao do algoritmo: %.2lfms", ((double)tmq/run));
                printf("\n===========================================\n\n\n");
                tmq=50000;
                if (i5 != 3) {
                    printf("\n\n*****Pressione enter para exibir proximo do ranking*****:");
                    getch();
                }
            }else {
                ///Report Média BubbleSort
                printf("\n\n\n===========================================\n");
                printf("Ordenacao BobbleSort: N-%d",i5);
                printf("\n===========================================\n");
                printf("Vetor Original: ");
                int i;
                for(i=0; i<tam; i++){
                    printf("%d ", vb[i]);
                }
                printf("\n-------------------------------------------\n");
                printf("Tempo total de execucao: %.2lfms", (double)t);
                printf("\n-------------------------------------------\n");
                printf("-------------------------------------------\n");
                printf("Tempo medio de execucao do algoritmo: %.2lfms", ((double)tmb/run));
                printf("\n===========================================\n\n\n");
                tmb=50000;
                if (i5 != 3) {
                    printf("\n\n*****Pressione enter para exibir proximo do ranking*****:");
                    getch();
                }
            }
        }else {
            if (tms<=tmb) {
                //Report Média SelectionSort
                printf("\n\n\n===========================================\n");
                printf("Ordenacao SelectionSort: N-%d",i5);
                printf("\n===========================================\n");
                printf("Vetor Original: ");
                int i;
                for(i=0; i<tam; i++){
                    printf("%d ", vs[i]);
                }
                printf("\n-------------------------------------------\n");
                printf("Tempo total de execucao: %.2lfms", (double)t);
                printf("\n-------------------------------------------\n");
                printf("-------------------------------------------\n");
                printf("Tempo medio de execucao do algoritmo: %.2lfms", ((double)tms/run));
                printf("\n===========================================\n\n\n");
                tms=50000;
                if (i5 != 3) {
                    printf("\n\n*****Pressione enter para exibir proximo do ranking*****:");
                    getch();
                }
            } else { 
                ///Report Média BubbleSort
                printf("\n\n\n===========================================\n");
                printf("Ordenacao BobbleSort: N-%d",i5);
                printf("\n===========================================\n");
                printf("Vetor Original: ");
                int i;
                for(i=0; i<tam; i++){
                    printf("%d ", vb[i]);
                }
                printf("\n-------------------------------------------\n");
                printf("Tempo total de execucao: %.2lfms", (double)t);
                printf("\n-------------------------------------------\n");
                printf("-------------------------------------------\n");
                printf("Tempo medio de execucao do algoritmo: %.2lfms", ((double)tmb/run));
                printf("\n===========================================\n");
                tmb=50000;
                if (i5 != 3) {
                    printf("\n\n*****Pressione enter para exibir proximo do ranking*****:");
                    getch();
                }
                
            }
        }
    }    
}