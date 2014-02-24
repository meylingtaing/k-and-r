#include <stdio.h>

/* Print fahrenheit to celcius table */

int main() {
	float fahr, cels;
	int lower, upper, step;

	// Print heading
	printf("Celsius\tFahrenheit\n");
	printf("=======\t==========\n");

	lower = 0;
	upper = 300;
	step = 20;

	cels = lower;
	while (cels <= upper) {
		fahr = 9.0/5.0 * cels + 32.0;
		printf("%7.0f\t%10.1f\n", cels, fahr);
		cels = cels + step;
	}

	return 0;
}