#include <stdio.h>
#include <stdlib.h> 

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x) {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if (rear == NULL) { 
        front = rear = newnode;
        rear->next = front;  
    } else {
        rear->next = newnode;
        rear = newnode;
        rear->next = front; 
    }
}

void dequeue() {
    if (front == NULL) { 
        printf("\nQueue is empty");
        return;
    }
    struct node *temp = front;
    if (front == rear) {  
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front;
    }
    free(temp);
}

void peek() {
    if (front == NULL) {  
        printf("\nQueue is empty");
    } else {
        printf("\nThe front element is %d", front->data);
    }
}

void display() {
    if (front == NULL) {  
        printf("\nQueue is empty");
        return;
    }
    struct node *temp = front;
    printf("\nThe elements in the Queue are: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\nMenu:");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                while (front != NULL) {
                    dequeue();
                }
                printf("\nExiting...");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.");
        }
    }
    return 0;
}
