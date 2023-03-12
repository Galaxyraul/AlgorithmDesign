/***************************************************************/
/*                                                             */
/*    Módulo en C para uso de objetos en una estructura de     */
/*                                                             */
/*                         VECTOR DINAMICO                     */
/*                                                             */
/***************************************************************/



#include <stdio.h>
#include <stdlib.h>
#include "vdin.h"

#define MAXELEM 20

int main() {
	
	int i, dato;
	
	vdin v;
	
	v=vdin_nuev(sizeof(int));
	for (i=0;i<MAXELEM;i++) 
		vdin_aumd(v,&i);
	
	printf("tamal=%d\n",vdin_tamal(v));
	printf("tamaf=%d\n",vdin_tamaf(v));
	for (i=0;i<MAXELEM;i++) {
		vdin_obti(v,i,&dato);
		printf("%*d",4,dato);
	}
	printf("\n");
	vdin_dest(&v);
}
