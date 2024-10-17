#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void push(struct Node** top, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Heap overflow\n");
        return;
    }
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed to stack\n", data);
}


void pop(struct Node** top) {
    struct Node* temp;
     if (*top == NULL)
    {
        printf("stack is empty");
        return;
    }
    else{
    temp = *top;
    int popped = temp->data;
    *top = (*top)->next;
    free(temp);
   
    }
}

void display(struct Node* top) {
     if (top == NULL)
    {
        printf("stack is empty");
        return;
    }
    else{
    struct Node* temp = top;
    printf("Stack elements are: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("Null\n");
}
}


int main() {
    struct Node* top = NULL;
    int choice, data, position;

    do {
        printf("\nMenu:\n");
        printf("1.push: \n");
        printf("2.pop: \n");
        printf("3.display: \n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                push(&top, data);
                break;
            case 2:
                pop(&top);
                break;
           
            case 3:
                printf("Linked list: ");
                display(top);
                break;
            case 4:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    while (top != NULL) {
       pop(&top);
    }

    return 0;
}


