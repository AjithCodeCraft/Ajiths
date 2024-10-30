 #include <stdio.h>
 #include <stdlib.h>

 #define SIZE 4
int top= -1,inp_array[SIZE];
void push();
void pop();
void show();

int main(){
    int choice;
    while(1)
    {
        printf("\n1.Push an element\n2.Pop the element\n3.Show\n4.End");
        printf("\n\n Enter the choice");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
           pop();
           break;
        case 3:
           show();
           break;
        case 4:
          exit(0);
        
        
        default:
            printf("\n Invalid choice \n");
        }
    }
}
void push(){
    int x;
    if(top ==SIZE-1)
    {
        printf("\n OverFlow");

    }
    else{
        printf("\n Enter the element to be added onto the stack");
        scanf("%d",&x);
        top =top +1;
        inp_array[top] = x;
    }
}
void pop(){
    if(top ==-1){
        printf("\n UnderFlow");
    }
    else {
        printf("\n Popped element :%d",inp_array[top]);
        top = top -1;
    }
}
void show()
{
    if (top ==-1){
        printf("\n Under Flow");

    }
    else{
        printf("\n Elements present in the stack :\n");
        for (int i = top;i>=0;--i){
            printf("%d\n",inp_array[i]);
        }
    }
}