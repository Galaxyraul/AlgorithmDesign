#include <stdio.h>
void mayorMenorClasico(const int* v,int izq,int der,int* min,int* max){
    *min = *max = v[izq];
    for(int i = izq + 1; i <= der; ++i){
        *min = *min < v[i]? *min:v[i];
        *max = *max > v[i]? *max:v[i];
    }
}
int sumaClasico(int* v,int izq, int der,int menor,int mayor){
    int suma = 0;
    for(int i = izq; i <= der; ++i){
        suma += ((v[i] != mayor) && (v[i] != menor))? v[i] : 0;
    }
    return suma;
}
void mayorMenorDYV(int* v, int izq,int der,int* min,int* max){
    if(izq == der){
        *min = *max = v[izq];
    }else{
        int minIzq,maxIzq;
        int mid = (der + izq)/2;
        mayorMenorDYV(v,izq,mid,&minIzq,&maxIzq);
        mayorMenorDYV(v,mid + 1,der,min,max);
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
    int v[] = {8,7,6,5,1,1};
    mayorMenorClasico(v,0,5,&menor,&mayor);
    printf("El menor valor es:%d\nEl valor mayor es:%d\n",menor,mayor);
    printf("La suma es:%d\n", sumaClasico(v,0,5,menor,mayor));
    mayorMenorDYV(v,0,5,&menor,&mayor);
    printf("La suma es:%d", sumaDYV(v,0,5,menor,mayor));
    return 0;
}
