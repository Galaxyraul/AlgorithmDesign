/**	Módulo de primitivas del TDA Heap con tipo generalizado.
	
	@file		heap_aristas.c
	@brief		TDA Heap con tipo generalizado. Implementación de primitivas y representación
	@author		Manuel García Vega
	@date		09/11/2009
	@see		heap_aristas.h
	@par Utilización
		Sustituir aristas por una palabra que identifique al tipo base
		Incluir "heap_aristas.c" en la compilación del proyecto.
		renombra los archivos [ tip ] por la palabra que identifica el tipo base
	@par Ejemplo
		h=heap_aristas_crea();  <---crea un heap 
		if (heap_aristas_vacio(h)) {...}   <---si el heap "h" no tiene elementos....
		dato=heap_aristas_saca(h,compara);   <---saca la raíz del heap y reorganiza el orden

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "depuracion.h"
#include "heap_aristas.h"

struct heap_aristas_rep {
	int tamf; /**< tamaño físico del vector. es invariante durante la ejecución */
	int taml; /**< tamaño lógico del vector. varía según se meten o sacan elementos del heap */
	heap_aristas_tbase *v; /**< vector que soporta los datos del heap */
};

/* --------------------------- Primitivas privadas -------------------------- */

void __heap_aristas_intercambia(heap_aristas heap, int pos1, int pos2) {
	heap_aristas_tbase tmp_paso;
	tmp_paso = heap->v[pos1];
	heap->v[pos1] = heap->v[pos2];
	heap->v[pos2] = tmp_paso;
}

void __heap_aristas_hunde(heap_aristas heap, int elemento, int (*fcomp)(heap_aristas_tbase*,heap_aristas_tbase*)){
	int i, j;

	i=elemento+1;
	do {
		j=i;		
		if (2*j <= heap->taml)
			/* si tiene hijo de la izquierda */
			if (fcomp(&heap->v[i-1], &heap->v[2*j-1]) > 0)
				i = 2*j;
		if (2*j < heap->taml)
			/* si tiene hijo de la derecha */
			if (fcomp(&heap->v[i-1], &heap->v[2*j]) > 0)
				i = 2*j+1;
		if (j!=i) __heap_aristas_intercambia(heap, i-1, j-1);		
	} while (j!=i);
}

/* -------------------------------------------------------------------------- */

void __heap_aristas_flota(heap_aristas heap, int elemento, int (*fcomp)(heap_aristas_tbase*,heap_aristas_tbase*)){
	int i, j;

	i = elemento;
	do {
		j=i;
		if (j>1) {
			if (fcomp(&heap->v[j/2-1], &heap->v[i-1])>0) {
				i = j/2;
				__heap_aristas_intercambia(heap, i-1, j-1);
			}
		}
	} while (j!=i);		
}

/* -------------------------------------------------------------------------- */

void __heap_aristas_inorden(heap_aristas_tbase *v, int nodo_actual, int tam, int tabulacion) {
	
	if (nodo_actual*2<=tam) __heap_aristas_inorden(v,nodo_actual*2,tam,tabulacion+6);
	printf("%*d\n",tabulacion,v[nodo_actual-1].peso);
	if (nodo_actual*2+1<=tam) __heap_aristas_inorden(v,nodo_actual*2+1,tam,tabulacion+6);
}

/* --------------------------- Primitivas públicas -------------------------- */

/**
 * @brief Constructor primitivo del heap
 * @param length tamaño físico del heap. número máximo de elementos que puede contener
 * @pre debe haber memoria para el nuevo heap
 * @pre length debe ser mayor que 0
 * @post devuelve un nuevo heap vacío de tamaño físico = length
 */
heap_aristas heap_aristas_creavacio(int tamf) {
	heap_aristas heap;

	heap = (heap_aristas) malloc (sizeof(struct heap_aristas_rep));

#ifdef __HEAP_aristas_DEBUG_
	if (tamf<=0)
		depuracion("heap_aristas_crea: length debe ser mayor que 0\n", ERR_DATO_INVALIDO);
	if (!heap)
		depuracion("heap_aristas_crea: No hay memoria\n", ERR_NO_MEM);
#endif

	heap->v = (heap_aristas_tbase *) malloc(sizeof(heap_aristas_tbase)*tamf);

#ifdef __HEAP_aristas_DEBUG_
	if (!heap->v)
		depuracion("heap_aristas_crea: No hay memoria", ERR_NO_MEM);	
#endif

	heap->tamf = tamf;
	heap->taml = 0;
	return heap;
}

/* -------------------------------------------------------------------------- */

heap_aristas heap_aristas_crea(heap_aristas_tbase *vinit, int nelem, int (*fcomp)(heap_aristas_tbase*,heap_aristas_tbase*)) {
	heap_aristas heap;
	int i;
	
	heap = (heap_aristas) malloc (sizeof(struct heap_aristas_rep));

#ifdef __HEAP_aristas_DEBUG_
	if (nelem<=0)
		depuracion("heap_aristas_crea: length debe ser mayor que 0\n", ERR_DATO_INVALIDO);
	if (!heap)
		depuracion("heap_aristas_crea: No hay memoria\n", ERR_NO_MEM);
#endif

	heap->v = (heap_aristas_tbase *) malloc(sizeof(heap_aristas_tbase)*nelem);

#ifdef __HEAP_aristas_DEBUG_
	if (!heap->v)
		depuracion("heap_aristas_crea: No hay memoria", ERR_NO_MEM);	
#endif

	heap->tamf = nelem;
	heap->taml = nelem;
	memcpy(heap->v, vinit, nelem*sizeof(struct heap_aristas_base ));
	for (i=nelem/2; i>=0;i--)
		__heap_aristas_hunde(heap, i, fcomp);
	return heap;
}	

/* -------------------------------------------------------------------------- */

/**
 * @brief Destructor. Libera la memoria
 * @param heap puntero al heap a destruir
 * @pre el heap debe haber sido creado previamente
 * @post el heap queda destruido y apuntando a NULL
*/
void heap_aristas_destruye(heap_aristas *heap) {

#ifdef __HEAP_aristas_DEBUG_
	if (!*heap)
		depuracion("heap_aristas_destruye: el heap no existe", ERR_NO_EXISTE);
#endif
	free((*heap)->v);
	free(*heap);
	*heap = NULL;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief devuelve si el heap está vacío o no
 * @param heap heap objeto de consulta
 * @pre el heap debe haber sido creado previamente
 * @post devuelve distinto de 0 si el heap está vacío
*/
int heap_aristas_vacio(heap_aristas heap) {

#ifdef __HEAP_aristas_DEBUG_
	if (!heap)
		depuracion("heap_aristas_vacio: el heap no existe", ERR_NO_EXISTE);
#endif
	return heap->taml == 0;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief devuelve si el heap está lleno o no
 * @param heap heap objeto de consulta
 * @pre el heap debe haber sido creado previamente
 * @post devuelve distinto de 0 si el heap está lleno
*/
int heap_aristas_lleno(heap_aristas heap) {

#ifdef __HEAP_aristas_DEBUG_
	if (!heap)
		depuracion("heap_aristas_lleno: el heap no existe", ERR_NO_EXISTE);
#endif
	return heap->taml == heap->tamf;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief Observador para consultar el tamaño lógico del heap
 * @param heap heap objeto de consulta
 * @pre el heap debe haber sido creado previamente
 * @post devuelve el tamaño lógico del heap
*/
int heap_aristas_tama(heap_aristas heap) {

#ifdef __HEAP_aristas_DEBUG_
	if (!heap)
		depuracion("heap_aristas_tama: el heap no existe\n", ERR_NO_EXISTE);
#endif
	return heap->taml;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief Observador para consultar el elemento raíz del heap
 * @param heap heap objeto de consulta
 * @pre el heap debe haber sido creado previamente
 * @pre el heap no puede estar vacío
 * @post devuelve la raíz del heap sin hacer ninguna modificación
*/

heap_aristas_tbase heap_aristas_raiz(heap_aristas heap) {

#ifdef __HEAP_aristas_DEBUG_
	if (!heap)
		depuracion("heap_aristas_raiz: el heap no existe", ERR_NO_EXISTE);
	if (heap->taml == 0)
		depuracion("heap_aristas_raiz: el heap está vacío", ERR_DATO_INVALIDO);
#endif
	return heap->v[0];
}

/* -------------------------------------------------------------------------- */

/**
 * @brief Modificador para eliminar el elemento raíz del heap
 * @param heap heap objeto de consulta
 * @param fcomp función para comparar 2 elementos del tipo base, que devuelve -1, 0, 1 si "a" es menor, igual o mayor que "b", respectivamente
 * @pre el heap debe haber sido creado previamente
 * @pre el heap no puede estar vacío
 * @post devuelve la raíz del heap eliminandola del hep
*/

heap_aristas_tbase heap_aristas_saca(heap_aristas heap, int (*fcomp)(heap_aristas_tbase *, heap_aristas_tbase *)) {
	heap_aristas_tbase raiz;
	
#ifdef __HEAP_aristas_DEBUG_
	if (!heap)
		depuracion("heap_aristas_saca: el heap no existe", ERR_NO_EXISTE);
	if (heap->taml == 0)
		depuracion("heap_aristas_saca: el heap está vacío", ERR_DATO_INVALIDO);
#endif

	/* recuperamos el valor a sacar */
	raiz = heap->v[0];

	/* disminuimos */
	heap->taml--;

	/* intercambiamos primero y último */
	__heap_aristas_intercambia(heap, 0, heap->taml);

	/* hundimos el primero */
	if (heap->taml>0) __heap_aristas_hunde(heap, 0, fcomp);

	return raiz;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief Modificador para insertar un nuevo elemento en el heap
 * @param heap heap objeto de consulta
 * @param dato elemento a insertar
 * @param fcomp función para comparar 2 elementos del tipo base, que devuelve -1, 0, 1 si "a" es menor, igual o mayor que "b", respectivamente
 * @pre el heap debe haber sido creado previamente
 * @pre el heap no puede estar lleno
 * @post inserta "dato" en el heap
*/

void heap_aristas_mete(heap_aristas heap, heap_aristas_tbase dato, int (*fcomp)(heap_aristas_tbase *, heap_aristas_tbase *)) {

#ifdef __HEAP_aristas_DEBUG_
	if (!heap)
		depuracion("heap_aristas_mete: el heap no existe", ERR_NO_EXISTE);
	if (heap->taml == heap->tamf)
		depuracion("heap_aristas_mete: el heap está lleno", ERR_MAX_TAM);
#endif

	/* metemos el dato  */
	heap->v[heap->taml] = dato;

	/* aumentamos el tamaño lógico */
	heap->taml++;

	/* flotamos el recién llegado */
	__heap_aristas_flota(heap, heap->taml, fcomp);
}

/* -------------------------------------------------------------------------- */

/**
 * @brief Observador para imprimir el heap en pantalla
 * @param heap heap objeto de consulta
 * @pre el heap debe haber sido creado previamente
 * @post muestra el heap en stdout como árbol en inorden (el árbol está tumbado)
*/

void heap_aristas_printf(heap_aristas heap) {
	heap_aristas_tbase una_arista;
	
#ifdef __HEAP_aristas_DEBUG_
	if (!heap)
		depuracion("heap_aristas_mete: el heap no existe", ERR_NO_EXISTE);
#endif

	__heap_aristas_inorden(heap->v, 1, heap->taml, 0);
}
