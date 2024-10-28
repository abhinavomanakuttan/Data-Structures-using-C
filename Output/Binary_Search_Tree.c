#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int item;               // item to be stored in the node
    struct Node* left;      // pointer to the left child
    struct Node* right;     // pointer to the right child
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->item = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert function for BST
struct Node* insert(struct Node* root, int item) {
    if (root == NULL) { // If the tree is empty, return a new node
        return createNode(item);
    }
    if (item < root->item) { // If the item to insert is less, insert in left subtree
        root->left = insert(root->left, item);
    } else if (item > root->item) { // If the item to insert is greater, insert in right subtree
        root->right = insert(root->right, item);
    }
    return root; // return the unchanged root pointer
}

// Inorder traversal of the tree (left-root-right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->item);
        inorder(root->right);
    }
}

// Preorder traversal of the tree (root-left-right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->item);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal of the tree (left-right-root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->item);
    }
}

int main() {
    struct Node* root = NULL;
    int n, item;

    // Insert items into the BST
    printf("Enter number of items to insert: ");
    scanf("%d", &n);
    printf("Enter the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &item);
        root = insert(root, item);
    }

    // Display the BST in different orders
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
