/********************************************************
 * shellsort --	Implementacion del algoritmo de ordenacion Shell para ordenar
 * un array de numeros. Inventado por D. L. Shell en 1959.
********************************************************/
#include <stdio.h>
#include <time.h>

#define MAXNUMBER	50	/* cantidad de numeros a ordenar */

int main () {
	void shellsort (int [], int);
	void printarray (int [], int);
	clock_t begin, end;	/* tiempo al inciar y teminar el programa */
	double time_spent;	/* tiempo ejecucion del programa */
	int v[MAXNUMBER];
	int i;	/* contador de bucle for */

	for (i = 0; i < MAXNUMBER; ++i)	/* llenar el array */
		v[i] = MAXNUMBER - i;

	/* array original */
	printarray(v, MAXNUMBER);

	begin = clock();
	shellsort(v, MAXNUMBER);
	end = clock();
	time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

	/* array ordenado */
	printarray(v, MAXNUMBER);
	printf("%lf\n", time_spent);

	return 0;
}

/*
 * shellsort: ordenar v[0]...v[n-1] en orden creciente
 *
 * Parameters:
 *		v	array de numeros enteros
 *		n	tamaño del array v
 */
void shellsort (int v[], int n) {
	int gap;	/* intervalo */
	int i;
	int j;
	int tmp;

	for (gap = n/2; gap > 0; gap /= 2) {
		for (i = gap; i < n; ++i) {
			for (j = i-gap; j >= 0 && v[j] > v[j+gap]; j -= gap) {
				tmp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = tmp;
			}
		}
	}
}

/*
 * printarray: imprimir los elementos de un array
 *
 * Parameters:
 *		v	array a imprimir
 *		n	tamaño del array
 */
void printarray (int v[], int n) {
	int i;	/* contador de bucle */

	printf("{ %d", v[0]);
	for (i = 1; i < n; ++i) {
		printf(", %d", v[i]);
	}
	printf(" }\n");
}
