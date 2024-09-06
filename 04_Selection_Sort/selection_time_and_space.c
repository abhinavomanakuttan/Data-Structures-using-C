#include <stdio.h>

int main() {
    int n, i, j, min, temp;
    int count =0;
    
     
    
    // Get the number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);
    count+=2;

    int arr[n];

    // Get the elements of the array
    printf("Enter elements:\n");
    count++;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        count+=2;
    }
    count++;

    // Selection Sort Algorithm
    for (i = 0; i < n-1; i++) {
        // Find the minimum element in unsorted array
        min = i;
        count+=2;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
                count+=3;
            }
        }
        count+=2;

        // Swap the found minimum element with the first element
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
        count+=3;
    }

    // Print sorted array
    printf("Sorted array: \n");
    count++;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        count+=2;
    }
    printf("\n");
    count+=2;
    
    int space =(n*6)*4;
    printf("\nspace complexity : %d",space);
    count++;
    count++;
    printf("\ntime complexity : %d ",count);
    return 0;
}
