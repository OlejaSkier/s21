#include <stdio.h>

int main() {
	double x, y;
	char a, b;
	scanf("%lf%c%lf%c", &x, &a, &y, &b);
	int s, r, m;
	double d;
	if ( (int) x == x && (int) y == y && (a == ' ' || a == '\n') && b == '\n') {
		d = x/y;
		x = (int) x;
		y = (int) y;
		s = x + y;
		r = x - y;
		m = x * y;
		if (y != 0) printf("%d %d %d %d", s, r, m, (int) d);
		else printf("%d %d %d n/a", s, r, m);
	}
	else printf("n/a");

	return 0;
}
