#include <stdio.h>

#define MAX 100

typedef struct{
    int row;
    int col;
    int value;
} Element;

int main() {
    int sparseMatrix[MAX][MAX];
    Element elements[MAX];
    int m, n, nonZeroCount = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &m);
    printf("Enter the number of columns: ");
    scanf("%d", &n);

    printf("Enter the elements of the matrix:\n");
    
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
        
            scanf("%d", &sparseMatrix[i][j]);
              
            
        }
    }
     for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
        
            printf("%d  ", sparseMatrix[i][j]);
                
        }
        printf("\n");
    }
    
     for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
              
            if (sparseMatrix[i][j] != 0) {
                elements[nonZeroCount].row = i;
                elements[nonZeroCount].col = j;
                elements[nonZeroCount].value = sparseMatrix[i][j];
                nonZeroCount++;
            }
        }
    }
    

    printf("\nSparse Matrix Representation \n(Row, Column, Value):\n");
    printf("%d   %d   %d \n",m,n,nonZeroCount);
    for (int i = 0; i < nonZeroCount; i++) {
    	
        printf("  %d   %d   %d \n", elements[i].row, elements[i].col, elements[i].value);
    }

    return 0;
}
