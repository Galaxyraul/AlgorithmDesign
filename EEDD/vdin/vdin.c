/***************************************************************/
/*                                                             */
/*    Módulo en C para uso de objetos en una estructura de     */
/*                                                             */
/*                         VECTOR DINAMICO                     */
/*                                                             */
/***************************************************************/


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "vdin.h"

struct vdin_rep {
	long tambase;
	long tamal;
	long tamaf;
	void *vector;
};

/********************************************************************/
/***************   PROCEDIMIENTOS Y FUNCIONES PRIVADOS   ************/
/********************************************************************/

void *vdin_alovector(long tamano, long tambase) {

	void *vector;

	if (!tamano) return(NULL);
	else {
		if ((vector=malloc(tambase*tamano))==NULL) {
			fprintf(stderr,"vdin_alovector: no hay memoria.\n");
			exit(1);
		}
		return(vector);
	}
}

void vdin_dalovector(void *vector) {

	if (vector) free(vector);
}

vdin vdin_alo(long tamano, long tambase) {

	vdin p;

	if ((p=(vdin)malloc(sizeof(struct vdin_rep)))==NULL) {
		fprintf(stderr,"vdin_alo: no hay memoria.\n");
		exit(1);
	}
	p->vector=vdin_alovector(tamano,tambase);
	return(p);
}

void vdin_dalo(vdin *p) {

	if (*p!=NULL) {
		vdin_dalovector((*p)->vector);
		free(*p);
		*p=NULL;
	}
}

/********************************************************************/
/*************  PROCEDIMIENTOS Y FUNCIONES PUBLICOS   ***************/
/********************************************************************/

vdin vdin_nuev(int tambase) {

	vdin x;

	if (tambase<=0) {
		fprintf(stderr,"vdin_nuev: tambase <= 0.\n");
		exit(2);
	}
 	x=vdin_alo(1,tambase);
	x->tambase=tambase;
	x->tamaf=1;
	x->tamal=0;
	return(x);
}

/********************************************************************/

vdin vdin_copia(vdin a) {

	vdin x;

	if (!a) {
		fprintf(stderr,"vdin_copia: el argumento no ha sido creado.\n");
		exit(3);
	}
	x=vdin_alo(a->tamaf,a->tambase);
	x->tambase=a->tambase;
	x->tamaf=a->tamaf;
	x->tamal=a->tamal;
	memcpy(x->vector, a->vector, a->tamal * a->tambase);
	return(x);
}

/********************************************************************/

int vdin_tamal(vdin a) {

	if (!a) {
		fprintf(stderr,"vdin_tamal: el argumento no ha sido creado.\n");
		exit(3);
	}
	return(a->tamal);
}

/********************************************************************/

int vdin_tamaf(vdin a) {

	if (!a) {
		fprintf(stderr,"vdin_tamaf: el argumento no ha sido creado.\n");
		exit(3);
	}
	return(a->tamaf);
}

/********************************************************************/

int vdin_tambase(vdin a) {

	if (!a) {
		fprintf(stderr,"vdin_tambase: el argumento no ha sido creado.\n");
		exit(3);
	}
	return(a->tambase);
}

/********************************************************************/

void vdin_obti(vdin a, int i, void *e) {

	if (!a) {
		fprintf(stderr,"vdin_obti: el argumento no ha sido creado.\n");
		exit(3);
	}
	if (i<0 || i>=a->tamal) {
		fprintf(stderr,"vdin_obti: indice fuera de limites.\n");
		exit(4);
	}
	memcpy(e,(char *)(a->vector)+i*a->tambase,a->tambase);
}

/********************************************************************/

void vdin_asig(vdin a, int i, void *e) {

	if (!a) {
		fprintf(stderr,"vdin_asig: el argumento no ha sido creado.\n");
		exit(3);
	}
	if (i<0 || i>=a->tamal) {
		fprintf(stderr,"vdin_asig: indice fuera de limites.\n");
		exit(4);
	}
	memcpy((char *)(a->vector)+i*a->tambase,e,a->tambase);
}

/********************************************************************/

void vdin_aumd(vdin a, void *e) {

	void *b;

	if (!a) {
		fprintf(stderr,"ardi_[tip]_aumd: el argumento no ha sido creado.\n");
		exit(3);
	}
	if (a->tamal==a->tamaf) {
		a->tamaf*=2;
		if (a->tamaf>0) {
			b=vdin_alovector(a->tamaf,a->tambase);
			memcpy(b, a->vector, a->tamal * a->tambase);
			vdin_dalovector(a->vector);
			a->vector=b;
		}
		else {
			fprintf(stderr,"ardi_[tip]_aumd: máximo sobrepasado.\n");
			exit(5);
		}
	}
	memcpy((char *)(a->vector)+a->tamal*a->tambase,e,a->tambase);
	a->tamal++;


	
}

/********************************************************************/

void vdin_disd(vdin a, void *e) {

	void *b;

	if (!a) {
		fprintf(stderr,"vdin_disd: el argumento no ha sido creado.\n");
		exit(3);
	}
	if (!a->tamal) {
		fprintf(stderr,"vdin_disd: el vector tiene tamaño 0.\n");
		exit(6);
	}
	a->tamal--;
	memcpy(e,(char *)(a->vector)+a->tamal*a->tambase,a->tambase);
	if (a->tamal==a->tamaf/2 && a->tamal>0) {
		a->tamaf/=2;
		b=vdin_alovector(a->tamaf,a->tambase);
		memcpy(b, a->vector, a->tamal * a->tambase);
		vdin_dalovector(a->vector);
		a->vector=b;
	}
}

/********************************************************************/

void vdin_dest(vdin *a) {

	if (!*a) {
		fprintf(stderr,"vdin_dest: el argumento no ha sido creado.\n");
		exit(3);
	}
	vdin_dalo(a);
}

/********************************************************************/

void vdin_swap(vdin a, int l, int r) {

	void *temp;

	if (!a) {
	fprintf(stderr,"vdin_swap: el argumento no ha sido creado.\n");
		exit(3);
	}
	if (a->tamal==0) {
		fprintf(stderr,"vdin_swap: el vector tiene tamaño 0.\n");
		exit(6);
	}
	if (l<0 || l>=a->tamal) {
		fprintf(stderr,"vdin_swap: indice 'l' fuera de rango.\n");
		exit(4);
	}
	if (r<0 || r>=a->tamal) {
		fprintf(stderr,"vdin_swap: indice 'r' fuera de rango.\n");
		exit(4);
	}
	temp=malloc(a->tambase);
	memcpy(temp,(char *)(a->vector)+l*a->tambase,a->tambase);
	memcpy((char *)(a->vector)+l*a->tambase,(char *)(a->vector)+r*a->tambase,a->tambase);
	memcpy((char *)(a->vector)+r*a->tambase,temp,a->tambase);
	free(temp);
}

/********************************************************************/

int vdin_bbin(vdin a, void *e, int (*compar) (const void *, const void *)) {

	void *t;

	if (!a) {
		fprintf(stderr,"vdin_bbin: el argumento no ha sido creado.\n");
		exit(3);
	}
	if (!a->tamal) {
		fprintf(stderr,"vdin_bbin: el vector tiene tamaño 0.\n");
		exit(6);
	}
	t=bsearch(e,a->vector,a->tamal,a->tambase, compar);
	if (!t) return(-1);
	else return(((char *)t-(char *)(a->vector))/a->tambase);
}

/********************************************************************/

int vdin_blseq(vdin a, void *e,int (*compar) (const void *, const void *)) {

   int i;

	if (!a) {
		fprintf(stderr,"vdin_blseq: el argumento no ha sido creado.\n");
		exit(3);
	}
	if (a->tamal)
		for (i=0;i<a->tamal;i++)
			if (!compar((char *)(a->vector)+i*a->tambase,e)) return(i);
	return(-1);
}

/********************************************************************/

int vdin_brseq(vdin a, void *e,int (*compar) (const void *, const void *)) {

	int i;

	if (!a) {
		fprintf(stderr,"vdin_brseq: el argumento no ha sido creado.\n");
		exit(3);
	}
	if (a->tamal)
		for (i=a->tamal-1;i>=0;i--)
			if (!compar((char *)(a->vector)+i*a->tambase,e)) return(i);
	return(-1);
}

/********************************************************************/

void vdin_qsort(vdin a,int (*compar) (const void *, const void *)) {

	if (!a) {
		fprintf(stderr,"vdin_qsort: el argumento no ha sido creado.\n");
		exit(3);
	}
	if (!a->tamal) {
		fprintf(stderr,"vdin_qsort: el vector tiene tamaño 0.");
		exit(6);
	}
	qsort(a->vector,a->tamal,a->tambase,compar);
}
