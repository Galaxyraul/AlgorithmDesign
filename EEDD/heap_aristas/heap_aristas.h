/**	Módulo de cabeceras del TDA Heap con tipo generalizado.
	
	@file		heap_aristas.h
	@brief		TDA Heap con tipo generalizado. Definición de cabeceras
	@author		Manuel García Vega
	@date		09/11/2009
	@see		heap_aristas.c
	@par Utilización
		Sustituir aristas por una palabra que identifique al tipo base
		Define el tipo base dentro de la estructura "struct heap_aristas_tipo_base"
		Colocar 	#include "heap_aristas.h" en los modulos que vayan a usar el TDA heap.
	@par Ejemplo
		h=heap_aristas_crea();  <---crea un heap 
		if (heap_aristas_vacio(h)) {...}   <---si el heap "h" no tiene elementos....
		dato=heap_aristas_saca(h,compara);   <---saca la raíz del heap y reorganiza el orden

*/

#ifndef __HEAP_aristas_H_
#define __HEAP_aristas_H_

#define __HEAP_aristas_DEBUG_

typedef struct heap_aristas_rep *heap_aristas;


/*define aquí el tipo base */
typedef struct heap_aristas_base {
	int origen; /**< nodo origen de la arista */
	int destino; /**< nodo destino de la arista */
	int peso; /**< peso de la arista */
}heap_aristas_tbase;



heap_aristas heap_aristas_creavacio(int tamf);
heap_aristas heap_aristas_crea(heap_aristas_tbase *vinit, int nelem, int (*fcomp)(heap_aristas_tbase*,heap_aristas_tbase*));
void heap_aristas_destruye(heap_aristas *heap);
int heap_aristas_vacio(heap_aristas heap);
int heap_aristas_lleno(heap_aristas heap);
int heap_aristas_tama(heap_aristas heap);
heap_aristas_tbase heap_aristas_raiz(heap_aristas heap);
heap_aristas_tbase heap_aristas_saca(heap_aristas heap, int (*fcomp)(heap_aristas_tbase *, heap_aristas_tbase *));
void heap_aristas_mete(heap_aristas heap, heap_aristas_tbase dato, int (*fcomp)(heap_aristas_tbase *, heap_aristas_tbase *));
void heap_aristas_printf(heap_aristas heap);

#endif /* __HEAP_aristas_H_ */
