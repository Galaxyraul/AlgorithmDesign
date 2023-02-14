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
int sumaDYV(int* v,int izq ,int der,int menor,int mayor){
    if(izq == der){
        return ((v[izq] != mayor) && (v[izq] != menor) )? v[izq] : 0;
    } else{
        int mid = (izq + der) / 2;
        return sumaDYV(v,izq,mid,menor,mayor) + sumaDYV(v,mid + 1,der,menor,mayor);
    }
}

int main() {
    int mayor;
    int menor;
    int v[] = {8,7,6,5,4,1};
    mayorMenorDYV(v,0,5,&menor,&mayor);
    printf("la suma es:%d", sumaDYV(v,0,5,menor,mayor));
    return 0;
}
