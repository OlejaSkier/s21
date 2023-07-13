#include <stdio.h>
#include <stdlib.h>

void input(int *a, int *flag, int *n);
void sort(int *a, int n);
void output(int *a, int n);

int main() {
    int n;
    int *data = calloc(n, sizeof(int));
    int flag = 0;
    input(data, &flag, &n);
    if (flag != 1) {
        sort(data, n);
        output(data, n);
    } else
        printf("n/a");
    free(data);

    return 0;
}

void input(int *a, int *flag, int *n) {
    char c;
    scanf("%d%c", n, &c);
    if (c != '\n') *flag = 1;
    for (int *p = a; p - a < *n; p++) {
        int d = scanf("%d", p);
        if (d != 1) *flag = 1;
    }
}

void sort(int *a, int n) {
    int count, m = n - 1;
    while (m > 0) {
        for (int *p = a; p - a < m; p++) {
            if (*p > *(p + 1)) {
                count = *p;
                *p = *(p + 1);
                *(p + 1) = count;
            }
        }
        m--;
    }
}

void output(int *a, int n) {
    printf("%d", *a);
    for (int *p = a + 1; p - a < n; p++) {
        printf(" %d", *p);
    }
}