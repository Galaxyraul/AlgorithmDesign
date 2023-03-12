/***************************************************************/
/*                                                             */
/*    M�dulo en C para uso de objetos en una estructura de     */
/*                                                             */
/*                   CONJUNTOS DISJUNTOS                       */
/*                                                             */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "disjoint.h"

/********************************************************/

disjoint disjoint_nuev(int n) {

	disjoint r;
	int i;

	if (!(r=(int*)malloc(sizeof(int)*n))) {
		fprintf(stderr,"disjoint_nuev: no hay memoria.\n");
		exit(1);
	}
	for (i=0;i<n;i++) r[i]=-1;
	return(r);
}

/********************************************************/

void disjoint_dest(disjoint *c) {
	if (*c) {
		free(*c);
		*c=NULL;
	}
}

/********************************************************/

void disjoint_merge(disjoint c, int a, int b) {

	if (c[a-1]==c[b-1]) {
		c[a-1]-=1;
		c[b-1]=a;
	}
	else if (c[a-1]<c[b-1]) c[b-1]=a;
	else c[a-1]=b;
}

/********************************************************/

int disjoint_find(disjoint c, int x) {

	int r,i;

	r=x;
	while (c[r-1]>0) r=c[r-1];
	i=x;
	while (i!=r) {
		x=c[i-1];
		c[i-1]=r;
		i=x;
	}
	return(r);
}

/********************************************************/

void disjoint_printf(disjoint c,int n) {

	int i;

	for (i=0;i<n;i++) printf("%d ",c[i]);
	printf("\n");
	
}

