#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Stack {
    int top;
    unsigned capacity;
    int *array;
};

/**
 * @brief Создает стек размера capacity
 * @param capacity размерность стека
*/
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
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
     * @brief выходной массив
    */
    char out[100];
    char c = 0;
    struct Stack* stack = createStack(100);
    
    int count = 0, j = 0;
    
    
    while(c != '\n') {
        c = getchar();
        switch(c) {
            case '*':
                while (stack->array[stack->top] == '*' || stack->array[stack->top] == '/' || stack->array[stack->top] == 's' || stack->array[stack->top] == 'c' || stack->array[stack->top] == 'l' || stack->array[stack->top] == 't' || stack->array[stack->top] == 'g') {
                    out[j] = pop(stack);
                    j++;
                    out[j] = ' ';
                    j++;
                }
                push(stack, c);
                count++;
                break;
            case '/':
                while (stack->array[stack->top] == '*' || stack->array[stack->top] == '/' || stack->array[stack->top] == 's' || stack->array[stack->top] == 'c' || stack->array[stack->top] == 'l' || stack->array[stack->top] == 't' || stack->array[stack->top] == 'g') {
                    out[j] = pop(stack);
                    j++;
                    out[j] = ' ';
                    j++;
                }
                push(stack, c);
                count++;
                break;
            case '+':
                while (stack->array[stack->top] == '+' || stack->array[stack->top] == '-' || stack->array[stack->top] == '*' || stack->array[stack->top] == '/' || stack->array[stack->top] == 's' || stack->array[stack->top] == 'c' || stack->array[stack->top] == 'l' || stack->array[stack->top] == 't' || stack->array[stack->top] == 'g') {
                    out[j] = pop(stack);
                    j++;
                    out[j] = ' ';
                    j++;
                }
                push(stack, c);
                count++;
                break;
            case '-':
                while (stack->array[stack->top] == '+' || stack->array[stack->top] == '-' || stack->array[stack->top] == '*' || stack->array[stack->top] == '/' || stack->array[stack->top] == 's' || stack->array[stack->top] == 'c' || stack->array[stack->top] == 'l' || stack->array[stack->top] == 't' || stack->array[stack->top] == 'g') {
                    out[j] = pop(stack);
                    j++;
                    out[j] = ' ';
                    j++;
                }
                push(stack, c);
                count++;
                break;
            case 's':
                c = getchar();
                if (c == 'i' || c == 'q') {
                    c = getchar();
                    if (c == 'n' || c == 'r') {
                        if (c == 'r') {
                            c = getchar();
                            if (c == 't') {
                                while (stack->array[stack->top] == 's' || stack->array[stack->top] == 'c' || stack->array[stack->top] == 'l' || stack->array[stack->top] == 't' || stack->array[stack->top] == 'g') {
                                    out[j] = pop(stack);
                                    j++;
                                    out[j] = ' ';
                                    j++;
                                }
                                push(stack, 'q');
                                count++;
                            }
                        } else {
                            while (stack->array[stack->top] == 's' || stack->array[stack->top] == 'c' || stack->array[stack->top] == 'l' || stack->array[stack->top] == 't' || stack->array[stack->top] == 'g') {
                                out[j] = pop(stack);
                                j++;
                                out[j] = ' ';
                                j++;
                            }
                            push(stack, 's');
                            count++;
                        }
                    }
                }
                break;
            case 'c':
                c = getchar();
                if (c == 'o') {
                    c = getchar();
                    if (c == 's') {
                        while (stack->array[stack->top] == 's' || stack->array[stack->top] == 'c' || stack->array[stack->top] == 'l' || stack->array[stack->top] == 't' || stack->array[stack->top] == 'g') {
                            out[j] = pop(stack);
                            j++;
                            out[j] = ' ';
                            j++;
                        }
                        push(stack, 'c');
                        count++;
                    }
                }
                else {
                    c = getchar();
                    if (c == 't') {
                        c = getchar();
                        if (c == 'g') {
                            while (stack->array[stack->top] == 's' || stack->array[stack->top] == 'c' || stack->array[stack->top] == 'l' || stack->array[stack->top] == 't' || stack->array[stack->top] == 'g') {
                                out[j] = pop(stack);
                                j++;
                                out[j] = ' ';
                                j++;
                            }
                            push(stack, 'g');
                            count++;
                        }
                    }
                }
                break;
            case 't':
                c = getchar();
                if (c == 'a') {
                    c = getchar();
                    if (c == 'n') {
                        while (stack->array[stack->top] == 's' || stack->array[stack->top] == 'c' || stack->array[stack->top] == 'l' || stack->array[stack->top] == 't' || stack->array[stack->top] == 'g') {
                            out[j] = pop(stack);
                            j++;
                            out[j] = ' ';
                            j++;
                        }
                        push(stack, 't');
                        count++;
                    }
                }
                break;
            case 'l':
                c = getchar();
                if (c == 'n') {
                    while (stack->array[stack->top] == 's' || stack->array[stack->top] == 'c' || stack->array[stack->top] == 'l' || stack->array[stack->top] == 't' || stack->array[stack->top] == 'g') {
                        out[j] = pop(stack);
                        j++;
                        out[j] = ' ';
                        j++;
                    }
                    push(stack, 'l');
                    count++;
                }
                break;
            case '(':
                push(stack, c);
                count++;
                break;
            case ')':
                while(stack->array[stack->top] != '(') {
                    out[j] = pop(stack);
                    j++;
                    out[j] = ' ';
                    j++;
                }
                delete(stack);
                break;
            default:
                if (c == '\n') break;
                out[j] = c;
                j++;
                out[j] = ' ';
                j++;
                continue;
        }
    }
    for (int i = 0; i < stack->top + 2; i++, j++)
        out[j] = pop(stack);
    printf("stack = ");
    for (int i = 0; i < count; i++)
        printf("%c", pop(stack));
    printf("\n");
    printf("stdout = ");
    for (int i = 0; i < j; i++)
        printf("%c", out[i]);

    destroy(stack);
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
