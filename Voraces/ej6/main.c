#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define NUM_BALDAS 5
#define NUM_LIBROS 20
//Elige la balda con menor peso para añadirle el libro
void selector(int *b,int libro){
    int candidata = 0;
    for(int i = 0; i < NUM_BALDAS; ++i){
        candidata = b[i] < b[candidata]? i:candidata;
    }
    b[candidata] += libro;
}
void mostrarResultado(int* b){
    for(int i = 0; i < NUM_BALDAS;++i){
        printf("%d ",b[i]);
    }
}
int main() {
    srand(28);
    int *libros = malloc(NUM_LIBROS * sizeof (int));
    int *baldas = malloc(NUM_BALDAS * sizeof (int));
    for(int i = 0; i < NUM_LIBROS; ++i){
        libros[i] = rand() % 20;
    }
    for(int i = 0; i < NUM_BALDAS;++i){
        baldas[i] = 0;
    }
    for(int i = 0; i < NUM_LIBROS; ++i){
        selector(baldas,libros[i]);
    }
    mostrarResultado(baldas);
    free(libros);
    free(baldas);
}
