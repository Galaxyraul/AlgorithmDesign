#include <stdio.h>
void selector(int x,int y){
    //Comprobamos que ninguno sea cero
    if(!x || !y){
        printf("Terminando el programa");
        return;
    }
    //Sacamos la division y el resto
    int num = (x > y? x : y )/ (x > y? y : x);
    printf("Cuadrados de tamaño %d:%d \n",x > y? y : x,num);
    int rem = (x > y? x : y) % (x > y? y : x);
    //Mandamos el menor y el resto
    selector(x > y? y : x,rem);
}
int main() {
    selector(9,5);
}
