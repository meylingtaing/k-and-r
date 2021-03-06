/* Rewrite day_of_year and month_day with pointers */

#include <stdlib.h>
#include <stdio.h>

#define YEAR 2000

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main(int argc, char **argv)
{
	int input_day;
	int month, day;

	if (argc < 2) {
		printf("Usage: %s day_of_year\n");
		return -1;
	}

	input_day = atoi(argv[1]);

	month_day(YEAR, input_day, &month, &day);
	printf("Day %d in %d is %d/%d\n", input_day, YEAR, month, day);
	printf("Converting it to day of year: %d\n", day_of_year(YEAR, month, day));
}

/* day_of_year: set day of year from month and day */
int day_of_year(int year, int month, int day)
{
	int i, leap;
	char *p;

	if (year < 0 || month < 1 || month > 12 || 
		day < 1 || day > daytab[1][month] )
		return -1;

	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	p = *(daytab + leap);
	for (i = 1; i < month; i++)
		day += *(p + i);

	return day;
}

/* month_day: set month and day from day of year */
int month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	char *p;

	// Error checking
	if (year < 0 || yearday < 1 || yearday > 366)
		return -1;

	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	if (!leap && yearday == 366)
		return -1;

	p = *(daytab + leap);
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= *(p + i);

	*pmonth = i;
	*pday = yearday;

	return 0;
}

/* month_name: return name of nth month */
char *month_name(int n)
{
	static char *name[] = {
		"Illegal month", "January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December"
	};

	return (n < 1 || n > 12) ? name[0] : name[n];
}