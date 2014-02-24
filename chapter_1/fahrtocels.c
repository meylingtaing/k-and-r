#include <stdio.h>

#define	LOWER	0
#define UPPER	300
#define STEP	20

/* Print fahrenheit to celcius table */
float convert_to_cels(float fahr);

int main() {
	int fahr;

	// Print heading
	printf("Fahrenheit\tCelsius\n");
	printf("==========\t=======\n");

	for (fahr = UPPER; fahr >= LOWER; fahr = fahr-STEP)
		printf("%10d\t%7.1f\n", fahr, convert_to_cels(fahr));

	return 0;
}

float convert_to_cels(float fahr) {
	float cels = (5.0/9.0)*(fahr-32);
	return cels;
}