#include <stdio.h>
#include <stdlib.h>
#define N 3  // Fixed size for the deque

int front = -1, rear = -1, dq[N];

void insertFront(int item) {
    if ((front == 0 && rear == N - 1) || (rear + 1) % N == front) {
        printf("Deque overflow\n");
    } else {
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (front == 0) {
            front = N - 1;
        } else {
            front--;
        }
        dq[front] = item;
        printf("%d successfully inserted at the front\n", item);
    }
}

void insertRear(int item) {
    if ((front == 0 && rear == N - 1) || (rear + 1) % N == front) {
        printf("Deque overflow\n");
    } else {
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == N - 1) {
            rear = 0;
        } else {
            rear++;
        }
        dq[rear] = item;
        printf("%d successfully inserted at the rear\n", item);
    }
}

int deleteFront() {
    if (front == -1) {
        printf("Deque underflow\n");
        return -1;
    }
    int item = dq[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == N - 1) {
        front = 0;
    } else {
        front++;
    }
    printf("%d successfully deleted from the front\n", item);
    return item;
}

int deleteRear() {
    if (front == -1) {
        printf("Deque underflow\n");
        return -1;
    }
    int item = dq[rear];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (rear == 0) {
        rear = N - 1;
    } else {
        rear--;
    }
    printf("%d successfully deleted from the rear\n", item);
    return item;
}

void display() {
    if (front == -1) {
        printf("Deque is empty\n");
    } else {
        printf("Deque elements: ");
        int i = front;
        while (1) {
            printf("%d", dq[i]);
            if (i == rear) break; // Stop after printing the last element
            printf(" -> "); // Print arrow between elements
            i = (i + 1) % N;
        }
        printf(" -> NULL\n"); // Print NULL at the end
    }
}

int main() {
    int item, choice;

    do {
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to be inserted at the front: ");
                scanf("%d", &item);
                insertFront(item);
                break;
            case 2:
                printf("Enter element to be inserted at the rear: ");
                scanf("%d", &item);
                insertRear(item);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("\nExiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (1);

    return 0;
}
