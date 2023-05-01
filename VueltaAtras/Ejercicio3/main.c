#include <stdio.h>
#include <stdlib.h>
#define TAMABECEDARIO 8
int factible(char comprobar,int vocales,int longitud){
    int aux = 0;
    if(longitud + 1 > 5){
        return 0;
    }
    if (comprobar == 'A' || comprobar == 'E' || comprobar == 'I' || comprobar == 'O' || comprobar == 'U'){
        aux = 2;
    }
    if(vocales == 2 && aux){
        return 0;
    }
    if(aux){
        return 2;
    }
    return 1;
}
void muestraSolucion(char* resultado,int longitud){
    for(int i = 0; i  < longitud; ++i){
        printf("%c",resultado[i]);
    }
    printf("\n");
}
void combinaciones(char* abecedario,char* resultado,int vocales,int longitud){
    if(longitud <= 5){
        if(vocales == 2){
            muestraSolucion(resultado,longitud);
        }
        for(int i = 0; i < TAMABECEDARIO; ++i){
            int aux;
            if(aux = factible(abecedario[i],vocales,longitud)){
                resultado[longitud] = abecedario[i];
                if(aux == 2){
                    combinaciones(abecedario,resultado,vocales + 1,longitud + 1);
                }else{
                    combinaciones(abecedario,resultado,vocales,longitud + 1);
                }
            }
        }
    }
}
int main() {
    char *resultado = malloc(sizeof (char) * 5);
    char abecedario[] =  {'1','2','3', 'A', 'E', 'I', 'O', 'U'};
    combinaciones(abecedario,resultado,0,0);
    free(resultado);
    printf("Hello, World!\n");
    return 0;
}
