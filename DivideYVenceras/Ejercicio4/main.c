#include <stdio.h>
void mayorMenorDYV(int* v, int izq,int der,int* min,int* max){
    if(izq == der){
        *min = *max = v[izq];
    }else{
        int minIzq,maxIzq;
        int mid = (der - izq)/2;
        mayorMenorDYV(v,izq,izq + mid,&minIzq,&maxIzq);
        mayorMenorDYV(v,izq + mid + 1,der,min,max);
        *min = *min < minIzq ? *min : minIzq;
        *max = *max > maxIzq ? *max : maxIzq;
    }
}

int main() {
    int mayor;
    int menor;
    int v[] = {8,7,6,5,4,1};
    mayorMenorDYV(v,0,5,&menor,&mayor);
    printf("el menor es:%d\n el mayor es:%d",menor,mayor);
    return 0;
}
