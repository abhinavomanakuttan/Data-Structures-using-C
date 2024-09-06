#include <stdio.h>

int main() {
    int n, i, j, temp,count=0;

    // Get the number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);
    count+=2;
    
    int space=(4*n)*sizeof(int);
    int arr[n];

    // Get the elements of the array
    printf("Enter elements:\n");
    count++;
    
    for (i = 0; i < n; i++) {
    	printf("No%d: ", i + 1);
        scanf("%d", &arr[i]);
        count+=3;
    }

    // Bubble Sort Algorithm
    for (i = 0; i < n-1; i++) {
    		
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                count+=3;
            }
            
        }count++;
        
    }count++;

    // Print sorted array

    printf("Sorted array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        count+=2;
    }
    count++;
    printf("\nspace complexity : %d",space);
    count++;
    count++;
    printf("\ntime complexity : %d ",count);

    return 0;
}
