#include "data_sort.h"

#include <stdio.h>
#include <stdlib.h>

void sort(double *data, int n) {
    double count;
    int m = n - 1;
    while (m > 0) {
        for (int i = 0; i < m; i++) {
            if (data[i] > data[i + i]) {
                count = data[i];
                data[i] = data[i + 1];
                data[i + 1] = count;
            }
        }
        m--;
    }
}