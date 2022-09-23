#include <stdio.h>
#define UNDEFINED -1	/* aun no se ha identidica el caracter introducido */
#define SPACE 0	/* caracter introducido es un espacio */
#define NEWLINE 1	/* caracter introducido es un salto de linea */
#define NON_SPACE 2	/* caracter introducido no es un espacio ni un salto de
					   linea */

/*
 * word_procesing: procesa palabra por palabra la entrada del usuario
 */
int word_procesing (char word[], int max) {
	int c;	/* cada caracter introducido */
	int i;	/* contador de bucle */
	char type_flag;	/* indica el tipo de caracter introducido */

	type_flag = UNDEFINED;	/* tipo indefinido */

	for (i = 0; i < max - 1 && (c = getchar()) != EOF; ++i) {
		switch (c) {
			case ' ':
			case '\t':
				if (type_flag != SPACE && type_flag != UNDEFINED) {
					/* la palabra formada hasta ahora no era de espacios: */

					/* devolver el ultimo caracter leido al bufer */
					ungetc(c, stdin);

					word[i++] = '\0';	/* terminar la palabra */
					return i;	/* devolver su longitud */
				}
				/* else: */
				type_flag = SPACE;	/* definir el tipo de palabra */
				word[i] = c;
				break;

			case '\n':
				if (type_flag != NEWLINE && type_flag != UNDEFINED) {
					/* la palabra formada hasta ahora no era de saltos de linea: */

					/* devolver el ultimo caracter leido al bufer */
					ungetc(c, stdin);

					word[i++] = '\0';	/* terminar la palabra */
					return i;	/* devolver su longitud */
				}
				/* else: */
				type_flag = NEWLINE;	/* definir el tipo de palabra */
				word[i++] = c;
				word[i++] = '\0';
				return i;

			default:
				if (type_flag != NON_SPACE && type_flag != UNDEFINED) {
					/* la palabra formada hasta ahora era de espacios o de
					 * saltos de linea: */

					/* devolver el ultimo caracter leido al bufer */
					ungetc(c, stdin);

					word[i++] = '\0';	/* terminar la palabra */
					return i;	/* devolver su longitud */
				}
				/* else: */
				type_flag = NON_SPACE;	/* definir el tipo de palabra */
				word[i] = c;
				break;
		}
	}

	/*
	 * Si se ha salido del bucle es por dos razones:
	 *  1. se ha llegado a un caracter EOF (End Of File)
	 *  2. se ha sobrepasado el limite de longitud de una palabra (Overflow)
	 */

	if (i == 0) {	/* EOF */
		word[0] = '\0';	/* no se ha procesado ninguna palabra */
		return -1;	/* status de EOF */
	}
	else {	/* Overflow */
		word[i++] = '\0';	/* terminar la palabra */
		return i;	/* devolver su longitud */
	}
}
