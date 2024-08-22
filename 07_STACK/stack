#include <stdio.h>

#define MAX_SIZE 100

int top = -1;
int stack[MAX_SIZE];

void push(int x) {
    if(top == MAX_SIZE - 1) {
        printf("Stack is full. Overflow condition!\n");
        return;
    }
    stack[++top] = x;
}

int pop() {
    if(top == -1) {
        printf("Stack is empty. Underflow condition!\n");
        return -1;
    }
    return stack[top--];
}

void display() {
    if(top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements are: ");
    for(int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, x;
    while(1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                x = pop();
                if(x != -1)
                    printf("Popped element is: %d\n", x);
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
