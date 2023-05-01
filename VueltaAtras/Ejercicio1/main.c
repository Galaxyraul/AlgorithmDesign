#include <stdio.h>
#include <stdlib.h>
#define NUMDADOS 6
void muestraSolucion(int* v){
    for (int i = 0; i < NUMDADOS; ++i) {
        printf("%d",v[i]);
    }
    printf("\n");
}
int factible(int dados,int cantidad,int comprobar){
    //Comprobamos que el valor no se pase y que si sacasemos en los siguientes dados la máxima puntación podríamos obtener combinación
    if(cantidad - comprobar >= 0 && dados * 6 >= cantidad - comprobar && dados < cantidad){
        return 1;
    }
    return 0;

}
void combinaciones(int *v,int dados,int cantidad){
    if(cantidad == 0 && dados == 0){
        muestraSolucion(v);
    } else{
        for(int i = 1; i <= 6;++i){
            if(factible(dados - 1,cantidad,i)){
                v[NUMDADOS - dados] = i;
                combinaciones(v,dados - 1,cantidad-i);
            } else{
                break;
            }
        }
    }
}
int main() {
    int *v = malloc(sizeof(int) * NUMDADOS);
    combinaciones(v,NUMDADOS,5);
    free(v);
    return 0;
}
