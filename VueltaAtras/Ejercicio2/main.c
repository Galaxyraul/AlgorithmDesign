#include <stdio.h>
#include <stdlib.h>
#define TAMCONJUNTO  5
void mustraSolucion(int* v,int tam){
    for(int i = 0; i < tam; ++i){
        printf("%d",v[i]);
    }
    printf("\n");
}
int factible(int cantidad,int comprueba){
    if(cantidad - comprueba >= 0){
        return 1;
    }
    return 0;
}
void combinaciones(int*v,int* nums,int cantidad,int pos){
    if(cantidad == 0){
        mustraSolucion(v,pos + 1);
    } else{
        for(int i = 0; i  < TAMCONJUNTO && pos < TAMCONJUNTO;++i){
            if(nums[i] != -1){
                int aux = nums[i];
                nums[i] = -1;
                if(factible(cantidad,aux)){
                    combinaciones(v,nums,cantidad-aux,pos+1);
                }
                nums[i] = aux;
            }
        }
    }
}
int main() {
    int *v = malloc(sizeof (int) * TAMCONJUNTO);
    free(v);
    return 0;
}
