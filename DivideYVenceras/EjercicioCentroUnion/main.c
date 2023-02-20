#include <stdio.h>
int unionCentrosDYV(int* v,int* x, int derV,int izqV,int derX,int izqX){
    if(izqV - derV  == 1){
        if(v[derV] <= x[izqX]){
            return v[derV];
        } else{
            return v[izqV] > x[izqX] ? x[derX] : v[izqV];
        }
    }
    else{

    }
}
int main() {

}
