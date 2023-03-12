/***************************************************************/
/*                                                             */
/*    Módulo en C para uso de objetos en una estructura de     */
/*                                                             */
/*                  VECTOR DINAMICO                            */
/*                                                             */
/***************************************************************/

#ifndef VDIN

#define VDIN


typedef struct vdin_rep  *vdin;

vdin vdin_nuev(int tambase);
vdin vdin_copia(vdin a);
int vdin_tamal(vdin a);
int vdin_tamaf(vdin a);
int vdin_tambase(vdin a);
void vdin_obti(vdin a, int i, void *e);
void vdin_asig(vdin a, int i, void *e);
void vdin_aumd(vdin a, void *e);
void vdin_disd(vdin a, void *e);
void vdin_dest(vdin *a);
void vdin_swap(vdin a, int l,int r);
int vdin_bbin(vdin a, void *e,int (*compar) (const void *, const void *));
int vdin_blseq(vdin a, void *e,int (*compar) (const void *, const void *));
int vdin_brseq(vdin a, void *e,int (*compar) (const void *, const void *));
void vdin_qsort(vdin a,int (*compar) (const void *, const void *));

#endif
