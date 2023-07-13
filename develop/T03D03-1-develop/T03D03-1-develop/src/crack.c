#include <stdio.h>

int main() {
    float x, y;
    char a, b;
    scanf("%f%c%f%c", &x, &a, &y, &b);
    if ((a == ' ' || a == '\n') && b == '\n') {
        if (x*x + y*y <= 25) printf("GOTCHA");
        else printf("MISS");
    }
    else printf("n/a");
}