#include <stdio.h>

void input(int *a, int *flag);
void sort(int *a);
void fast_sort(int *a);
void output(int *a);

int main() {
    int data[10];
    int flag = 0;
    input(data, &flag);
    if (flag != 1) {
        sort(data);
        output(data);
    }
    else printf("n/a");
    return 0;
}

void input(int *a, int *flag) {
    int d;
    for (int *p = a; p - a < 10; p++) {
        d = scanf("%d", p);
        if (d != 1) *flag = 1;
    }
}

void sort(int *a) {
    int n = 9;
    int count;
    while (n > 0) {
        for (int *p = a; p - a < n; p++) {
            if (*p > *(p + 1)) {
                count = *p;
                *p = *(p + 1);
                *(p + 1) = count;
            }
        }
        n--;
    }
}

void fast_sort(int *a){
    
}

void output(int *a) {
    for (int *p = a; p - a < 10; p++) {
        printf("%d ", *p);
    }
}