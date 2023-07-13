#include <stdio.h>
#include <stdlib.h>

void input(int **matrix, int n, int m);

int main() {
    // int n, m;
    // int **matrix;
    // scanf("%d %d", &n, &m);
    // matrix = malloc(m * n * sizeof(int) * m * sizeof(int*));

    // input(matrix, n, m);
    // for (int i = 0; i < m; i++, printf("\n"))
    //     for (int j = 0; j < n; j++)
    //         printf("%d ", matrix[i][j]);
    // free(matrix);

    int array[10] = {5, 4, 3, 6, 2, 7, 8, 1, 9, 0};
    int count;
    int n = 10, m;

    while (n > 0) {
        for (int *p = array; p - array < n; p++) {
            if (*p > *(p + 1)) {
                count = *p;
                *p = *(p + 1);
                *(p + 1) = count;
            }
        }
        n--;
    }

    for (int i = 0; i < 10; printf("%d ", array[i]), i++);

    return 0;
}

void input(int **matrix, int n, int m) {
    int *ptr = (int*) (matrix + m);
    int count = 0;

    for (int i = 0; i < m; i++)
        matrix[i] = ptr + n * i;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);
}