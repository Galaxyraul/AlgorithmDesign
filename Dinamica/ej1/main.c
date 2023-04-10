#include <stdio.h>
#include <mm_malloc.h>
int funcion(int* resultados,int numero){
    //Comprobamos que el número no sea cero
    if(numero == 0){
        resultados[numero] = 0;
        return 0;
    }
    //Comprobamos que el valor no haya sido calculado previamente
    if(resultados[numero] != -1){
        return resultados[numero];
    }
    //Calculamos con los anteriores la sumatoria
    int aux = 0;
    for(int i = 0; i < numero;++i){
        aux+= funcion(resultados,i);
    }
    //Realizamos el calculo
    resultados[numero] = numero + (2/numero)*aux;
    return resultados[numero];
}
int main() {
    int* resultados = malloc(sizeof(int) * 50);
    for(int i = 0; i  < 50;++i){
        printf("%d\n",funcion(resultados,i));
    }
}
