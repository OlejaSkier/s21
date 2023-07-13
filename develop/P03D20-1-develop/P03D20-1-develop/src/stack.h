#ifndef STACK_H
#define STACK_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int top;
    unsigned capacity;
    double *array;
};

struct Stack *createStack(unsigned capacity);
/**
 * @brief Добавить в стек
 */
void push(struct Stack *stack, double item);
/**
 * @brief Взять из стека
 */
double pop(struct Stack *stack);
/**
 * @brief Убить стек
 */
void destroy(struct Stack *stack);
/**
 * @brief Удалить верхний элемент стека
 */
void del(struct Stack *stack);
/**
 * @brief Высчитывает значение выражения в польской нотации
 * @param stack временный стек для хранения переменных
 * @param arr выходная строка польской нотации
 * @param count длина arr
 * @param x_x значения х
 */
double array(struct Stack *stack, const char *arr, int count, double x_x);
/**
 * @brief Вычисляет значение y
 * @param arr_x массив значений x
 * @param arr_y массив значений y
 * @param out выходная строка польской нотации
 * @param count_out длина out
 */
void x_y(double *arr_x, double *arr_y, char *out, int count_out);
/**
 * @brief Ввод пробела в выходную строку
 */
void space(int *count_out, char *out);

#endif
