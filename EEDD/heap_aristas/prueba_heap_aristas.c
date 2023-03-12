/**	programa de prueba de heap_aristas
	
	@file		prueba_heap_aristas.c
	@brief		Programa de prueba del TDA Heap_aristas. Crea un heap a partir de un vector de aristas
	@author		Manuel García Vega
	@date		09/11/2009
	@see		heap_aristas.h
	@par Utilización
		Ejecuta el programa
*/

#include <stdio.h>
#include <stdlib.h>
#include "heap_aristas.h"

#define NROARISTAS 15

int fcomp(heap_aristas_tbase *a,heap_aristas_tbase *b){
	
	return a->peso-b->peso;
}

int main() {
	
	heap_aristas aristas; /**< heap de prueba */

	heap_aristas_tbase vector_init[NROARISTAS], arista;
	
	int i;
	
	for (i=0;i<NROARISTAS;i++) {
		arista.origen = rand()%NROARISTAS+1;
		arista.destino = rand()%NROARISTAS+1;
		arista.peso = rand()%(2*NROARISTAS)+1;
		vector_init[i] = arista;
	}
	printf("a por el heap...\n");
	aristas = heap_aristas_crea(vector_init, NROARISTAS, fcomp);
	printf("imprimiendo...\n");
	heap_aristas_printf(aristas);
	printf("destruyendo...\n");
	heap_aristas_destruye(&aristas);
}
