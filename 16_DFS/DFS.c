#include <stdio.h>

#define MAX 100 // Maximum number of vertices

int stack[MAX];
int top = -1;
int visited[MAX]; // Array to keep track of visited vertices

// Function to push an element onto the stack
void push(int vertex) {
    if (top == MAX - 1) {
        printf("Stack is full\n");
        return;
    }
    stack[++top] = vertex;
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top--];
}

// DFS function
void dfs(int graph[MAX][MAX], int startVertex, int n) {
    // Mark the start vertex as visited and push it onto the stack
    visited[startVertex] = 1;
    push(startVertex);

    printf("DFS traversal: ");
    while (top != -1) { // Continue until the stack is empty
        int currentVertex = pop();
        printf("%d ", currentVertex);

        // Visit all adjacent vertices
        for (int i = 0; i < n; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) { // Check if there's an edge and the vertex is not visited
                visited[i] = 1;
                push(i);
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

    // Perform DFS traversal
    dfs(graph, startVertex, n);

    return 0;
}
