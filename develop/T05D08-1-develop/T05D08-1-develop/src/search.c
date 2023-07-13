/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

#include <math.h>
#include <stdio.h>
#define NMAX 30

void input(int *a, int *n, int *flag);
double math_wait(int *a, int n);
double sigma(int *a, int n, int m_wait);
int result(int *a, int n, int *flag);

int main() {
    int flag = 0;
    int n, data[NMAX];
    input(data, &n, &flag);
    if (flag != 1) {
        printf("%d", result(data, n, &flag));
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
            if (d != 1) *flag = 1;
        }
    }
}

double math_wait(int *a, int n) {
    double count = 0.0;
    for (int *p = a; p - a < n; p++) {
        count = count + (double)*p * (1.0 / (double)n);
    }

    return count;
}

double sigma(int *a, int n, int m_wait) {
    double count = 0.0;
    for (int *p = a; p - a < n; p++) {
        count = count + pow((double)*p, 2) * (1.0 / (double)n);
    }
    double sigma = sqrt(count - pow(m_wait, 2));

    return sigma;
}

int result(int *a, int n, int *flag) {
    double results;
    for (int *p = a; p - a < n; p++) {
        if (*p % 2 == 0) {
            if (*p >= math_wait(a, n)) {
                if (*p != 0) {
                    if (fabs(math_wait(a, n) - *p) / sigma(a, n, math_wait(a, n)) <= 3) {
                        results = *p;
                        break;
                    } else
                        *flag = 1;
                } else
                    *flag = 1;
            } else
                *flag = 1;
        } else
            *flag = 1;
    }

    return (int)results;
}