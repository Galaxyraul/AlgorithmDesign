#include <stdio.h>
#include <stdlib.h>
#define TOTALMONEDAS  40
#define NUMMONEDAS 8
void muestraResultado(int*resultado ,int tam){
    int suma = 0;
    for(int i = 0; i < tam;++i){
        suma+=resultado[i];
        printf("%4d",resultado[i]);
    }
    printf(" Suma:%d",suma);
    printf("\n");
}

int factible(int** monedas,int moneda,int cantidad){
    if(monedas[1][moneda] > 0 && cantidad - monedas[0][moneda] >= 0){
        return 1;
    }
    if(monedas[1][moneda] == 0){
        return 2;
    }
    return 0;
}
void combinaciones(int **monedas,int* resultado,int* minlength,int cantidad,int pos){
    if(cantidad > 1000){ return;}
    if(cantidad == 0 && pos < *minlength){
        *minlength = pos ;
        muestraResultado(resultado,pos);
    }else{
        for(int i = 0; i < NUMMONEDAS;++i){
            int aux;
            if(aux= factible(monedas,i,cantidad)){
                if(aux != 2){
                    monedas[1][i]--;
                    resultado[pos] = monedas[0][i];
                    combinaciones(monedas,resultado,minlength,cantidad - monedas[0][i],pos + 1);
                    monedas[1][i]++;
                    resultado[pos] = 0;
                }
            } else{
                break;
            }
        }
    }
}
int main() {
    int** monedas = malloc(2* sizeof (int*));
    monedas[0] = malloc(8 * sizeof  (int));
    monedas[1] = malloc(8 * sizeof (int));
    monedas[0][0] = 1;
    monedas[0][1] = 2;
    monedas[0][2] = 5;
    monedas[0][3] = 10;
    monedas[0][4] = 20;
    monedas[0][5] = 50;
    monedas[0][6] = 100;
    monedas[0][7] = 200;
    int* resultado = malloc((TOTALMONEDAS * sizeof (int)));
    for (int i = 0; i < 8; ++i) {
        monedas[1][i] = 5;
    }
    int minLength = INT_MAX;
    combinaciones(monedas,resultado,&minLength,500,0);
    free(monedas[0]);
    free(monedas[1]);
    free(monedas);
    free(resultado);
    return 0;
}

