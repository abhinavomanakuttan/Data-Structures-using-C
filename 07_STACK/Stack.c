#include <stdio.h>

#define MAX_SIZE 5  // Define the maximum size of the stack

int top = -1; // Initialize the top of the stack to -1 (indicating an empty stack)
int stack[MAX_SIZE]; // Array to store stack elements with a maximum capacity

// Function to push an element onto the stack
void push(int x) {
    if (top == MAX_SIZE - 1) {  // Check if the stack is full
        printf("Stack is full. Overflow condition!\n");
        return; // Exit the function if the stack is full
    }
    stack[++top] = x; // Increment top and assign the value to the stack
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {  // Check if the stack is empty
        printf("Stack is empty. Underflow condition!\n");
        return -1; // Return -1 if the stack is empty
    }
    return stack[top--];  // Return the top element and decrement top
}

// Function to display elements in the stack
void display() {
    if (top == -1) {  // Check if the stack is empty
        printf("Stack is empty.\n");
        return; // Exit the function if the stack is empty
    }
    printf("Stack elements are: ");
    for (int i = 0; i <= top; i++) {  // Loop through stack elements up to 'top'
        printf("%d ", stack[i]);  // Print each element in the stack
    }
    printf("\n");
}

// Main function to demonstrate stack operations
int main() {
    int choice, x;  // Variables to store user choice and the element to be pushed

    while (1) {  // Infinite loop to show the menu continuously until the user exits
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);  // Take the user's choice as input

        switch (choice) {  // Perform actions based on the user's choice
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &x);  // Take the element to push
                push(x);  // Call the push function with the user input
                break;
            case 2:
                x = pop();  // Call the pop function
                if (x != -1)  // If pop returns a valid element
                    printf("Popped element is: %d\n", x);
                break;
            case 3:
                display();  // Call the display function
                break;
            case 4:
                return 0;  // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
