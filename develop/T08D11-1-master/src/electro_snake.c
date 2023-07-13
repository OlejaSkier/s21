#include <stdio.h>
#include <stdlib.h>

/*
    1 6 7
    2 5 8
    3 4 9
*/
// void sort_vertical(int **matrix, int n, int m, int **result_matrix);

/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);


void input(int **matrix, int n, int m);
void output(int **matrix, int n, int m);

void main()
{
    int **matrix, **result;
    int n,m;
    scanf("%d %d", &n, &m);
    matrix = malloc(m * n * sizeof(int) * m * sizeof(int*));


    input(matrix, n, m);

    sort_horizontal(matrix, n, m, result);
    output(matrix, n, m);
    
    // sort_vertical(matrix, n, m, result);
    // output(result, n, m);

    free(matrix);
    free(result);
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
void output(int **matrix, int n, int m) {
    for (int i = 0; i < m; i++, printf("\n"))
    for (int j = 0; j < n; j++)
        printf("%d ", matrix[i][j]);
}

void sort_horizontal(int **matrix, int n, int m, int **result_matrix) {
    for (int i = 0; i < n; i++) {
        int count;
        int t = m;
        // if (i % 2 == 0) {
            while (t > 0) {
                for (int j = 0; j < t; j++) {
                    if (matrix[i][j] > matrix[i][j + 1]) {
                        count = matrix[i][j];
                        matrix[i][j] = matrix[i][j + 1];
                        matrix[i][j + 1] = count;
                    }
                }
                t--;
            }
        // }
        // else {
        //     while (t > 0) {
        //         for (int j = 0; j < t; j++) {
        //             if (matrix[i][j] < matrix[i][j + 1]) {
        //                 count = matrix[i][j];
        //                 matrix[i][j] = matrix[i][j + 1];
        //                 matrix[i][j + 1] = count;
        //             }
        //         }
        //         t--;
        //     }
        // }
    }

}

// void sort_vertical(int **matrix, int n, int m, int **result_matrix);
