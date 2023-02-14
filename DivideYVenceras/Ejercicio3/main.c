#include <stdio.h>
int clasico(int* v, int izq, int der){

}
//Potencial de mejora?
int mayoritarioDYV(int* v,int izq,int der){
    if(izq == der){
        return izq;
    }else{
        int mid = (der -  izq)/ 2;
        int mayoritarioIzq = mayoritarioDYV(v,izq,izq + mid);
        int mayoritarioDer = mayoritarioDYV(v,izq + mid + 1,der);
        int numDer = 0;
        int numIzq = 0;
        if(mayoritarioDer == mayoritarioIzq){
            return -1;
        }else if(mayoritarioIzq == -1){
            for(int i = izq; i <= der; ++i){
                numDer += v[mayoritarioDer] == v[i] ? 1:0;
            }
        }else if (mayoritarioDer == -1){
            for(int i = izq; i <= der; ++i){
                numIzq += v[mayoritarioIzq] == v[i] ? 1:0;
            }
        }else{
            for(int i = izq; i <= der; ++i){
                numDer += v[mayoritarioDer] == v[i] ? 1:0;
                numIzq += v[mayoritarioIzq] == v[i] ? 1:0;
            }
        }
        double half = (der - izq + 1)/2.0;
        if(numDer > numIzq){return numDer > half? mayoritarioDer : - 1;}
        else{return numIzq > half? mayoritarioIzq : - 1;}
    }
}
int main() {
    int v[] = {1,1,2,2,2,4,2};
    int mayor = mayoritarioDYV(v,0,6);
    if(mayor != -1){
        printf("%d",v[mayor]);
    } else{
        printf("No hay mayoritario");
    }

    return 0;
}