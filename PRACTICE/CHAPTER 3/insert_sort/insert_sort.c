/********************************************************
 * insert_sort --	Implementacion del algoritmo de ordenacion insert sort
********************************************************/
#include <stdio.h>
#include <time.h>

#define MAXNUMBER	50	/* cantidad de numeros a ordenar */

int main () {
	void printarray (int [], int);
	void insert_sort (int [], int);
	clock_t begin, end;	/* tiempo al inciar y teminar el programa */
	double time_spent;	/* tiempo ejecucion del programa */
	int v[MAXNUMBER];
	int i;	/* contador de bucle for */

	for (i = 0; i < MAXNUMBER; ++i)	/* llenar el array */
		v[i] = MAXNUMBER - i;


	/* array original */
	printarray(v, MAXNUMBER);

	begin = clock();
	insert_sort(v, MAXNUMBER);
	end = clock();
	time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

	/* array ordenado */
	printarray(v, MAXNUMBER);
	printf("%lf\n", time_spent);

	return 0;
}

/*
 * insert_sort: ordena un array de enteros v[0]...v[n-1] en orden creciente
 *
 * Parameters:
 *		v	array de numeros enteros
 *		n	tamoño del array
 */
void insert_sort (int v[], int n) {
	int j;	/* indice del elemento actual */
	int i;	/* indice del elemento anterior */
	int key;	/* elemento actual */

	for (j = 1; j < n; ++j) {	/* iniciar desde el segundo elemento (j = 1) */
		key = v[j];
		/* insertar v[j] dentro del array ordenado v[0...n-1]: */
		i = j - 1;
		while (i >= 0 && v[i] > key) {
			/* El elemento anterior es mayor al actual: */

			v[i + 1] = v[i]; /* desplazar el elemento anterior hacia la derecha */
			--i;	/* indice del siguiente elemento anterior */
		}
		v[i + 1] = key;	/* insertar el elemento actual */
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
