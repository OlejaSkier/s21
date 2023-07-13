#include "s21_string.h"

int s21_strlen(char *string) {
    int count = 0;

    for (int *p = string; *p != '\n'; p++)
        count++;
    
    return count;
}