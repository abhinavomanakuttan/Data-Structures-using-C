#include <stdio.h>

int main() {
    int n, i, j, min, temp;

    // Get the number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Get the elements of the array
    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Selection Sort Algorithm
    for (i = 0; i < n-1; i++) {
        // Find the minimum element in unsorted array
        min = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        // Swap the found minimum element with the first element
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }

    // Print sorted array
    printf("Sorted array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
