#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define  NUM_FILAS 2
#define  NUM_BOMBILLAS 3
#define  NUM_COLUMNAS 10

void mostrarResultado(int **v){
    for(int i = 0; i < NUM_COLUMNAS;++i){
        printf("%d ",v[0][i]) ;
    }
    printf("\n");
    for(int i = 0; i < NUM_COLUMNAS;++i){
        printf("%d ",v[1][i]) ;
    }
}
int selector(int **candidatos,int *bombillas,int cambiar){

}
int main() {
    srand(28);
    int dia = 0;
    int *bombillas = malloc(NUM_BOMBILLAS * sizeof (int));
    int **v = malloc(NUM_FILAS * sizeof (int *));
    for(int i = 0; i < NUM_FILAS; ++i){
        v[i] = malloc(NUM_COLUMNAS * sizeof (int));
    }
    for(int i = 0; i < NUM_COLUMNAS;++i){
        v[0][i] = 0;
        v[1][i] = rand() % 5 + 1;
    }
    int bombillasRestantes = NUM_COLUMNAS;
    while(bombillasRestantes){
        dia++;
        for(int i = 0; i < NUM_BOMBILLAS; ++i) {
            bombillas[i]--;
            if (bombillas[i] == 0) {
                selector(v, bombillas, i);
                bombillasRestantes--;
            }
        }
    }
    mostrarResultado(v);
    for(int i = 0; i < NUM_FILAS;++i){
        free(v[i]);
    }
    free(v);
    free(bombillas);
}
