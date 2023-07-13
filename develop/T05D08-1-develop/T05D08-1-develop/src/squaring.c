#include <stdio.h>
#define NMAX 10

void input(int *a, int *n, int *flag);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int flag = 0;
    int n, data[NMAX];
    input(data, &n, &flag);
    if (flag == 0) {
        squaring(data, n);
        output(data, n);
    } else
        printf("n/a");

    return 0;
}

void input(int *a, int *n, int *flag) {
    char c;
    int d;
    scanf("%d%c", n, &c);
    if (c != '\n') {
        *flag = 1;
    } else {
        for (int *p = a; p - a < *n; p++) {
            d = scanf("%d", p);
            if (d != 1) *flag = 1;
        }
    }
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }
}

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        *p = *p * *p;
    }
}
