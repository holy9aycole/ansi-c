/********************************************************
 * Programa que elimina todo los comentarios de un programa en C
 * TODO: escapar u omitir comentario que esta entre comillas (")
********************************************************/
#include <stdio.h>
#include <string.h>
#include "./remove_comment.h"
#include "../util/util.h"

#define MAXLINE 100	/* Tamaño máximo de una linea leida de la entrada */

int main (void) {
	char line[MAXLINE];	/* linea leida de la entrada del usuario */
	int len;	/* longitud de la linea leida */
	Comment comment;	/* posicion inicial y final de un comentario */


	while ((len = get_line(line, MAXLINE) > 0)) {	/* obtener una linea */
		comment = find_comment(line);	/* buscar comentario en la linea */
		if (comment.start != UNDEFINED && comment.end != UNDEFINED) {
			/* inicio y final estan definidos en la linea (comentario de una
			 * sola linea): */
			len = remove_string(line, comment.start, comment.end);
		} else if (comment.start != UNDEFINED) {
			/* solo el inicio del comentario esta definido (comentario multi
			 * lineal): */
			len = remove_string(line, comment.start, strlen(line));
		} else if (comment.end != UNDEFINED) {
			/* solo el final del comentario esta definido (comentario multi
			 * lineal): */
			len = remove_string(line, 0, strlen(line));
		}

		if (len == 1 && line[0] == '\n' && comment.start != UNDEFINED &&
				comment.end != UNDEFINED) /* si toda la linea ha sido eliminada */
			continue;	/* no imprimir linea */

		printf("%s", line);
	}
}
