#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node {
    int data;                // Data stored in the node
    struct Node* left;       // Pointer to the left child
    struct Node* right;      // Pointer to the right child
};

// Function to create a new node
struct Node* createNode(int data) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {  // Check if memory allocation was successful
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);  // Exit the program if memory allocation fails
    }
    // Initialize the new node with the provided data and set left and right children to NULL
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;  // Return the created node
}

// Function to insert values in level order (breadth-first)
void insertLevelOrder(struct Node** root, int data) {
    // Create a new node with the provided data
    struct Node* newNode = createNode(data);
    
    // If the tree is empty, make the new node the root
    if (*root == NULL) {
        *root = newNode;
    } else {
        // Use a simple array-based queue for level-order traversal
        struct Node* queue[100];  // Queue with a fixed size of 100 (can be adjusted as needed)
        int front = 0, rear = 0;  // Initialize queue front and rear indices
        
        // Enqueue the root node to start level order traversal
        queue[rear++] = *root;
        
        // Loop through the queue until the correct position for insertion is found
        while (front < rear) {
            // Dequeue the current node
            struct Node* current = queue[front++];
            
            // Check if the left child is empty
            if (current->left == NULL) {
                // Insert the new node as the left child
                current->left = newNode;
                return;
            } else {
                // Otherwise, enqueue the left child for further checking
                queue[rear++] = current->left;
            }
            
            // Check if the right child is empty
            if (current->right == NULL) {
                // Insert the new node as the right child
                current->right = newNode;
                return;
            } else {
                // Otherwise, enqueue the right child for further checking
                queue[rear++] = current->right;
            }
        }
    }
}

// Function for in-order traversal (left-root-right)
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);  // Visit left subtree
        printf("%d ", root->data);     // Print root node's data
        inOrderTraversal(root->right); // Visit right subtree
    }
}

// Function for pre-order traversal (root-left-right)
void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);     // Print root node's data
        preOrderTraversal(root->left);  // Visit left subtree
        preOrderTraversal(root->right); // Visit right subtree
    }
}

// Function for post-order traversal (left-right-root)
void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);  // Visit left subtree
        postOrderTraversal(root->right); // Visit right subtree
        printf("%d ", root->data);       // Print root node's data
    }
}

// Function to free the memory of the binary tree
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);  // Free left subtree
        freeTree(root->right); // Free right subtree
        free(root);            // Free the current node
    }
}

// Main function to demonstrate the binary tree operations
int main() {
    struct Node* root = NULL;  // Initialize the root of the tree to NULL
    int n;

    // Prompt user for number of nodes to insert
    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    // Insert nodes into the binary tree using level order
    for (int i = 0; i < n; i++) {
        int value;
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        insertLevelOrder(&root, value);  // Insert each value into the tree
    }

    // Display the tree using different traversals
    printf("In-order Traversal of the Binary Tree:\n");
    inOrderTraversal(root);  // In-order traversal (left-root-right)
    printf("\n");

    printf("Pre-order Traversal of the Binary Tree:\n");
    preOrderTraversal(root);  // Pre-order traversal (root-left-right)
    printf("\n");

    printf("Post-order Traversal of the Binary Tree:\n");
    postOrderTraversal(root);  // Post-order traversal (left-right-root)
    printf("\n");

    // Free the allocated memory for the tree
    freeTree(root);

    return 0;  // End of program
}
