#include <stdio.h>

int maximum(int first, int second) {
	if (first >= second) return first;
	else return second;
}

int main() {
	char a, b;
	double x, y;
	scanf("%lf%c%lf%c", &x, &a, &y, &b);

	if ( (int) x == x && (int) y == y && (a == ' ' || a == '\n') && b == '\n'){
		x = (int) x;
		y = (int) y;
		printf("%d", maximum(x, y));
	}
	else printf("n/a");

	return 0;
}
