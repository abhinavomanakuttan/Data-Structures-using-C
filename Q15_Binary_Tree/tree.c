#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;                                                                                                                                                                                                                                   
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the binary tree
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

// In-order traversal
void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Pre-order traversal
void preOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Post-order traversal
void postOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Main function to demonstrate the binary tree with a menu
int main() {
    struct TreeNode* root = NULL;
    int choice, value;

    while(1){
        printf("\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. In-order traversal\n");
        printf("3. Pre-order traversal\n");
        printf("4. Post-order traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d inserted.\n", value);
                break;

            case 2:
                printf("In-order traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;

            case 3:
                printf("Pre-order traversal: ");
                preOrderTraversal(root);
                printf("\n");
                break;

            case 4:
                printf("Post-order traversal: ");
                postOrderTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting...\n");
                return 0;
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    // Freeing memory would typically go here (not shown for simplicity)

    return 0;
}

