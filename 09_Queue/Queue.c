#include <stdio.h>

#define MAX_SIZE 100  // Define the maximum size the queue can have

int queue[MAX_SIZE];
int front = -1;
int rear = -1;
int n;  // User-defined size of the queue

void enqueue(int x) {
    if (rear == n - 1) {
        printf("Overflow: Queue is full.\n");
    } else {
        if (front == -1 && rear == -1) {
            front = rear = 0;
        } else {
            rear++;
        }
        queue[rear] = x;
        printf("Enqueued: %d\n", x);
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Underflow: Queue is empty.\n");
    } else {
        printf("Dequeued: %d\n", queue[front]);
        if (front == rear) {
            front = rear = -1;  // Reset the queue when the last element is dequeued
        } else {
            front++;
        }
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the size of the queue (up to %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("Size exceeds maximum allowed size (%d). Exiting.\n", MAX_SIZE);
        return 1;
    }

    int choice, element;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
