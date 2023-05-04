#include <stdio.h>
#include <stdlib.h>
#define K 10
#define TAMRESULT 4
//Raúl Gómez Téllez
int es_potencia_de_dos(int n){
    return (n & (n - 1)) == 0;
}
int suma(int* resultado,int pos){
    int suma = 0;
    for (int i = 0; i < pos; ++i) {
        suma+=resultado[i];
    }
    return suma;
}
void muestraResultado(int *resultado,int pos){
    for (int i = 0; i < pos; ++i) {
        printf("%3d",resultado[i]);
    }
    printf("\n");
}
void combinaciones(int* valores,int *resultado,int pos,int *cont){
    if(pos == 4){
        if(es_potencia_de_dos(suma(resultado,pos))){
            *cont= *cont+1;
            printf("El cuarteto número %d es potencia de 2 con suma:%d\n", *cont, suma(resultado,pos));
            muestraResultado(resultado,pos);
        }
    } else if(pos < 4){
        for (int i = 0; i < K; ++i) {
            resultado[pos] = valores[i];
            combinaciones(valores,resultado,pos + 1,cont);
        }
    }
}
int main() {
    int v[] = {1,2,3,4,5,6,7,8,9,10};
    int *resultado = malloc(TAMRESULT * sizeof (int));
    int cont = 0;
    combinaciones(v,resultado,0,&cont);
    printf("Hello, World!\n");
    free (resultado);
    return 0;
}
