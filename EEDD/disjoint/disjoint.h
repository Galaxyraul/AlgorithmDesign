/***************************************************************/
/*                                                             */
/*           M¢dulo de cabeceras C para uso de objetos         */
/*                                                             */
/*                        CONJUNTOS DISJUNTOS                  */
/*                                                             */
/***************************************************************/

#ifndef DISJOINT

#define DISJOINT

typedef int *disjoint;

disjoint disjoint_nuev(int n);
void disjoint_dest(disjoint *c);
void disjoint_merge(disjoint c, int a, int b);
int disjoint_find(disjoint c, int x);
void disjoint_printf(disjoint c,int n);

#endif
