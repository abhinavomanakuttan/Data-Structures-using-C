#include <stdio.h>

#define MAX 10 // Define the maximum size for the matrix and elements array

typedef struct{
    int row; // Row index of the element
    int col; // Column index of the element 
    int value; // value of the elemet(non-zero)
} Element;

int main() {
    int sparseMatrix[MAX][MAX]; // 2D array to store the matrix entered by the user
    Element elements[MAX];       // Array to store non-zero elements in a compact form
    int m, n, nonZeroCount = 0;  // The count of non-zero elements

    
    printf("Enter the number of rows: ");
    scanf("%d", &m);
    printf("Enter the number of columns: ");
    scanf("%d", &n);

    
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("(%d %d) :",i+1,j+1); // index of the matirx 
            scanf("%d", &sparseMatrix[i][j]);// Input each element of the matrix
        }
    }

     // Display the matrix entered by the user
     for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d  ", sparseMatrix[i][j]);
        }
        printf("\n");
    }
    // Loop through the matrix to find non-zero elements and store them in the elements array
     for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
              
            if (sparseMatrix[i][j] != 0) { // Check if the element is non-zero
                elements[nonZeroCount].row = i;
                elements[nonZeroCount].col = j;
                elements[nonZeroCount].value = sparseMatrix[i][j]; // Store the non-zero value
                nonZeroCount++;// Increment the count of non-zero elements
            }
        }
    }

   // Display the sparse matrix representation in (row, column, value) format
    printf("\nSparse Matrix Representation \n(Row, Column, Value):\n");
    printf("  %d     %d     %d \n",m,n,nonZeroCount);
    for (int i = 0; i < nonZeroCount; i++) {
    	
        printf("  %d     %d     %d \n", elements[i].row, elements[i].col, elements[i].value);
    }

    return 0;
}
