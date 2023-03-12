/**	Módulo para el tratamiento homogéneo de errores en comprobación de precondiciones para las operaciones de TDA.
	Dispone de un procedimiento "depuracion" que debe ser llamado por el implementador de las operaciones del TDA cuando se detecte una precondición no satisfecha en la llamada. El usuario de la función debe pasar una cadena que describa el error ocurrido y un código de error que lo identifique para tratarlo adecuadamente. Se deben añadir más códigos de error según las necesidades de la aplicación.
	@file		depuracion.h
	@brief		Funciones para la unificación del tratamiento de errores
	@author		Jose Ramon Balsas
	@date		11/10/2004
	@see		depuracion.c
	@par Utilización
		Colocar 	#include "depuracion.h" en los modulos que vayan a usar el procedimiento "depuracion".
	@par Ejemplo
		depuracion("nr_crea: denominador igual a 0",ERR_DIV_CERO);
*/
#ifndef  __DEPURACION_H
#define  __DEPURACION_H

/**@brief División por cero en una expresión aritmética.*/
#define ERR_DIV_CERO	1
/**@brief Error en llamada a funciones de gestión de memoria.*/
#define ERR_NO_MEM	2
/**@brief Se ha intentado acceder a un elemento no existente en el tipo.*/
#define ERR_NO_EXISTE	3
/**@brief Una estructura estática ha alcanzado su máxima capacidad*/
#define	ERR_MAX_TAM		4
/**@brief El dato no es aceptado*/
#define	ERR_DATO_INVALIDO		5


	void depuracion(char *mensaje, int error);

#endif
