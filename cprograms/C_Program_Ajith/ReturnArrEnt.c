#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int numbers[MAX_SIZE];
    int count = 0;
    int number;
    char ch;

    printf("Enter integers (press Enter on an empty line to finish):\n");

    while (1) {
        if (scanf("%d", &number) == 1) {
            numbers[count++] = number;
            if (count >= MAX_SIZE) {
                printf("Array size limit reached.\n");
                break;
            }
        } else {
            scanf("%*s");
            while ((ch = getchar()) != EOF && ch != '\n') {
            }

            if (ch == '\n') {
                break;
            }
        }
    }

    printf("The numbers you entered are:\n");
    for (int i = 0; i < count; i++) {
        printf("%d\n", numbers[i]);
    }

    return 0;
}
//ERROR