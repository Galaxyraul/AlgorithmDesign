#include <stdio.h>
#include <stdlib.h>
//Reordenar
//Recursividad
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
int main() {
    srand(28);
    int v[8];
    for (int i = 0; i < 8; ++i) {
        v[i] = rand();
    }
    quickSort(v,0,7);
    printf("Hola");
}
