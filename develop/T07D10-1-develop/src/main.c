#include <stdio.h>
#include <stdlib.h>

#define N 100

void first_dynamic(int **array, int *n, int *m) {
    scanf("%d%d", n, m);
    array = malloc(*m * sizeof(int*));
    for (int i = 0; i < *m; i++)
        array[i] = malloc(*n * sizeof(int));

    for (int i = 0; i < *m; i++)
        for (int j = 0; j < *n; j++)
            scanf("%d", &array[i][j]);

    for (int i = 0; i < *m; i++, printf("\n"))
        for (int j = 0; j < *n; j++)
            printf("%d ", array[i][j]);

    for (int i = 0; i < *m; i++)
        free(array[i]);
    free(array);
}

int main() {
    int m, n;
    int count = 0;
    scanf("%d%d", &n, &m);
    
    int **pointer_array;

    first_dynamic(pointer_array, &n, &m);

    return 0;
}