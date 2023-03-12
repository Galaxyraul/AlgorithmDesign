/**	@file		depuracion.c
	@brief		Implementacin de funciones para la unificacin del tratamiento de errores
	@author		Jose Ramon Balsas
	@date		11/10/2004
	@see		depuracion.h
	@par Utilizacin
		Modificar la instruccin condicional mltiple del procedimiento "depuracion" para tratar adecuadamente cada uno de los diferentes tipos de error definidos
*/


#include <stdio.h>
#include "depuracion.h"

/** 	Este procediento es llamado por las primitivas de los TDAs cuando no se satisface alguna precondicin de las mismas.
	@brief	Gestion de errores en comprobacin de precondiciones de primitivas de TDAs
	@param	mensaje Cadena de caracteres. Mensaje que describe el error que ha ocurrido
	@param	error   Cdigo de error de salida
	@post	Muestra el mensaje de error por la  salida estandard de error.
	@post	Termina la aplicacin, realizando las acciones previas necesarias dependiendo del tipo de error
	@see	En depuracin.h se puede ver la lista de mensajes de error
*/

void depuracion(char *mensaje, int error) {
	fprintf(stderr, "ERROR en %s\n", mensaje);
	/*Tratamiento de errores*/
	switch(error) {
		case ERR_NO_MEM:	
				/*Tratamiento especfico cuando no hay memoria...*/
		default: exit(error);
	};
};
