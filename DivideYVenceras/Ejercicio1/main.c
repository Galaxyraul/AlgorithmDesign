#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int UMBRAL = 8;
int UMBRAL2 = 1024;
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

int estaSort(int *v,int tam){
    int valor = 1;
    for(int i = 0; i < tam - 1 && valor == 1; ++i){
       valor = v[i] > v[i+1]? 0:1;
    }
    return valor;
}
void mostrarResultado(int *v, int tam){
    for (int i = 0; i < tam; ++i){
        printf("%d\n",v[i]);
    }
    printf("\n");
}
int busquedaNormal(int *v,int izq,int der,int dato){
    int pos = 0;
    for(int i = izq; i <= der && v[pos] != dato ;++i){
        if(dato == v[i]){
            pos = i;
        }
    }
    return v[pos] == dato ? pos: -1;
}
int busquedaTernaria(int *v,int izq,int der,int dato){
    if (der - izq <= UMBRAL2){
        return busquedaNormal(v,izq,der,dato);
    }
    int tercio = (der - izq)/3;
    if(v[izq + tercio] == dato){
        return izq + tercio;
    }
    if (v[izq + tercio] > dato){
        return busquedaTernaria(v,izq,izq+tercio,dato);
    }
    if(v[izq + 2 * tercio] == dato){
        return izq + 2*tercio;
    }
    if (v[izq + 2 * tercio] > dato){
        return busquedaTernaria(v,izq + tercio,izq + 2 * tercio,dato);
    }
    return busquedaTernaria(v,izq + 2 * tercio,der,dato);
}
int main() {
    int tam = 259918;//Valor maximo de enteros que puede tener
    srand(28);
    int v[tam];
    for(int i = 0; i < tam; ++i){
        v[i] = rand();
    }
    mergesort(v,0,tam - 1);
    if(estaSort(v,tam)){
        printf("Esta ordenado");
    } else{ printf("No esta ordenado");}
    printf("\n%d", busquedaTernaria(v,0,tam - 1,80));
    return 0;
}

