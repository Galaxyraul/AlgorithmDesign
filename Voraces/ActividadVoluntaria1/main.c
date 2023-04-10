#include <stdio.h>
int selector(int x,int y){
    //Comprobamos que ninguno sea cero
    if(!x || !y){
        return 0;
    }
    //Sacamos la division y el resto
    int num = (x > y? x : y )/ (x > y? y : x);
    printf("Cuadrados de tamaño %d:%d \n",x > y? y : x,num);
    int rem = (x > y? x : y) % (x > y? y : x);
    //Mandamos el menor y el resto
    return num += selector(x > y? y : x,rem);
}
int main() {
    printf("El número total de cuadrados que se ha usado es:%d", selector(9,5));
}
