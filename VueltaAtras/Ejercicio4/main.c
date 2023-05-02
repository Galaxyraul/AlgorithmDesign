#include <stdio.h>
#define FILAS 21
#define COLUMNAS 21
void muestraResultado (int **tablero,int longitud){
    printf("Camino de longitud %d",longitud);
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            printf("%d",tablero[i][j]);
        }
        printf("\n");
    }
}
int factible(int **tablero,int i,int j,int caminoActual,int masLargo){
    if(caminoActual >= masLargo){
        return 0;
    }
    if(tablero[i][j] == 4 || tablero[i][j] == 0){
        return 1;
    }
    return 0;
}
void combinaciones(int** tablero,int* caminoMasLargo,int longitudCaminoActual,int i,int j){
    if(tablero[i][j] == 4 && longitudCaminoActual < *caminoMasLargo){
        muestraResultado(tablero,*caminoMasLargo);
        *caminoMasLargo = longitudCaminoActual;
    }else{
        int aux = tablero[i][j];
        tablero[i][j] = 2;
        if(factible(tablero,i + 1,j,longitudCaminoActual,*caminoMasLargo)){
            combinaciones(tablero,caminoMasLargo,longitudCaminoActual + 1,i + 1,j);
        }
        if(factible(tablero,i - 1,j,longitudCaminoActual,*caminoMasLargo)){
            combinaciones(tablero,caminoMasLargo,longitudCaminoActual + 1,i - 1,j);
        }
        if(factible(tablero,i,j + 1,longitudCaminoActual,*caminoMasLargo)){
            combinaciones(tablero,caminoMasLargo,longitudCaminoActual + 1,i,j + 1);
        }
        if(factible(tablero,i,j - 1,longitudCaminoActual,*caminoMasLargo)){
            combinaciones(tablero,caminoMasLargo,longitudCaminoActual + 1,i,j - 1);
        }
        tablero[i][j] = aux;
    }
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
