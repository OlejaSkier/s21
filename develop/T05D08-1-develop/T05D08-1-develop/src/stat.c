#include <math.h>
#include <stdio.h>
#define NMAX 10

void input(int *a, int *n, int *flag);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    int flag = 0;
    input(data, &n, &flag);
    if (flag != 1) {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
    } else
        printf("n/a");

    return 0;
}

void input(int *a, int *n, int *flag) {
    char c;
    int d;
    scanf("%d%c", n, &c);
    if (c != '\n')
        *flag = 1;
    else {
        for (int *p = a; p - a < *n; p++) {
            d = scanf("%d", p);
            if (d != 1) {
                *flag = 1;
            }
        }
    }
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }
    printf("\n");
}

int max(int *a, int n) {
    int max = *a;
    for (int *p = a; p - a < n; p++) {
        if (*p > max) max = *p;
    }

    return max;
}

int min(int *a, int n) {
    int min = *a;
    for (int *p = a; p - a < n; p++) {
        if (*p < min) min = *p;
    }

    return min;
}

double mean(int *a, int n) {
    double count = 0.0;
    for (int *p = a; p - a < n; p++) {
        count = count + (double)*p * (1.0 / (double)n);
    }

    return count;
}

double variance(int *a, int n) {
    double count = 0.0;
    for (int *p = a; p - a < n; p++) {
        count = count + (double)(*p * *p) * (1.0 / (double)n);
    }
    count = count - pow(mean(a, n), 2);

    return count;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6f %.6f", max_v, min_v, mean_v, variance_v);
}