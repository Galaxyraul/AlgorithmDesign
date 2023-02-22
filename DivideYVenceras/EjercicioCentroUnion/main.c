#include <stdio.h>
#include <stdlib.h>
int UMBRAL = 8;
int size = 16;
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
    //Caso minimo de 2 elementos
    if(derV - izqV  == 1){
        if(v[derV] <= x[izqX]){
            return v[derV];
        }
        if(v[izqV] < x[izqX]){
            return  x[izqX];
        }
        return v[izqV] < x[derX]? v[izqV] : x[derX];
    }else{//caso normal
        int mid = (derV - izqV )/ 2;//Calculo la mitad de los elementos para no tener que usar un parámetro más
        return v[izqV + mid] < x[ izqX + mid]? unionCentrosDYV(v,x,izqV + mid + 1,derV,izqX,izqX + mid) : unionCentrosDYV(v,x,izqV,izqV + mid,izqX + mid + 1,derX);
    }
}
int main() {
    int v[size];
    int x[size];
    srand(28);
    for(int i = 0; i < size; ++i){
        v[i] = rand();
        x[i] = rand();
    }
    mergesort(v,0,size - 1);
    mergesort(x,0,size - 1);
    printf("%d", unionCentrosDYV(v,x,0,size - 1,0,size - 1));

}
