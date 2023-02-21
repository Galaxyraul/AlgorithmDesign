#include <stdio.h>
#include <stdlib.h>

int rangoNotas(int* v,int izq,int der,int* start,int* end){
    if(der - izq == 1){
        //Si ambos son mayores que 0 devolvermos la suma de ambos y los asignamos
        if(v[izq] > 0 && v[der] > 0){
            *start = izq;
            *end = der;
            return v[izq] + v[der];
        }
        //En caso de que alguno sea 0 comprobamos izquierda y derecha
        if(v[izq] > 0){
            *start = *end = izq;
            return v[izq];
        }
        if(v[der] > 0){
            *start=*end = der;
            return v[der];
        }
        //En caso de que ambos sean 0 posiciones a -1 y devolvemos 0
        *start = *end = - 1;
        return 0;
    }else if (der - izq == 0){
        if(v[izq] > 0){
            *start = *end = izq;
            return v[izq];
        } else{
            *start = *end = -1;
            return 0;
        }
    }else{
        int mid = (izq + der)/2;
        int sDer,eDer;
        //Hacemos la recursividad
        int sumaIzq = rangoNotas(v,izq,mid,start,end);
        int sumaDer = rangoNotas(v,mid + 1,der,&sDer,&eDer);
        //Calculamos el centro la secuencia
        int sumaMid = 0;
        int sumaAux = 0;
        int izqMid,derMid;
        for(int i = mid; i >= izq; --i ){
            sumaAux += v[i];
            if(sumaAux > sumaMid){
                sumaMid = sumaAux;
                izqMid = i;
            }
        }
        sumaAux = sumaMid;
        for(int i = mid + 1; i <= der; ++i){
            sumaAux += v[i];
            if(sumaAux > sumaMid){
                sumaMid = sumaAux;
                derMid = i;
            }
        }
        //Comparamos y asignamos
        if(sumaDer > sumaIzq){
            if(sumaDer > sumaMid){
                *start = sDer;
                *end = eDer;
                return sumaDer;
            }
            *start = izqMid;
            *end = derMid;
            return sumaMid;
        }
        if(sumaIzq > sumaMid){
            return sumaIzq;
        }
        *start = izqMid;
        *end = derMid;
        return sumaMid;
    }

}
int main() {
    int tam = 28;
    srand(28);
    int v[tam];
    for (int i = 0; i < tam; ++i) {
        v[i] = rand() % 201 - 100;
    }

    int ini,fin;
    int nota = rangoNotas(v,0,27,&ini,&fin);
    printf("El rango de días que se obtiene la mayor nota es:%d - %d con una nota de:%d",ini + 1,fin + 1,nota);
    return 0;
}
