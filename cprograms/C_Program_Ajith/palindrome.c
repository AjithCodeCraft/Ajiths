#include<stdio.h>
int main(){
    int number ;
    int result = 0;
    int q;
    int remainder;

    printf("ENTER NUMBER ");
    scanf("%d",&number);
    q = number;
    while (q!=0)
    {
        remainder =q%10;
        result = result*10+remainder;
        q =q/10;

    };
    if (number == result)
    {
        printf("its a palindrome %d",number);


    }
    else{
        printf("not a palindorme");
    }
  
    return 0;
}