#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
void seleccion(int **v,int reloj){
    float pesoMayor = 0;
    int pos = 0;
    for(int i = 0; i < 10; ++i){
        while(v[0][i] || v[1][i] < reloj){i++;}
        float peso = v[2][i] / (float)((v[1][i] - reloj) + 1);
        if(peso > pesoMayor){
            pesoMayor = peso;
            pos = i;
        }
    }
    v[0][pos] =1;
    printf("El pedidido elegido ha sido el que se encuentra en la posición %d con un precio de %d y un instante de entrega %d\n",pos,v[2][pos],v[1][pos]);
}
int main() {
    srand(28);
    int reloj = 1;
    int **v = malloc(3);
    v[0] = malloc(10 * sizeof(int));
    v[1] = malloc(10 * sizeof(int));
    v[2] = malloc(10 * sizeof(int));
    for(int i = 0;i < 10; ++i){
        v[0][i] = 0 ;
        v[1][i] = rand() % 5 + 1 ;
        v[2][i] = rand() % 80 + 20;
    }
    for(int i = 0;i < 10; ++i){
        printf("%d \t",v[0][i]);

    }
    printf("\n");
    for(int i = 0;i < 10; ++i){
        printf("%d \t",v[1][i]);
    }
    printf("\n");
    for(int i = 0;i < 10; ++i){
        printf("%d \t",v[2][i]);

    }
    printf("\n");
    while (reloj <= 5){
        seleccion(v,reloj);
        reloj++;
    }

    free(v[0]);
    free(v[1]);
    free(v[2]);
    free(v);
}
