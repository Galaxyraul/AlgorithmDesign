#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define FILAS 7
#define COLUMNAS 12
int buscaPivote(int *v,int izq,int der){
    for(int i = izq; i < der;++i){
        if(v[i] < v[i + 1]){return i + 1;}
        else if(v[i] > v[i + 1]){return i;}
    }
    return -1;
}
int swap(int *v,int i,int j){
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}
int reordena(int* v,int izq,int der,int pivote){

    do {
        swap(v,izq,der);
        while(v[izq] < pivote){izq++;}
        while(v[der] >= pivote ){der--;}
    } while (izq <= der);
    return izq;
}
void quickSort(int* v,int izq,int der){
    int k,pivote;
    pivote = buscaPivote(v,izq,der);
    if(pivote != -1){
        k = reordena(v,izq,der,v[pivote]);
        quickSort(v,izq,k-1);
        quickSort(v,k,der);
    }
}
void muestraSellos(int * sellos){
    for (int j = 0; j < FILAS; ++j) {
        printf("%3*d",sellos[j]);
    }
    printf("\n");
}
void muestraMatriz(int **matriz){
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            printf("%3*d",matriz[i][j]);
        }
        printf("\n");
    }
}
void formas(int **matriz,int* sellos){
    for(int i = 0; i < FILAS; ++i){
        for(int j = 0; j < COLUMNAS;++j){

        }
    }
}
int main() {
    srand(28);
    int **matriz = malloc(FILAS * sizeof(int*));
    for (int i = 0; i < FILAS; ++i) {
        matriz[i] = malloc(COLUMNAS * sizeof (int));
    }
    int* sellos = malloc(FILAS * sizeof(int));
    for(int i = 0; i < FILAS;++i){
        sellos[i] = rand() % 15 + 1;
    }
    //Inicializamos a -1 la matriz para indicar que no hay datos
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            matriz[i][j] = 0;
        }
    }
    quickSort(sellos,0,FILAS - 1);
    muestraSellos(sellos);
    muestraMatriz(matriz);

    for (int i = 0; i < FILAS; ++i){
        free(matriz[i]);
    }
    free(matriz);
    free(sellos);
    return 0;
}
