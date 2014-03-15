/* Swap macro */

#include <stdio.h>
#define swap(t, x, y) {t temp = (x); (x) = (y); (y) = temp;}

int main() {
	int x = 3, y = 4;
	double dx = 1.0, dy = 2.0;
	char cx = '4', cy = '5';

	swap(int, x, y);
	swap(double, dx, dy);
	swap(char, cx, cy);

	printf("x = %d, y = %d\n", x, y);
	printf("dx = %lf, dy = %lf\n", dx, dy);
	printf("cx = %c, cy = %c\n", cx, cy);

	return 0;
}