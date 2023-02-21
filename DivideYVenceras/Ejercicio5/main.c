#include <stdio.h>
#include "imatriz2d.h"
#include <stdlib.h>
#define Filas 8
#define Columnas 8
int clasico(imatriz2d m, int xinicio, int yfin,int filas,int columnas, int valorA, int valorB){
    int suma = 0;
    for(int i = xinicio; i < xinicio + filas; ++i){
        for(int j = yfin; j <yfin + columnas; ++j){
            suma += (m[i][j] >= valorA && m[i][j] <= valorB )? 1:0;
        }
    }
    return suma;
}
int valoresIntervalo(imatriz2d m, int xinicio, int yfin,int filas,int columnas, int valorA, int valorB){
    if(filas * columnas == 4){ clasico(m,xinicio,yfin,filas,columnas,valorA,valorB);}
    else{
        filas = filas/4;
        columnas = columnas/4;
        return  valoresIntervalo(m,xinicio,yfin,filas,columnas,valorA,valorB) +
        valoresIntervalo(m,xinicio + columnas,yfin,filas,columnas,valorA,valorB) +
        valoresIntervalo(m,xinicio,yfin + columnas,filas,columnas,valorA,valorB) +
        valoresIntervalo(m,xinicio + columnas,yfin + columnas,filas,columnas,valorA,valorB);
    }
}

int main() {
    srand(28);
    imatriz2d matriz = icreamatriz2d(Filas,Columnas);
    for(int i = 0; i < Filas;++i){
        for(int j = 0; j < Columnas; ++j){
            matriz[i][j] = rand();
        }
    }
    for(int i = 0; i < Filas;++i){
        for(int j = 0; j < Columnas; ++j){
            printf("%d\n",matriz[i][j]);
        }
    }
    printf("El número de valores entre A y B es:%d", valoresIntervalo(matriz,0,0,Filas,Columnas,0,9889));
    ifreematriz2d(&matriz);
}
