#include <stdio.h>
#include <math.h>

int fibonachi(int n) {
    int count = 1;
    int a = 1, b = 1, c;
    while (count != n) {
        c = a;
        a = a + b;
        b = c;
        count++;
    }

    return b;
}

int main() {
    int a;
    char c;
    scanf("%d%c", &a, &c);
    if (c == '\n' && a > 0) printf("%d", fibonachi(a));
    else printf("n/a");

    return 0;
}
