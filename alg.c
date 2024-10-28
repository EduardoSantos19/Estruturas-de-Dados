#include "header.h"
#include <time.h>
#include <stdio.h>

#include <conio.h>

#include <stdlib.h>

//variaveis de controle
    clock_t t=0;
    clock_t tmq=0;
    clock_t tmb=0;
    clock_t tms=0;
    int run= 10;

//variaveis do vetor
    const int tam=30;
    int vo[30];
    int vcr[30];
    int vdc[30];
    int vq[30];
    int vb[30];
    int vs[30]; 
    int arr[30];

void printV(int* v){
    //Printa Vetor
    for(int i=0; i<tam; i++){
        printf("%d, ", v[i]);
    }
    printf("\n");
}

void clonaV(int* v1, int* v2){
    //Clona o Vetor
        for (int i=0; i<tam; i++){
            v2[i] = v1[i];
        }
}

void selectionSortDecrescente(int* v, int tam) {
    clonaV(v, arr);

    for (int i = 0; i < tam - 1; i++) {
        // Assume que o primeiro elemento não ordenado é o maior
        int indiceMaior = i;

        // Encontra o maior elemento na parte não ordenada
        for (int j = i + 1; j < tam; j++) {
            if (arr[j] > arr[indiceMaior]) {  // Troca o sinal para '>' para ordem decrescente
                indiceMaior = j;
            }
        }

        // Troca o maior elemento encontrado com o primeiro elemento não ordenado
        if (indiceMaior != i) {
            int temp = arr[i];
            arr[i] = arr[indiceMaior];
            arr[indiceMaior] = temp;
        }

        for (int i=0; i<tam; i++){
            vdc[i] = arr[i];
        }
    }
    printf("Vetor Decrescente: ");
    printV(vdc);
}

void selectionSortCrescente(int* v, int tam) {
    clonaV(v, arr);

    for (int i = 0; i < tam - 1; i++) {
        // Assume que o primeiro elemento não ordenado é o menor
        int indiceMenor = i;

        // Encontra o menor elemento na parte não ordenada
        for (int j = i + 1; j < tam; j++) {
            if (arr[j] < arr[indiceMenor]) {  // Troca o sinal para '<' para ordem crescente
                indiceMenor = j;
            }
        }

        // Troca o menor elemento encontrado com o primeiro elemento não ordenado
        if (indiceMenor != i) {
            int temp = arr[i];
            arr[i] = arr[indiceMenor];
            arr[indiceMenor] = temp;
        }

        for (int i=0; i<tam; i++){            
            vcr[i] = arr[i];
        }
    }
    printf("Vetor Crescente: ");
    printV(vcr);
}


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
                //printf("%d ", v[k]);
            }
            //printf("\n");
        }while (a <= b);

        //troca pivo

        v[0] = v[b];
        v[b] = x;

        //Ordena subv-vetores restantes
        //Recursividade

        QuickSort(v, b);
        QuickSort(&v[a], tam -a);
        for (k=0; k<j; k++){
            //printf("%d ", v[k]);
        }
        //printf("\n");
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
                //printf("%d ", v[k]);
            }
            //printf("\n");
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
                    //printf("%d ", v[k]);
                }
                //printf("\n");
            }

            
        }
    }while (trocou);
}


//execução dos algoritimos
void resultPrint(char lable[20], double tcr, double tdc, double tvo){
    printf("===========================================\n");
    printf("%s: \n", lable);
    printf("===========================================\n");
    printf("Vetor Crescente: ");
    printV(vcr);
    printf("-------------------------------------------\n");
    printf("Tempo medio de execucao do algoritmo: %.2lfms\n", ((double)tcr/run));
    printf("-------------------------------------------\n");
    printf("Vetor decrescente: ");
    printV(vdc);
    printf("-------------------------------------------\n");
    printf("Tempo medio de execucao do algoritmo: %.2lfms\n", ((double)tdc/run));
    printf("-------------------------------------------\n");
    printf("Vetor aleatório: ");
    printV(vo);
    printf("-------------------------------------------\n");
    printf("Tempo medio de execucao do algoritmo: %.2lfms\n", ((double)tvo/run));
    printf("-------------------------------------------\n\n");  
}

void runBobbleSort() {
    
    double tcr;
    for (int i=0; i<run; i++){

        clonaV(vcr, vb);

        t = clock();
        BubbleSort(vb, tam);
        tcr += (clock() - t);
    }


    double tdc;
    for (int i=0; i<run; i++){

        clonaV(vdc, vb);

        t = clock();
        BubbleSort(vb, tam);
        tdc += (clock() - t);
    }

    double tvo;
    for (int i=0; i<run; i++){

        clonaV(vo, vb);

        t = clock();
        BubbleSort(vb, tam);
        tvo += (clock() - t);
    }
    tmb = tcr + tdc + tvo;

    resultPrint("Ordenacao BubbleSort", tcr, tdc, tvo);
}

void runSelectionSort(){
    //Run SelectionSort
    double tcr;
    for (int i=0; i<run; i++){

        clonaV(vcr, vs);

        t = clock();
        SelectionSort(vs, tam);
        tcr += (clock() - t);
    }

    double tdc;
    for (int i=0; i<run; i++){

        clonaV(vdc, vs);

        t = clock();
        SelectionSort(vs, tam);
        tdc += (clock() - t);
    }

    double tvo;
    for (int i=0; i<run; i++){

        clonaV(vo, vs);

        t = clock();
        SelectionSort(vs, tam);
        tvo += (clock() - t);
    }
    tms = tcr + tdc + tvo;

    resultPrint("Ordenacao SelectionSort", tcr, tdc, tvo);
}

void runQuickSort(){
    //Run QuickSort
    double tcr;
    for (int i=0; i<run; i++){

        clonaV(vcr, vq);

        t = clock();
        QuickSort(vq, tam);
        tcr += (clock() - t);
    }

    double tdc;
    for (int i=0; i<run; i++){

        clonaV(vdc, vq);

        t = clock();
        QuickSort(vq, tam);
        tdc += (clock() - t);
    }

    double tvo;
    for (int i=0; i<run; i++){

        clonaV(vo, vq);

        t = clock();
        QuickSort(vq, tam);
        tvo += (clock() - t);
    }
    tmq = tcr + tdc + tvo;
    resultPrint("Ordenacao QuickSort", tcr, tdc, tvo);
}

void gerVetores() {
    //Gerador de Vetores
    int i=0;
    srand(time(NULL));
    for (i=0; i<tam; i++){
        vo[i] = rand() % 100;
    }
    printf("===========================================\n");
    printf("Gerando Vetores\n");
    printf("===========================================\n");
    printf("Vetor Original: ");
    printV(vo);

    //ordena o vetor de forma crescente
    selectionSortCrescente(vo, tam);
    //ordena o vetor de forma decrescente
    selectionSortDecrescente(vo, tam);
    printf("\n*****   Pressione enter para proceguir   *****:");
    getchar();
}

//Gerador de Dados
void Ger(){   

    clock_t tempo_max = 1;

    gerVetores();    
    runBobbleSort();
    runSelectionSort();  
    runQuickSort();

    // Logica de controle de tempo maximo no gerador de ranking 

    if (tmb >= tmq && tmb >= tms) {
        tempo_max += tmb;
    } else if (tmq >= tmb && tmq >= tms) {
        tempo_max += tmq;
    } else {
        tempo_max += tms;
    }
    
    printf("===========================================================================\n");
    printf("===========================================================================\n");

    printf("Execucao de algoritmos comcluida com sucesso, %d rodadas por algoritimo!", run);
    printf("\nTotal de execucoes: %d", (run*3));
    printf("\n===========================================================================\n");
    printf("===========================================================================");
    printf("\n*********************************************************************************************\n\n\n\n\n\n\n\n"); 
    printf("*****Pressione enter para exibir resultados*****:");

    printf("Execucao de algoritmos comcluida com sucesso, %d rodadas por algoritimo!\n", run);
    printf("Total de execucoes: %d\n", (run*3*3));
    printf("===========================================================================\n");
    printf("===========================================================================\n");
    printf("\n*****   Pressione enter para exibir resultados   *****:\n");

    getchar();
    

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

              

                printV(vo);

                printf("\n-------------------------------------------\n");
                printf("Tempo total de execucao: %.2lfms", (double)tmq);
                printf("\n-------------------------------------------\n");
                printf("-------------------------------------------\n");
                printf("Tempo medio de execucao do algoritmo: %.2lfms", ((double)tmq/run*3));
                printf("\n===========================================\n\n\n");
                tmq=tempo_max;
                if (i5 != 3) {
                    printf("\n\n*****Pressione enter para exibir proximo do ranking*****:");
                    getchar();
                }
            }else {
                ///Report Média BubbleSort
                printf("\n\n\n===========================================\n");
                printf("Ordenacao BobbleSort: N-%d",i5);
                printf("\n===========================================\n");
                printf("Vetor Original: ");

          

                printV(vo);

                printf("\n-------------------------------------------\n");
                printf("Tempo total de execucao: %.2lfms", (double)tmb);
                printf("\n-------------------------------------------\n");
                printf("-------------------------------------------\n");
                printf("Tempo medio de execucao do algoritmo: %.2lfms", ((double)tmb/run*3));
                printf("\n===========================================\n\n\n");
                tmb=tempo_max;
                if (i5 != 3) {
                    printf("\n\n*****Pressione enter para exibir proximo do ranking*****:");
                    getchar();
                }
            }
        }else {
            if (tms<=tmb) {
                //Report Média SelectionSort
                printf("\n\n\n===========================================\n");
                printf("Ordenacao SelectionSort: N-%d",i5);
                printf("\n===========================================\n");
                printf("Vetor Original: ");

               

                printV(vo);

                printf("\n-------------------------------------------\n");
                printf("Tempo total de execucao: %.2lfms", (double)tms);
                printf("\n-------------------------------------------\n");
                printf("-------------------------------------------\n");
                printf("Tempo medio de execucao do algoritmo: %.2lfms", ((double)tms/run*3));
                printf("\n===========================================\n\n\n");
                tms=tempo_max;
                if (i5 != 3) {
                    printf("\n\n*****Pressione enter para exibir proximo do ranking*****:");
                    getchar();
                }
            } else { 
                ///Report Média BubbleSort
                printf("\n\n\n===========================================\n");
                printf("Ordenacao BobbleSort: N-%d",i5);
                printf("\n===========================================\n");
                printf("Vetor Original: ");

        

                printV(vo);

                printf("\n-------------------------------------------\n");
                printf("Tempo total de execucao: %.2lfms", (double)tmb);
                printf("\n-------------------------------------------\n");
                printf("-------------------------------------------\n");
                printf("Tempo medio de execucao do algoritmo: %.2lfms", ((double)tmb/run*3));
                printf("\n===========================================\n");
                tmb=tempo_max;
                if (i5 != 3) {
                    printf("\n\n*****Pressione enter para exibir proximo do ranking*****:");
                    getchar();

                
                

                }                

            }
        }
    }    
}