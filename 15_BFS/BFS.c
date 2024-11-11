#include <stdio.h>

#define MAX 100 // Maximum number of vertices

int queue[MAX];
int front = -1, rear = -1;
int visited[MAX]; // Array to keep track of visited vertices

// Function to add an element to the queue
void enqueue(int vertex) {
    if (rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = vertex;
}

// Function to remove an element from the queue
int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return -1;
    }
    int vertex = queue[front];
    front++;
    return vertex;
}

// BFS function
void bfs(int graph[MAX][MAX], int startVertex, int n) {
    // Mark the start vertex as visited and enqueue it
    visited[startVertex] = 1;
    enqueue(startVertex);

    printf("BFS traversal: ");
    while (front <= rear) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        // Visit all adjacent vertices
        for (int i = 0; i < n; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

int main() {
    int n;
    int graph[MAX][MAX];

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Input the starting vertex
    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    // Perform BFS traversal
    bfs(graph, startVertex, n);

    return 0;
}
