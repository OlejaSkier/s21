#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct Stack {
    int top;
    unsigned capacity;
    int *array;
};

struct Stack* creatStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
};

/**
 * @brief Проверяет заполненный стек или нет
 * @param stack
*/
int isFull(struct Stack* stack);

/**
 * @brief Проверяет пустой стек или нет
 * @param stack
*/
int isEmpty(struct Stack* stack);

/**
 * @brief Помещает элемент сверху стека
 * @param stack
 * @param element
*/
void push(struct Stack* stack, int item);

/**
 * @brief Изымает верхний элемент стека
 * @param stack
*/
char pop(struct Stack* stack);

/**
 * @brief Убивает стек
*/
void destroy(struct Stack* stack);

/**
 * @brief Удаляет элемент стека
*/
void delete(struct Stack* stack);

int main() {
    /**
     * @brief Куда считываем вводимую строку
    */
    char str[100];
    /**
     * @brief Куда выводим готовую сторку
    */
    char out[100];

    struct Stack* stack = creatStack(100);

    gets(str);

    int count = 0, count_out = 0;;

    while(str[count] != '\0') {
        switch (str[count]) {
            case '+':
                if (count_out != 0 && out[count_out - 1] != ' ') {
                    out[count_out] = ' ';
                    count_out++;
                }
                while(stack->array[stack->top] == '+' || stack->array[stack->top] == '-' || stack->array[stack->top] == '*' || stack->array[stack->top] == '/' || stack->array[stack->top] == 's' || stack->array[stack->top] == 'c' || stack->array[stack->top] == 'l' || stack->array[stack->top] == 't' || stack->array[stack->top] == 'g') {
                    out[count_out] = pop(stack);
                    count_out++;
                    out[count_out] = ' ';
                    count_out++;
                }
                push(stack, str[count]);
                break;
            case '-':
                if (count_out != 0 && out[count_out - 1] != ' ') {
                    out[count_out] = ' ';
                    count_out++;
                }
                if (count == 0 || str[count - 1] == '(') {
                    out[count_out] = '0';
                    count_out++;
                    out[count_out] = ' ';
                    count_out++;
                }
                while(stack->array[stack->top] == '+' || stack->array[stack->top] == '-' || stack->array[stack->top] == '*' || stack->array[stack->top] == '/' || stack->array[stack->top] == 's' || stack->array[stack->top] == 'c' || stack->array[stack->top] == 'l' || stack->array[stack->top] == 't' || stack->array[stack->top] == 'g') {
                    out[count_out] = pop(stack);
                    count_out++;
                    out[count_out] = ' ';
                    count_out++;
                }
                push(stack, str[count]);
                break;
            case '*':
                if (count_out != 0 && out[count_out - 1] != ' ') {
                    out[count_out] = ' ';
                    count_out++;
                }
                while(stack->array[stack->top] == '*' || stack->array[stack->top] == '/' || stack->array[stack->top] == 's' || stack->array[stack->top] == 'c' || stack->array[stack->top] == 'l' || stack->array[stack->top] == 't' || stack->array[stack->top] == 'g') {
                    out[count_out] = pop(stack);
                    count_out++;
                    out[count_out] = ' ';
                    count_out++;
                }
                push(stack, str[count]);
                break;
            case '/':
                if (count_out != 0 && out[count_out - 1] != ' ') {
                    out[count_out] = ' ';
                    count_out++;
                }
                while(stack->array[stack->top] == '*' || stack->array[stack->top] == '/' || stack->array[stack->top] == 's' || stack->array[stack->top] == 'c' || stack->array[stack->top] == 'l' || stack->array[stack->top] == 't' || stack->array[stack->top] == 'g') {
                    out[count_out] = pop(stack);
                    count_out++;
                    out[count_out] = ' ';
                    count_out++;
                }
                push(stack, str[count]);
                break;

            case 's':
                if (count_out != 0 && out[count_out - 1] != ' ') {
                    out[count_out] = ' ';
                    count_out++;
                }
                if (str[count + 1] == 'i' && str[count + 2] == 'n') {
                    while(stack->array[stack->top] == 's' || stack->array[stack->top] == 'c' || stack->array[stack->top] == 'l' || stack->array[stack->top] == 't' || stack->array[stack->top] == 'g') {
                        out[count_out] = pop(stack);
                        count_out++;
                        out[count_out] = ' ';
                        count_out++;
                    }
                    push(stack, 's');
                    count = count + 2;
                }
                else if (str[count + 1] == 'q' && str[count + 2] == 'r' && str[count + 3] == 't') {
                    while(stack->array[stack->top] == 's' || stack->array[stack->top] == 'c' || stack->array[stack->top] == 'l' || stack->array[stack->top] == 't' || stack->array[stack->top] == 'g') {
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
                if (count_out != 0 && out[count_out - 1] != ' ') {
                    out[count_out] = ' ';
                    count_out++;
                }
                if (str[count + 1] == 'o' && str[count + 2] == 's') {
                    while(stack->array[stack->top] == 's' || stack->array[stack->top] == 'c' || stack->array[stack->top] == 'l' || stack->array[stack->top] == 't' || stack->array[stack->top] == 'g') {
                        out[count_out] = pop(stack);
                        count_out++;
                        out[count_out] = ' ';
                        count_out++;
                    }
                    push(stack, 'c');
                    count = count + 2;
                }
                else if (str[count + 1] == 't' && str[count + 2] == 'g') {
                    while(stack->array[stack->top] == 's' || stack->array[stack->top] == 'c' || stack->array[stack->top] == 'l' || stack->array[stack->top] == 't' || stack->array[stack->top] == 'g') {
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
                if (count_out != 0 && out[count_out - 1] != ' ') {
                    out[count_out] = ' ';
                    count_out++;
                }
                if (str[count + 1] == 'a' && str[count + 2] == 'n') {
                    while(stack->array[stack->top] == 's' || stack->array[stack->top] == 'c' || stack->array[stack->top] == 'l' || stack->array[stack->top] == 't' || stack->array[stack->top] == 'g') {
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
                if (count_out != 0 && out[count_out - 1] != ' ') {
                    out[count_out] = ' ';
                    count_out++;
                }
                if (str[count + 1] == 'n') {
                    while(stack->array[stack->top] == 's' || stack->array[stack->top] == 'c' || stack->array[stack->top] == 'l' || stack->array[stack->top] == 't' || stack->array[stack->top] == 'g') {
                        out[count_out] = pop(stack);
                        count_out++;
                    }
                    push(stack, 'l');
                    count = count + 1;
                }
                break;

            case '(':
                push(stack, str[count]);
                break;
            case ')':
                while(stack->array[stack->top] != '(') {
                    out[count_out] = ' ';
                    count_out++;
                    out[count_out] = pop(stack);
                    count_out++;
                }
                delete(stack);
                break;

            default:
                if(str[count] == '\n') break;
                out[count_out] = str[count];
                count_out++;
        }

        count++;
    }
    for (int i = 0; i < stack->top + 2; count_out++, i++){
        out[count_out] = ' ';
        count_out++;
        out[count_out] = pop(stack);
        }

    printf("Stack = ");
    for (int i = 0; i < count; i++)
        printf("%c", pop(stack));
    printf("\nStdout = ");
    for (int i = 0; i < count_out; i++)
        printf("%c", out[i]);

    // for (int i = 0; i < count_out; i++)
    //     printf("\nout[%d] = `%c`", i, out[i]);
    // destroy(stack);

    return 0;
}

char pop(struct Stack* stack) {
    if(isEmpty(stack)) return 0;
    return stack->array[stack->top--];
}

void push(struct Stack* stack, int item) {
    if(isFull(stack)) return;
    stack->array[++stack->top] = item;
}

int isFull(struct Stack* stack) {
    return stack->top == (int) stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void destroy(struct Stack* stack) {
    free(stack->array);
    free(stack);
    stack = NULL;
}

void delete(struct Stack* stack) {
    stack->top--;
}
