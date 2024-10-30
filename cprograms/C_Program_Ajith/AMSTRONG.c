#include <stdio.h>
int main(){
    int num, originalNum, remainder, result = 0;
    printf("enter a three digit number: ");
    scanf("%d",&num);
    originalNum = num;
    while (originalNum != 0)
    {
       remainder = originalNum % 10;
       result += remainder * remainder * remainder;
       originalNum /= 10;
    }
    if(result == num){
        printf("Amstrong number");
    }
    else{
        printf("Not an amstrong");
    }
    return 0;
}
