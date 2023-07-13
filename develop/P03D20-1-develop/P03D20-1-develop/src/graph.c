#include "draw.h"
#include "stack.h"

int main() {
    /**
     * @brief Куда считываем вводимую строку
     */
    char str[100];
    /**
     * @brief Куда выводим готовую сторку
     */
    char out[100];
    int flag = 1;
    int count_parenthesis = 0;

    struct Stack *stack = createStack(100);

    scanf("%99s", str);

    int count = 0, count_out = 0;

    while (str[count] != '\0') {
        switch (str[count]) {
            case 'x':
                if (count != 0 && str[count - 1] != '+' && str[count - 1] != '-' && str[count - 1] != '*' &&
                    str[count - 1] != '/' && str[count - 1] != '(')
                    flag = 0;
                space(&count_out, out);
                out[count_out] = str[count];
                count_out++;
                break;
            case '+':
                if ((count != 0 && (str[count - 1] == '+' || str[count - 1] == '-' || str[count - 1] == '*' ||
                                    str[count - 1] == '/' || str[count - 1] == '(')) ||
                    count == 0)
                    flag = 0;
                space(&count_out, out);
                while (stack->array[stack->top] == '+' || stack->array[stack->top] == '-' ||
                       stack->array[stack->top] == '*' || stack->array[stack->top] == '/' ||
                       stack->array[stack->top] == 's' || stack->array[stack->top] == 'c' ||
                       stack->array[stack->top] == 'l' || stack->array[stack->top] == 't' ||
                       stack->array[stack->top] == 'g') {
                    out[count_out] = pop(stack);
                    count_out++;
                    out[count_out] = ' ';
                    count_out++;
                }
                push(stack, str[count]);
                break;
            case '-':
                if ((count != 0 && (str[count - 1] == '+' || str[count - 1] == '-' || str[count - 1] == '*' ||
                                    str[count - 1] == '/')))
                    flag = 0;
                space(&count_out, out);
                if (count == 0 || str[count - 1] == '(') {
                    out[count_out] = '0';
                    count_out++;
                    out[count_out] = ' ';
                    count_out++;
                }
                while (stack->array[stack->top] == '+' || stack->array[stack->top] == '-' ||
                       stack->array[stack->top] == '*' || stack->array[stack->top] == '/' ||
                       stack->array[stack->top] == 's' || stack->array[stack->top] == 'c' ||
                       stack->array[stack->top] == 'l' || stack->array[stack->top] == 't' ||
                       stack->array[stack->top] == 'g') {
                    out[count_out] = pop(stack);
                    count_out++;
                    out[count_out] = ' ';
                    count_out++;
                }
                push(stack, str[count]);
                break;
            case '*':
                if ((count != 0 && (str[count - 1] == '+' || str[count - 1] == '-' || str[count - 1] == '*' ||
                                    str[count - 1] == '/' || str[count - 1] == '(')) ||
                    count == 0)
                    flag = 0;
                space(&count_out, out);
                while (stack->array[stack->top] == '*' || stack->array[stack->top] == '/' ||
                       stack->array[stack->top] == 's' || stack->array[stack->top] == 'c' ||
                       stack->array[stack->top] == 'l' || stack->array[stack->top] == 't' ||
                       stack->array[stack->top] == 'g') {
                    out[count_out] = pop(stack);
                    count_out++;
                    out[count_out] = ' ';
                    count_out++;
                }
                push(stack, str[count]);
                break;
            case '/':
                if ((count != 0 && (str[count - 1] == '+' || str[count - 1] == '-' || str[count - 1] == '*' ||
                                    str[count - 1] == '/' || str[count - 1] == '(')) ||
                    count == 0)
                    flag = 0;
                space(&count_out, out);
                while (stack->array[stack->top] == '*' || stack->array[stack->top] == '/' ||
                       stack->array[stack->top] == 's' || stack->array[stack->top] == 'c' ||
                       stack->array[stack->top] == 'l' || stack->array[stack->top] == 't' ||
                       stack->array[stack->top] == 'g') {
                    out[count_out] = pop(stack);
                    count_out++;
                    out[count_out] = ' ';
                    count_out++;
                }
                push(stack, str[count]);
                break;

            case 's':
                if (count != 0 && (str[count - 1] != '+' && str[count - 1] != '-' && str[count - 1] != '*' &&
                                   str[count - 1] != '/' && str[count - 1] != '('))
                    flag = 0;
                space(&count_out, out);
                if (str[count + 1] == 'i' && str[count + 2] == 'n') {
                    while (stack->array[stack->top] == 's' || stack->array[stack->top] == 'c' ||
                           stack->array[stack->top] == 'l' || stack->array[stack->top] == 't' ||
                           stack->array[stack->top] == 'g') {
                        out[count_out] = pop(stack);
                        count_out++;
                        out[count_out] = ' ';
                        count_out++;
                    }
                    push(stack, 's');
                    count = count + 2;
                } else if (str[count + 1] == 'q' && str[count + 2] == 'r' && str[count + 3] == 't') {
                    while (stack->array[stack->top] == 's' || stack->array[stack->top] == 'c' ||
                           stack->array[stack->top] == 'l' || stack->array[stack->top] == 't' ||
                           stack->array[stack->top] == 'g') {
                        out[count_out] = pop(stack);
                        count_out++;
                        out[count_out] = ' ';
                        count_out++;
                    }
                    push(stack, 'q');
                    count = count + 3;
                }
                break;
            case 'c':
                if (count != 0 && (str[count - 1] != '+' && str[count - 1] != '-' && str[count - 1] != '*' &&
                                   str[count - 1] != '/' && str[count - 1] != '('))
                    flag = 0;
                space(&count_out, out);
                if (str[count + 1] == 'o' && str[count + 2] == 's') {
                    while (stack->array[stack->top] == 's' || stack->array[stack->top] == 'c' ||
                           stack->array[stack->top] == 'l' || stack->array[stack->top] == 't' ||
                           stack->array[stack->top] == 'g') {
                        out[count_out] = pop(stack);
                        count_out++;
                        out[count_out] = ' ';
                        count_out++;
                    }
                    push(stack, 'c');
                    count = count + 2;
                } else if (str[count + 1] == 't' && str[count + 2] == 'g') {
                    while (stack->array[stack->top] == 's' || stack->array[stack->top] == 'c' ||
                           stack->array[stack->top] == 'l' || stack->array[stack->top] == 't' ||
                           stack->array[stack->top] == 'g') {
                        out[count_out] = pop(stack);
                        count_out++;
                        out[count_out] = ' ';
                        count_out++;
                    }
                    push(stack, 'g');
                    count = count + 2;
                }
                break;
            case 't':
                if (count != 0 && (str[count - 1] != '+' && str[count - 1] != '-' && str[count - 1] != '*' &&
                                   str[count - 1] != '/' && str[count - 1] != '('))
                    flag = 0;
                space(&count_out, out);
                if (str[count + 1] == 'a' && str[count + 2] == 'n') {
                    while (stack->array[stack->top] == 's' || stack->array[stack->top] == 'c' ||
                           stack->array[stack->top] == 'l' || stack->array[stack->top] == 't' ||
                           stack->array[stack->top] == 'g') {
                        out[count_out] = pop(stack);
                        count_out++;
                        out[count_out] = ' ';
                        count_out++;
                    }
                    push(stack, 't');
                    count = count + 2;
                }
                break;
            case 'l':
                if (count != 0 && (str[count - 1] != '+' && str[count - 1] != '-' && str[count - 1] != '*' &&
                                   str[count - 1] != '/' && str[count - 1] != '('))
                    flag = 0;
                space(&count_out, out);
                if (str[count + 1] == 'n') {
                    while (stack->array[stack->top] == 's' || stack->array[stack->top] == 'c' ||
                           stack->array[stack->top] == 'l' || stack->array[stack->top] == 't' ||
                           stack->array[stack->top] == 'g') {
                        out[count_out] = pop(stack);
                        count_out++;
                    }
                    push(stack, 'l');
                    count = count + 1;
                }
                break;

            case '(':
                count_parenthesis++;
                push(stack, str[count]);
                break;
            case ')':
                count_parenthesis--;
                if (count_parenthesis >= 0) {
                    while (stack->array[stack->top] != '(') {
                        out[count_out] = ' ';
                        count_out++;
                        out[count_out] = pop(stack);
                        count_out++;
                    }
                    del(stack);
                }
                break;

            default:
                if (str[count] == '\n') break;
                out[count_out] = str[count];
                count_out++;
        }

        count++;
    }
    for (int i = 0; i < stack->top + 2; count_out++, i++) {
        out[count_out] = ' ';
        count_out++;
        out[count_out] = pop(stack);
    }
    if (count_parenthesis != 0) flag = 0;

    printf("\n");
    if (flag != 0) {
        double arr_y[WIDTH];
        double arr_x[WIDTH];
        x_y(arr_x, arr_y, out, count_out);
        int **field;
        field = (int **)malloc(HEIGHT * sizeof(int *));
        for (int i = 0; i < HEIGHT; i++) {
            field[i] = malloc(WIDTH * sizeof(int));
        }
        fill(field);
        func(field, arr_y, arr_x);
        draw(field);

        free(field);
        for (int i = 0; i < HEIGHT; i++) {
            free(field[i]);
        }
    } else
        printf("n/a");

    destroy(stack);

    return 0;
}
