 #include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 3 // Fixed queue size of 3
int front = -1, rear = -1, cq[SIZE];

void enqueue(int item) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue overflow\n");
    } else {
        if (front == -1 && rear == -1) {
            front = 0; // Initialize front and rear for the first element
        }
        rear = (rear + 1) % SIZE; // Move rear to the next position
        cq[rear] = item; // Insert item
        printf("%d successfully inserted\n", item);
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue underflow\n");
    } else {
        printf("%d successfully deleted\n", cq[front]);
        cq[front] = 0; // Clear the position
        if (front == rear) { // Queue becomes empty
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE; // Move front to the next position
        }
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements:\n");
        int i = front;
        while (true) {
            printf("%d\t", cq[i]);
            if (i == rear) break; // Break if we've reached the rear
            i = (i + 1) % SIZE; // Circular increment
        }
        printf("\n");
    }
}

int main() {
    int item, choice;
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display queue elements\n4. Exit\nEnter your choice:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to be inserted: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (true);
    return 0; // Return statement for main
}
