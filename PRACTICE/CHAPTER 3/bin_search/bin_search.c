/********************************************************
 * bin_search --	Programa que implementa el algoritmo binsearch para
 * realizar una busqueda binaria de un numero dentro de un array ordenado
 * de numeros
********************************************************/
#include <stdio.h>
#include <time.h>

int main () {
	int binsearch (int, int [], int);

	double time_spent;	/* tiempo consumido en la ejecucion del programa */
	clock_t start;	/* tiempo al iniciar el programa */
	clock_t end;	/* tiempo al finalizar el programa */
	int x;	/* numero a buscar */
	int v[5] = {3, 4, 7, 12, 21};	/* array de numeros */

	time_spent = 0.0;
	start = clock();
	x = 4;

	printf("%d\n", binsearch(x, v, 5));

	end = clock();
	time_spent = (double) (end - start) / CLOCKS_PER_SEC;

	printf("Tiempo consumido: %f\n", time_spent);

	return 0;
}

/*
 * binsearch: realiza una busqueda binaria de un numero dentro de un array de
 * numeros ordenado.
 *
 * Parameters:
 *		x	numero a buscar
 *		v	array de numeros ordenados
 *		n	tamaño del array
 *
 * Return:
 *		posicion del numero dentro del array, si el numero es encontrado,
 *		o -1 en caso contrario
 */
int binsearch (int x, int v[], int n) {
	int low;	/* limite inferior */
	int high;	/* limite superior */
	int mid;	/* promedio ((lower + upper) / 2) */

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else /* encontrado */
			return mid;
	}

	return -1;	/* no encontrado */
}
