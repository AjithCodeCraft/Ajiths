#include <stdio.h>

int main() {
    int length;
    printf("Enter length of array: ");
    scanf("%d", &length);
    int a[length];
    printf("Enter the numbers:\n");
    for (int i = 0; i < length; i++) {
        scanf("%d", &a[i]); 
    for(int i=0;i<length;i++){
        printf("%d,",a[i]);
    }
    printf("\n");
    for(int i=length-1 ; i>=0;i--){
        printf("%d ,",a[i]);
    }

    return 0;
}
