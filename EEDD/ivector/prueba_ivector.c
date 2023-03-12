/*************************ivector.c***************************/
/*              Módulo en C para uso de objetos              */
/*                     VECTOR DE ENTEROS                     */
/*************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "ivector.h"

#define TAM 10

int main() {
	
	ivector v;
	int i, k;
	
	v=icreavector(TAM);
	
	for (k=i=0;i<TAM; i++)
		v[i]=++k;
	
	for (i=0;i<TAM; i++) {
		printf("%*d",4,v[i]);
	}
	printf("\n");
	ifreevector(&v);
	return 0;
}
