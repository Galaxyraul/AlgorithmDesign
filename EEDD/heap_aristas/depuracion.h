/**	M�dulo para el tratamiento homog�neo de errores en comprobaci�n de precondiciones para las operaciones de TDA.
	Dispone de un procedimiento "depuracion" que debe ser llamado por el implementador de las operaciones del TDA cuando se detecte una precondici�n no satisfecha en la llamada. El usuario de la funci�n debe pasar una cadena que describa el error ocurrido y un c�digo de error que lo identifique para tratarlo adecuadamente. Se deben a�adir m�s c�digos de error seg�n las necesidades de la aplicaci�n.
	@file		depuracion.h
	@brief		Funciones para la unificaci�n del tratamiento de errores
	@author		Jose Ramon Balsas
	@date		11/10/2004
	@see		depuracion.c
	@par Utilizaci�n
		Colocar 	#include "depuracion.h" en los modulos que vayan a usar el procedimiento "depuracion".
	@par Ejemplo
		depuracion("nr_crea: denominador igual a 0",ERR_DIV_CERO);
*/
#ifndef  __DEPURACION_H
#define  __DEPURACION_H

/**@brief Divisi�n por cero en una expresi�n aritm�tica.*/
#define ERR_DIV_CERO	1
/**@brief Error en llamada a funciones de gesti�n de memoria.*/
#define ERR_NO_MEM	2
/**@brief Se ha intentado acceder a un elemento no existente en el tipo.*/
#define ERR_NO_EXISTE	3
/**@brief Una estructura est�tica ha alcanzado su m�xima capacidad*/
#define	ERR_MAX_TAM		4
/**@brief El dato no es aceptado*/
#define	ERR_DATO_INVALIDO		5


	void depuracion(char *mensaje, int error);

#endif
