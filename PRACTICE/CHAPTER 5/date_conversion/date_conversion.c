/********************************************************
 * date_conversion --	Programa que realiza conversion de fecha:
 * - de un dia del mes -> un dia del año
 * - de un dia del año -> un dia del mes
********************************************************/
#include <stdio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int main (void) {
	int month;
	int day;
	int day_of_year (int year, int month, int day);
	void month_day (int year, int yearday, int *pmonth, int *pday);

	printf("%d\n", day_of_year(2022, 9, 27));

	month_day(0, 36, &month, &day);
	printf("mes: %d, dia: %d\n", month, day);

}

/* day_of_year: establecer el dia del año a partir de mes y dia */
int day_of_year (int year, int month, int day) {
	int i;	/* contador de bucle */
	int leap;	/* 0: año no bisiesto, 1: año bisiesto */

	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	for (i = 1; i < month; ++i)
		day += daytab[leap][i];
	return day;
}

/* month_day: establecer mes y dia desde dia del año */
void month_day (int year, int yearday, int *pmonth, int *pday) {
	int i;	/* contador de bucle */
	int leap;	/* 0: año no bisiesto, 1: año bisiesto */

	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	for (i = 1; yearday > daytab[leap][i]; ++i)
		yearday -= daytab[leap][i];

	if (i > 12)
		*pmonth = *pday = -1;
	else {
		*pmonth = i;
		*pday = yearday;
	}
}
