#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void display(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void addElement(struct Node **head_ref, int new_data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

int searchElement(struct Node *head, int item) {
    struct Node *current = head;
    int index = 0;

    while (current != NULL) {
        if (current->data == item) {
            return index;
        }
        current = current->next;
        index++;
    }

    return -1;
}

int main() {
    struct Node *head = NULL;
    int item, new_data, num_elements, i;

    printf("Enter the number of elements in the initial list: ");
    scanf("%d", &num_elements);

    for (i = 0; i < num_elements; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &new_data);
        addElement(&head, new_data);
    }

    printf("Linked List: ");
    display(head);

    printf("Enter element to search: ");
    scanf("%d", &item);

    int index = searchElement(head, item);

    if (index == -1)
        printf("Item not found\n");
    else
        printf("Item found at position: %d\n", index + 1);

    printf("Enter new element to add: ");
    scanf("%d", &new_data);
    addElement(&head, new_data);

    printf("Updated Linked List: ");
    display(head);

    return 0;
}
