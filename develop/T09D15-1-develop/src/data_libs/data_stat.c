#include "data_stat.h"

double max(double *data, int n) {
    double count = 0;
    for (int i = 0; i < n; i++)
        if (data[i] > count) count = data[i];

    return count;
}

double min(double *data, int n) {
    double count = data[0];
    for (int i = 0; i < n; i++)
        if (data[i] < count) count = data[i];

    return count;
}

double mean(double *data, int n) {
    double count = 0;
    for (int i = 0; i < n; i++) count = count + data[i] * 1 / n;

    return count;
}

double variance(double *data, int n) {
    double count = 0;
    for (int i = 0; i < n; i++) count = count + data[i] * data[i];
    count = count + mean(data, n) * mean(data, n);

    return count;
}
