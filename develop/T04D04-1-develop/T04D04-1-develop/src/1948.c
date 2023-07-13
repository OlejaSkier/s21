#include <stdio.h>
#include <math.h>

int delen(int x, int y) {
    int count = 0;

    while (x >= y) {
        x = x - y;
        count++;
    }

    return count;
}

int ostat(int x, int y) {

    while(x >= y) {
        x = x - y;
    }

    return x;
}

int is_simple(int x) {
    int flag = 1;
    
    for (int i = 2; i < x; i++) {
        if (ostat(x, i) == 0) flag = 0;
        
    }

    return flag;
}

int num_of_del(int x) {
    int i = 2;
    while (ostat(x, i) != 0) i++;
    return delen(x, i);
}

int main() {
    double a;
    scanf("%lf", &a);
    if (a < 0) {
        a = -a;
    }
    if ((int) a == a) {
        a = (int) a;
        a = num_of_del(a);

        while (is_simple(a) == 0) a = num_of_del(a);

        printf("%d", (int)a);
    }
    else printf("n/a");

    return 0;
}