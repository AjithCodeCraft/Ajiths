#include <stdio.h>
int main()
{
    int i,n;
    int k1 =0,k2 = 1;
    int nextTerm =k1+k2;
    printf("Enter next term: ");
    scanf("%d",&n);
    printf("The numbers are %d,%d,",k1,k2);
    for(i = 3 ;i<=n; i++){
        printf("%d, ", nextTerm);
        k1 = k2;
        k2= nextTerm;
        nextTerm = k1+k2;
    }
    return 0;
}
