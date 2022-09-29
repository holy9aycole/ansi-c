#include <string.h>
#include "./qsort.h"

/*
 * qsort: ordena v[left] ... v[right] en orden creciente
*/
void qsort (void *v[], int left, int right, int (*comp)(void *, void *), int rv) {
	int i;	/* contador de bucle */
	int last;	/*  */
	void swap (void *v[], int i, int j);

	if (left >= right)	/* si el array contiene menos de dos elementos: */
		return;	/* no hacer nada */
	swap(v, left, (left + right) / 2);	/* mover el elemento de la mitad a v[0] */
	last = left;
	for (i = left + 1; i <= right; ++i)
		if ((rv == 0)
				? ((*comp)(v[i], v[left]) < 0) /* de menor a mayor */
				: ((*comp)(v[i], v[left]) > 0))	/* de mayor a menor */
			swap(v, ++last, i);

	swap(v, left, last);
	qsort(v, left, last - 1, comp, rv);
	qsort(v, last + 1, right, comp, rv);
}

/*
 * swap: intercambiar v[i] y v[j]
 */
void swap (void *v[], int i, int j) {
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
