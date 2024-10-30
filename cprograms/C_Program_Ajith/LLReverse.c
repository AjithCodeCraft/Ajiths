#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

void addNode(struct Node** head, int new_data) {
    struct Node* new_node = createNode(new_data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
};


struct Node* reverseList(struct Node* head) {
    struct Node *curr = head, *prev = NULL, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main() {
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu");
        printf("\n1. Add value");
        printf("\n2. Print original list");
        printf("\n3. Print reversed list");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of elements you want to add: ");
                int numElements;
                scanf("%d", &numElements);
                for (int i = 0; i < numElements; i++) {
                    printf("Enter element %d: ", i + 1);
                    scanf("%d", &value);
                    addNode(&head, value);
                }
                break;

            case 2:
                printf("Original list: ");
                printList(head);
                break;

            case 3:
                head = reverseList(head);
                printf("Reversed list: ");
                printList(head);
                break;

            case 4:
                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;

            default:
                printf("Invalid choice, please enter a number between 1 and 4.\n");
                break;
        }
    }
}
