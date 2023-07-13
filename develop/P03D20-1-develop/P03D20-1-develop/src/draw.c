#include "draw.h"

#include "stack.h"

void draw(int **field) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (field[i][j] == 0) {
                printf(".");
            }
            if (field[i][j] == 1) {
                printf("*");
            }
            if (j == WIDTH - 1) {
                printf("\n");
            }
        }
    }
}

void fill(int **field) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            field[i][j] = 0;
        }
    }
}

void func(int **field, const double *arr_y, const double *arr_x) {
    for (int i = 0; i < WIDTH; i++) {
        int y;
        y = (int)round(arr_y[i] * 12 + HEIGHT / 2);
        if (y <= HEIGHT - 1 && arr_x[i] <= WIDTH - 1 && y >= 0 && arr_x[i] >= 0) {
            field[y][i] = 1;
        }
    }
}
