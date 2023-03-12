/*************************imat2d.c****************************/
/*              Módulo en C para uso de objetos              */
/*                    Matriz 2D DE ENTEROS                   */
/*************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "imatriz2d.h"

#define FILAS 5
#define COLUMNAS 10
int main() {
	
	imatriz2d m;
	int i, j, k;
	
	m=icreamatriz2d(FILAS, COLUMNAS);
	
	for (k=i=0;i<FILAS; i++)
		for (j=0;j<COLUMNAS;j++)
			m[i][j]=++k;
	
	for (i=0;i<FILAS; i++) {
		for (j=0;j<COLUMNAS;j++)
			printf("%*d",4,m[i][j]);
		printf("\n");
	}
	ifreematriz2d(&m);
	return 0;
}
