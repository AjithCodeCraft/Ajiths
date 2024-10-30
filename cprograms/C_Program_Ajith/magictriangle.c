#include <stdio.h>

void print_star(int k) {
    int i, j;
    for (i = 0; i < k; i++) {
        for (j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int rows;
    
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    
    print_star(rows);
    
    return 0;
}
