#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
struct node {
    int val;            // Value stored in the node
    struct node *link;  // Pointer to the next node in the list
};

// Global variable for the head of the list and a placeholder for the value to be inserted
struct node *head = NULL;
int value;

// Function to insert a node at the beginning of the list
void Insert_Begin() {
    struct node *temp = (struct node*)malloc(sizeof(struct node));  // Allocate memory for the new node
    if (!temp) {  // Check if memory allocation failed
        printf("Memory overflow\n");
        return;
    }

    printf("Enter the element to insert: ");
    scanf("%d", &value);  // Get the value to insert from the user
    temp->val = value;    // Assign the value to the new node
    temp->link = head;    // Point the new node's link to the current head
    head = temp;          // Update head to the new node
}

// Function to insert a node at the end of the list
void Insert_End() {
    struct node *temp = (struct node*)malloc(sizeof(struct node));  // Allocate memory for the new node
    if (!temp) {  // Check if memory allocation failed
        printf("Memory overflow\n");
        return;
    }

    printf("Enter the element to insert: ");
    scanf("%d", &value);  // Get the value to insert from the user
    temp->val = value;    // Assign the value to the new node
    temp->link = NULL;    // Set the new node's link to NULL as it will be the last node

    if (head == NULL) {
        // If the list is empty, the new node becomes the head
        head = temp;
    } else {
        // Otherwise, traverse to the end of the list
        struct node *ptr = head;
        while (ptr->link != NULL) {
            ptr = ptr->link;
        }
        ptr->link = temp;  // Set the last node's link to the new node
    }
}

// Function to insert a node after a specific value in the list
void Insert_AnyPos() {
    int key;
    printf("Enter the element to insert: ");
    scanf("%d", &value);  // Get the value to insert
    printf("Enter the value after which to insert: ");
    scanf("%d", &key);    // Get the value of the node after which to insert the new node

    struct node *ptr = head;
    // Traverse the list to find the node with the given key
    while (ptr != NULL && ptr->val != key) {
        ptr = ptr->link;
    }

    if (ptr == NULL) {
        printf("Value not found\n");  // Key not found in the list
        return;
    }

    struct node *temp = (struct node*)malloc(sizeof(struct node));  // Allocate memory for the new node
    if (!temp) {  // Check if memory allocation failed
        printf("Memory overflow\n");
        return;
    }

    temp->val = value;    // Set the value for the new node
    temp->link = ptr->link;  // Link the new node to the node after the key
    ptr->link = temp;     // Link the key node to the new node
}

// Function to delete the node at the beginning of the list
void Delete_Begin() {
    if (head == NULL) {
        printf("List is empty\n");  // Check if the list is empty
        return;
    }

    struct node *ptr = head;  // Temporarily store the current head
    head = head->link;        // Update the head to the next node
    free(ptr);                // Free the memory of the old head
}

// Function to delete the node at the end of the list
void Delete_End() {
    if (head == NULL) {
        printf("List is empty\n");  // Check if the list is empty
        return;
    }

    struct node *ptr = head, *temp = NULL;

    if (head->link == NULL) {
        // If the list has only one node, update the head to NULL
        head = NULL;
    } else {
        // Traverse to the second last node
        while (ptr->link != NULL) {
            temp = ptr;
            ptr = ptr->link;
        }
        temp->link = NULL;  // Remove the last node by setting the second last node's link to NULL
    }
    free(ptr);  // Free the memory of the last node
}

// Function to delete a node with a specific value in the list
void Delete_AnyPos() {
    int key;
    printf("Enter the value to delete: ");
    scanf("%d", &key);  // Get the value to delete

    struct node *ptr = head, *temp = NULL;

    if (head == NULL) {
        printf("List is empty\n");  // Check if the list is empty
        return;
    }

    if (head->val == key) {
        // If the node to delete is the head, update the head
        head = head->link;
        free(ptr);  // Free the memory of the old head
        return;
    }

    // Traverse the list to find the node with the given key
    while (ptr != NULL && ptr->val != key) {
        temp = ptr;
        ptr = ptr->link;
    }

    if (ptr == NULL) {
        printf("Value not found\n");  // Key not found in the list
        return;
    }

    temp->link = ptr->link;  // Update the link to skip the node to delete
    free(ptr);               // Free the memory of the node to delete
}

// Function to display the elements in the list
void Display() {
    struct node *ptr = head;
    if (head == NULL) {
        printf("List is empty\n");  // Check if the list is empty
        return;
    }

    printf("\nList Elements: ");
    // Traverse the list and print the values
    while (ptr != NULL) {
        printf("%d-> ", ptr->val);
        ptr = ptr->link;
    }
    printf("NULL\n");  // Indicate the end of the list
}


int main() {
    int s = 0;
    char option;

    while(1) {
        // Main menu for insertion, deletion, and display operations
        printf("Enter your choice: ")
        printf("\n1: Insertion\n2: Deletion\n3: Display\n4: Exit\nChoice: ");
        scanf("%d", &s);
        switch (s) {
            case 1:
                // Sub menu for choosing where to insert
                printf("\nSelect Position\n1: Front\n2: End\n3: Between Nodes\nChoice: ");
                scanf("%d", &s);
                switch (s) {
                    case 1: Insert_Begin();
                        break;  // Insert at the front
                    case 2: Insert_End();
                        break;    // Insert at the end
                    case 3: Insert_AnyPos();
                        break; // Insert at a specific position
                    default: printf("Wrong Input\n");
                }
                break;
            case 2:
                // Sub menu for choosing which node to delete
                printf("\nSelect Position\n1: Front\n2: End\n3: Between Nodes\nChoice: ");
                scanf("%d", &s);
                switch (s) {
                    case 1: Delete_Begin();
                        break;  // Delete from the front
                    case 2: Delete_End();
                        break;    // Delete from the end
                    case 3: Delete_AnyPos();
                        break; // Delete a specific node
                    default: printf("Wrong Input\n");
                }
                break;
            case 3:
                Display();  // Display the list
                break;
            case 4:
                printf("Exited!");  // Exit the program
                exit(0);
            default:
                printf("Wrong Choice!");
        }
    }

    printf("Exited!");
    return 0;
}
