/***************************************************************/
/*                                                             */
/*    M�dulo en C para uso de objetos en una estructura de     */
/*                                                             */
/*                   CONJUNTOS DISJUNTOS                       */
/*                                                             */
/***************************************************************/



#include "disjoint.h"

int main() {

	disjoint a;
	int i;

	a=disjoint_nuev(11);
    disjoint_printf(a,11);
	disjoint_merge(a,disjoint_find(a,5),disjoint_find(a,7));
	disjoint_printf(a,11);
	disjoint_merge(a,disjoint_find(a,1),disjoint_find(a,7));
	disjoint_printf(a,11);
	disjoint_merge(a,disjoint_find(a,3),disjoint_find(a,2));
	disjoint_printf(a,11);
	disjoint_merge(a,disjoint_find(a,3),disjoint_find(a,7));
	disjoint_find(a,1);
	disjoint_find(a,7);
	disjoint_printf(a,11);
	disjoint_dest(&a);
	return 0;
}
