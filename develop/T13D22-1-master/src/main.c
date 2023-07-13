#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f1, *f2;
    f1 = fopen("input.txt", "r");
    f2 = fopen("input2.txt", "r");
    printf("f1=%d f2=%d", f1, f2);
    fclose(f1);
    fclose(f2);
}