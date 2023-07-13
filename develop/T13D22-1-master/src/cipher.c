#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* file;
    int choose;
    char end;
    char filename[100] = "";
    scanf("%d%c", &choose, &end);
    if (end != '\n') printf("n/a\n");
    else {
        while (choose != -1) {
            switch (choose)
            {
            case 1:
                scanf("%99s", filename);
                file = fopen(filename, "r");
                if(file != NULL) {
                    do {
                        char content[100] = "";
                        fgets(content, 100, file);
                        printf("%s", content);
                    } while(!feof(file));
                    printf("\n");
                    fclose(file);
                } else printf("n/a\n");
                break;
            case 2:
                file = fopen(filename, "a+");
                char content[100] = "";
                gets(content);
                if(file != NULL) {
                    fprintf(file, "%s", content);
                    // while(!feof(file)) {
                    //     char cont[100] = "";
                    //     fscanf(file, "%s", cont);
                    //     printf("%s\n", cont);
                    // }
                    fclose(file);
                } else printf("n/a\n");
                break;
            
            default:
                break;
            }
            scanf("%d", &choose);
        }
    }

    return 0;
}