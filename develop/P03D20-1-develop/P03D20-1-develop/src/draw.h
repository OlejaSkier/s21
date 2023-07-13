#ifndef DRAW_H
#define DRAW_H

#define HEIGHT 25
#define WIDTH 80
/**
 * @brief Заполнить матрицу 0
 */
void fill(int **field);
/**
 * @brief Отрисовать точки и звездочки
 */
void draw(int **field);
/**
 * @brief Координаты звездочек
 */
void func(int **field, const double *arr_y, const double *arr_x);

#endif
