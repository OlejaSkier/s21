#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100

int main() {
    int array[N][N];
    int choice, flag, line_array, colum_array;
    char between, end;
    scanf("%d%c", &choice, &end);
    if (end != '\n') flag = 1;
    if (flag != 1) {
        if (choice == 1) {
            //static matrix
            scanf("%d%c%d%c", &line_array, &between, &colum_array, &end);
            if (between != ' ' || end != '\n') flag = 1;
            int d;
            for (int i = 0; i < line_array; i++)
                for (int j = 0; j < colum_array; j++, d = scanf("%d", &array[i][j]))
                    if (d != 1) flag = 1;
        }
        else if (choice == 2) {
            //first dynamic matrix
        }
        else if (choice == 3) {
            //second dynamic matrix
        }
        else if (choice == 4) {
            //third dynamic matrix
        }
        else printf("n/a");
        for (int i = 0; i < line_array; i++) {
            for (int j = 0; j < colum_array; j++, printf("%d ", array[i][j]));
            printf("\n");
        }
    }
    else printf("n/a");
}