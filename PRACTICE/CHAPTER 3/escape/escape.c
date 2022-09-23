/********************************************************
 * escape --	Programa que convierte caracteres como salto de linea y
 * tabalución en una secuencia escapes visibles como \n y \t. Realizando lo
 * mismo también en el sentido contrario
********************************************************/
#include <stdio.h>

#define LENGTH 100	/* tamaño de cada string */

int main () {
	void escape_to (char [], char [], int);
	void escape_from (char [], char [], int);

	char source[LENGTH];
	char escaped[LENGTH];

	fgets(source, sizeof(source), stdin);

	escape_to(escaped, source, LENGTH);

	printf("%s\n", escaped);

	return 0;
}

/* escape_to: convierte caracteres como saltos de linea y tabaluciones en una
 * secuencia de caracteres visibles como \n y \t
 *
 * Parameters:
 *		s	string con los caracteres visibles (\n)
 *		t	string con los caracteres reales (salto de linea)
 *		max	tamaño de los string
 */
void escape_to (char s[], char t[], int max) {
	int i;	/* indice del string s */
	int j;	/* indice del string t */

	for (i = j = 0; i < max; ++i, ++j) {
		switch (t[i]) {
			case '\n':
				s[j++] = '\\';
				s[j] = 'n';
				break;
			case '\t':
				s[j++] = '\\';
				s[j] = 't';
				break;
			default:
				s[j] = t[i];
				break;
		}
	}
}

/*
 * escape_from: convierte caracteres visibles como \n y \t en caracteres reales
 * como salto de linea y tabaluciones
 *
 * Parameters:
 *		s	string con los caracteres reales (salto de linea)
 *		t	string con los caracteres visibles (\n)
 */
void escape_from (char s[], char t[], int max) {
	int i;	/* indice del string s */
	int j;	/* indice del string t */
	int flag;	/* indica si se ha encontrado el caracter de escape (\) */

	for (i = j = 0; i < max; ++i, ++j) {
		switch (t[i]) {
			case '\\':
				flag = 1;
				s[j] = t[i];
				break;
			case 'n':
				if (flag == 1) {
					s[--j] = '\n';
				} else {
					s[j] = t[i];
				}
				break;
			case 't':
				if (flag == 1) {
					s[--j] = '\t';
				} else {
					s[j] = t[i];
				}
				break;
			default:
				s[j] = t[i];
				break;

		}
	}
}
