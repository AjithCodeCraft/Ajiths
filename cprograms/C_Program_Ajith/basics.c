#include <stdio.h>
main()
{
    int I,SUM,N;
    printf("Enter value ");
    scanf("%d",&N);
    while(I<=N){
        SUM=SUM+I;
        I=I+1;
    }
    printf("%d",SUM);
};