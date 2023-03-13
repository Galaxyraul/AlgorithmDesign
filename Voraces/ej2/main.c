#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
void swap(int *v,int a,int b){
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}
int selector(int *v,int num,int pos,int der){ //se puede hacer más facil seguro pensarlo mejor
    int posC;
    int i = pos;
    //Busca posición valida
    while(v[i] < num && i < der){++i;}
    posC = i;
    //Si no la ha encontrado no entra
    while(i < der){
        while(v[i] < num){++i;}
        posC = v[i] - num < v[posC] - num? i:posC;
        i++;
    }
    //Comprueba el valor de resultado para ver si es válido
    if(v[posC] < num){
        printf("Finalizando el programa\n");
        return -1;
    } else{ swap(v,posC,pos);}
    return 0;

}
void mostrarResultado(int *v,int izq,int der){
    for(int i = izq; i <= der;++i){
        printf("%d ",v[i]);
    }
    printf("\n");
}
int main() {
    srand(28);
    int *a = malloc(20*sizeof (int));
    int *v = malloc(20*sizeof (int));
    for(int i = 0; i  < 20; ++i){
        a[i] = rand() % 15;
    }
    srand(15);
    for(int i = 0; i  < 20; ++i){
        v[i] = rand() % 15;
    }
    mostrarResultado(v,0,19);
    mostrarResultado(a,0,19);
    for(int i = 0; i < 20;++i){
        if(selector(a,v[i],i,19)){
            break;
        }
    }
    mostrarResultado(v,0,19);
    mostrarResultado(a,0,19);
    free(v);
    free(a);
}
