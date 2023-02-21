#include <stdio.h>
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
            }else{
                *start = izqMid;
                *end = derMid;
                return sumaMid;
            }
        }else{
            if(sumaIzq > sumaMid){
                return sumaIzq;
            }else{
                *start = izqMid;
                *end = derMid;
                return sumaMid;
            }
        }
    }

}
int main() {
    printf("Hello, World!\n");
    return 0;
}
