#include <stdio.h>
#include <malloc.h>
int Stern(int *v,int numCalcular){
    if(v[numCalcular] != -1){
        return v[numCalcular];
    }
    int aux;
    if(numCalcular % 2 == 0){
        aux = (Stern(v,numCalcular/2));
        v[numCalcular] = aux;
        return aux;
    }
    aux = Stern(v,(numCalcular - 1)/2) + Stern(v,1 + (numCalcular - 1)/2);
    v[numCalcular] = aux;
    return aux;
}
int main() {
    int numCalcular = 13;
    int* resultados = malloc(sizeof (int) * (numCalcular + 1));
    for(int i = 0; i < numCalcular + 1;++i){
        resultados[i] = -1;
    }
    resultados[0] = 0;
    resultados[1] = 1;
    Stern(resultados,numCalcular);
    printf("%d",resultados[numCalcular]);
    free(resultados);
    return 0;
}
