#include <stdio.h>
#include <stdlib.h>
int UMBRAL = 8;

void insercion(int *v, int izq,int der){
    for(int i = izq + 1; i <= der;++i){ //bucle para recorrerse todo el vector
        int j = i - 1; //Posicion anterior al indicador
        int iesimo = v[i]; //guardamos el valor en i
        while(j>=izq && v[j] > iesimo){ //bucle para comprobar que el anterior es mayor que el iesimo
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = iesimo;
    }
}
void merge(int* v,int izq,int mid,int der){
    int U [mid - izq + 1];
    int V [der - mid];
    for(int i = izq; i <= mid; ++i){ U[i - izq] = v[i];}
    for(int i = mid + 1; i <= der; ++i){ V[i - mid - 1] = v[i];}
    int tamV = der - mid;
    int tamU = mid - izq + 1;
    int i = izq; int j = 0; int k = 0;
    while(tamV != 0 && tamU != 0){
        if(V[j] > U[k]){v[i] = U[k]; ++k;++i; --tamU;}
        else{v[i] = V[j];++j;++i;--tamV;}
    }
    while(tamU != 0){
        v[i] = U[k];
        ++k;
        --tamU;
        ++i;
    }
    while(tamV != 0){
        v[i] = V[j];
        ++j;
        --tamV;
        ++i;
    }

}

void mergesort(int* v,int izq,int der){
    int tam = der - izq + 1;
    int mid =  izq + (der - izq)/2;
    if(tam <= UMBRAL){ insercion(v,izq,der);}
    else {
        mergesort(v, izq,mid);
        mergesort(v, mid + 1,der);
        merge(v,izq,mid,der);
    }
}
int unionCentrosDYV(int* v,int* x, int izqV,int derV ,int izqX ,int derX){
    if(derV - izqV  == 1){
        if(v[derV] <= x[izqX]){
            return v[derV];
        } else{
            return v[izqV] > x[izqX] ? x[derX] : v[izqV];
        }
    }
    else{
        if(v[derV] < x[izqX]){
            return v[derV];
        }
        if(x[derX] < v[izqV]){
            return x[derX];
        }
        int mid = (izqV - derV )/ 2;
        return v[mid] < x[mid]? unionCentrosDYV(v,x,izqV + mid + 1,izqV,derX,derX + mid): unionCentrosDYV(v,x,derX,derV + mid,izqX + mid + 1,izqX);
    }
}
int main() {
    int v[4];
    int x[4];
    srand(28);
    for(int i = 0; i < 4; ++i){
        v[i] = rand();
        x[i] = rand();
    }
    mergesort(v,0,3);
    mergesort(x,0,3);
    printf("%d", unionCentrosDYV(v,x,0,3,0,3));

}
