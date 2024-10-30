#include <stdio.h>
#include<conio.h>
void main(){
    int s[20],i=-1,j;
    char a[20];
    printf("Enter The numbers");
    do{
        i++;
        fgets(a,10,stdin);
        sscanf(a,"%d",&s[i]);

    }
    while (a[0]!='\n');
        printf("the numbers are\n");
        for(j=0;j<i;j++)
        printf("%d\n",s[j]);
        getch();   

}