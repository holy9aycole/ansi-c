/*
 * fold: pliega lineas de entrada largas dentro de dos o más linea cortas
 * después del último caracter no espacio que ocurre antes de la columna
 * enésima (n-th) de la entrada
 */
void fold ();

/*
 * word_procesing: procesa palabra por palabra la entrada del usuario
 *
 * Parameters:
 *		word	string donde guardar la palabra
 *		max		tamaño máximo del string
 *
 * Return:
 *		cantidad de caracteres que contiene la palabra
 */
int word_procesing (char word[], int max);
