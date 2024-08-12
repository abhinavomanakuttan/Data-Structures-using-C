#include <stdio.h>

#define MAX_TERMS 10  // Maximum number of terms in a polynomial

// Structure to represent a polynomial term
struct Term {
    int coefficient;
    int exponent;
};

int main() {
    struct Term P1[MAX_TERMS], P2[MAX_TERMS], P3[MAX_TERMS];
    int n1, n2, n3 = 0;
    int i = 0, j = 0, k = 0;

    // Step 3: Read the number of terms in P1 and P2
    printf("Enter the number of terms in polynomial P1: ");
    scanf("%d", &n1);
    printf("Enter the number of terms in polynomial P2: ");
    scanf("%d", &n2);

    // Step 4: Read two polynomials and store them in P1 and P2
    printf("Enter the terms for polynomial P1 (coefficient and exponent):\n");
    for (i = 0; i < n1; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &P1[i].coefficient, &P1[i].exponent);
    }

    printf("Enter the terms for polynomial P2 (coefficient and exponent):\n");
    for (i = 0; i < n2; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &P2[i].coefficient, &P2[i].exponent);
    }

    // Reset i and j to start the addition process
    i = 0;
    j = 0;

    // Step 5: Add the polynomials
    while (i < n1 && j < n2) {
        // Step 5.2.1: Check if P1[i].exponent > P2[j].exponent
        if (P1[i].exponent > P2[j].exponent) {
            P3[k] = P1[i];
            i++;
        }
        // Step 5.2.2: Check if P1[i].exponent < P2[j].exponent
        else if (P1[i].exponent < P2[j].exponent) {
            P3[k] = P2[j];
            j++;
        }
        // Step 5.2.3: If P1[i].exponent == P2[j].exponent
        else {
            P3[k].coefficient = P1[i].coefficient + P2[j].coefficient;
            P3[k].exponent = P1[i].exponent;
            i++;
            j++;
        }
        k++;
    }

    // Step 5.3: Copy the remaining terms of P1 (if any)
    while (i < n1) {
        P3[k] = P1[i];
        i++;
        k++;
    }

    // Step 5.4: Copy the remaining terms of P2 (if any)
    while (j < n2) {
        P3[k] = P2[j];
        j++;
        k++;
    }

    n3 = k;  // Number of terms in the result polynomial P3

    // Step 6: Display the result
    printf("Resultant Polynomial (P3): ");
    for (k = 0; k < n3; k++) {
        printf("%dx^%d", P3[k].coefficient, P3[k].exponent);
        if (k < n3 - 1 && P3[k + 1].coefficient >= 0) {
            printf(" + ");
        }
    }
    printf("\n");

    return 0;
}
