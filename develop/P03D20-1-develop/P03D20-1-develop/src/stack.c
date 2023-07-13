#include "stack.h"

#include "draw.h"

struct Stack *createStack(unsigned capacity) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (double *)malloc(stack->capacity * sizeof(double));
    return stack;
}

double pop(struct Stack *stack) { return stack->array[stack->top--]; }

void push(struct Stack *stack, double item) { stack->array[++stack->top] = item; }

void destroy(struct Stack *stack) {
    free(stack->array);
    free(stack);
}

void del(struct Stack *stack) { stack->top--; }

void space(int *count_out, char *out) {
    if ((*count_out) != 0 && out[(*count_out) - 1] != ' ') {
        out[*count_out] = ' ';
        (*count_out)++;
    }
}

void x_y(double *arr_x, double *arr_y, char *out, int count_out) {
    struct Stack *new_stack = createStack(100);
    arr_x[0] = 0;
    for (int j = 0; j < WIDTH + 1; j++) arr_x[j + 1] = arr_x[j] + M_PI / 20.0;
    for (int j = 0; j < WIDTH; j++) arr_y[j] = array(new_stack, out, count_out, arr_x[j]);
    destroy(new_stack);
}

double array(struct Stack *stack, const char *arr, int count, double x_x) {
    int i = 0;
    while (i < count) {
        if (arr[i] == 'x') {
            push(stack, (double)x_x);
        }
        if (arr[i] == '0' || arr[i] == '1' || arr[i] == '2' || arr[i] == '3' || arr[i] == '4' ||
            arr[i] == '5' || arr[i] == '6' || arr[i] == '7' || arr[i] == '8' || arr[i] == '9') {
            int flg = 0;
            int p = 0;
            double k = 0.0;
            while (arr[i] != ' ') {
                if (arr[i] == '.') {
                    flg = 1;
                } else {
                    double l = (double)(arr[i] - '0');
                    k = k * 10.0 + l;
                }
                i++;
                if (flg == 1) p++;
            }
            k = k / (double)pow(10, p);
            push(stack, k);
        } else if (arr[i] == '*') {
            double n = pop(stack);
            double m = pop(stack);
            double k = m * n;
            push(stack, k);
        } else if (arr[i] == '+') {
            double n = pop(stack);
            double m = pop(stack);
            double k = m + n;
            push(stack, k);
        } else if (arr[i] == '-') {
            double n = pop(stack);
            double m = pop(stack);
            double k = m - n;
            push(stack, k);
        } else if (arr[i] == '/') {
            double n = pop(stack);
            double m = pop(stack);
            double k = m / n;
            push(stack, k);
        } else if (arr[i] == 's') {
            double n = pop(stack);
            double k = sin(n);
            push(stack, k);
        } else if (arr[i] == 'c') {
            double n = pop(stack);
            double k = cos(n);
            push(stack, k);
        } else if (arr[i] == 't') {
            double n = pop(stack);
            double k = tan(n);
            push(stack, k);
        } else if (arr[i] == 'g') {
            double n = pop(stack);
            double k = 1.0 / tan(n);
            push(stack, k);
        } else if (arr[i] == 'q') {
            double n = pop(stack);
            double k = sqrt(n);
            push(stack, k);
        } else if (arr[i] == 'l') {
            double n = pop(stack);
            double k = log(n);
            push(stack, k);
        }
        i++;
    }
    return pop(stack);
}
