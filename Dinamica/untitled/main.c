#include <stdio.h>
#include <malloc.h>
int Q(int **matriz,int* vector,int m,int n){
    if(m == 0 || n == 0){
        return 1;
    }
    if(matriz[m][n] != -1 ){
        return matriz[m][n];
    }
    int aux = 0;
    if(n < vector[m]){
        aux = Q(matriz,vector,m - 1,n);
    }else{
        for (int i = 1; i < vector[m] ; ++i) {
            aux+= Q(matriz,vector,m,n-i);
        }
    }
    matriz[m][n] = aux;
    return aux;
}
void mostrarMatriz(int **matriz){
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                printf("%3d",matriz[i][j]);
            }
            printf("\n");
        }
}
int main() {
    int vector[5] = {1,2,3,4,5};
    int** matriz = malloc(sizeof (int*) * 5);
    for (int i = 0; i < 5; ++i) {
        matriz[i] = malloc(sizeof (int) * 5);
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            matriz[i][j] = -1;
        }
    }
    for (int i = 0; i < 5; ++i) {
        matriz[0][i] = 1;
    }
    for (int i = 0; i < 5; ++i) {
        matriz[i][0] = 1;
    }
    printf("%d",Q(matriz,vector,4,4));
    mostrarMatriz(matriz);
    return 0;
}
