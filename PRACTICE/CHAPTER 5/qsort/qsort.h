/*
 * readlines: leer lineas de entrada
 *
 * Parameters:
 *		linesptr	lineas de texto a leidas
 *		maxlines	cantidad maxima de lineas a leer
 *
 * Return:
 *		cantidad de linea leidas
 */
int readlines (char *linesptr[], int nlines);

/*
 * writelines: escribir lineas de texto en la salida estandar
 *
 * Parameters:
 *		linesptr	lineas de texto
 *		nlines		cantidad de lineas de texto
 */
void writelines (char *linesptr[], int nlines);

/*
 * atof: convierte una cadena de caracteres en un numero double
 *
 * Parameters:
 *		s	cadena de caracteres
 *
 * Return:
 *		numero decimal (double)
 */
double atof (const char s[]);

/*
 * numcmp: compara s1 y s2 numericamente
 *
 * Parameters:
 *		s1	string de caracteres
 *		s2	string de caracteres
 *
 * Return
 *		-1 se s1 < s2
 *		1 si s1 > s2
 *		0 si s1 == s2
 */
int numcmp (const char *s1, const char *s2);

/*
 * qsort: ordena v[left] ... v[right] en orden creciente
 *
 * Parameters:
 *		linesptr	lineas de texto
 *		left		posicion de partida
 *		right		posicion final
 *		comp		funcion que compara los elementos
 *		rv			orden creciente o decreciente
 */
void qsort (void *lineptr[], int left, int right, int (*comp)(void *, void *), int rv);
