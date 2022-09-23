/********************************************************
 * temperature --	Imprime la tabla de conversion de Fahrenheit a Celsius
 * y de Celsius a Fahrenheit para temperaturas 0, 20, ..., 300
********************************************************/
#include <stdio.h>

#define LOWER 0		/* Temperatura minima de la tabla */
#define UPPER 300	/* Temperatura maxima de la tabla */
#define STEP 20		/* Tamaño de crecimiento */

float fahr_to_celsius (int fahr);
float celsius_to_fahr (int celsius);

int main() {
	int fahr;		/* Temperatura en maginitud Fahrenheit */
	int celsius;	/* Temperatura en maginitud Celsius */

	char title_fahr[] = "Fahrenheit";
	char title_celc[] = "Celsius";
	char delimiter[] = "----------";

	/* Tabla de Fahrenheit a Celsius */
	printf("%10s  |  %10s\n", title_fahr, title_celc);
	printf("%10s  |  %10s\n", delimiter, delimiter);
	for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
		printf("%10d  |  %10.1f\n", fahr, fahr_to_celsius(fahr));
	}

	printf("\n\n");

	/* Tabla de Celsius a Fahrenheit */
	printf("%10s  |  %10s\n", title_celc, title_fahr);
	printf("%10s  |  %10s\n", delimiter, delimiter);
	for (celsius = LOWER; celsius <= UPPER; celsius += STEP) {
		printf("%10d  |  %10.1f\n", celsius, celsius_to_fahr(celsius));
	}

	return 0;
}

/*
 * fahr_to_celsius -- convierte una temperatura en magnitud Fahrenheit a
 * magnitud grados centígrados o Celsius
 *
 * Parameters:
 *		fahr -	temperatura en magnitud Fahrenheit
 *
 *	Return
 *		la temperatura en magnitud grados centígrados o Celsius
 */
float fahr_to_celsius (int fahr) {
	return (5.0 / 9.0) * (fahr - 32);
}

/*
 * celsius_to_fahr -- convierte una temperatura en magnitud Celsius a
 * magnitud Fahrenheit
 *
 * Parameters:
 *		celsius -	temperatura en magnitud grados centígrado o Celsius
 *
 *	Return
 *		la temperatura en magnitud Fahrenheit
 */
float celsius_to_fahr (int celsius) {
	return (9.0 / 5.0) * celsius + 32;
}
