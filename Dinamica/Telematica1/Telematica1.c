#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define FILAS 5
#define COLUMNAS 33
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
    for (int j = 0; j < FILAS - 1; ++j) {
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
    for(int i = 1; i < FILAS; ++i){
        for(int j = 1; j < COLUMNAS;++j){
            if(sellos[i - 1] > j ){
                matriz[i][j] = matriz[i-1][j];
            } else{
                matriz[i][j] = matriz[i-1][j] + matriz[i][j-sellos[i - 1]];
            }
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
    for (int i = 0; i < COLUMNAS; ++i) {
            matriz[0][i] = 0;
    }
    for(int i = 1; i < FILAS;++i){
        matriz[i][0] = 1;
    }
    quickSort(sellos,0,FILAS - 1);
    muestraSellos(sellos);
    formas(matriz,sellos);
    muestraMatriz(matriz);
    for (int i = 0; i < FILAS; ++i){
        free(matriz[i]);
    }
    free(matriz);
    free(sellos);
    return 0;
}
