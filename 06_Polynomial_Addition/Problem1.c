#include <stdio.h>
#include <stdlib.h>

// Structure to represent a polynomial term
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;  // Pointer to the next term
};

// Function to create a new term
struct Term* createTerm(int coefficient, int exponent) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert a term into a polynomial (linked list)
struct Term* insertTerm(struct Term* poly, int coefficient, int exponent) {
    struct Term* newTerm = createTerm(coefficient, exponent);
    if (poly == NULL) {
        return newTerm;  // If the list is empty, return the new term as the head
    }
    
    // Find the last node
    struct Term* temp = poly;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newTerm;  // Insert the new term at the end
    return poly;
}

// Function to add two polynomials
struct Term* addPolynomials(struct Term* P1, struct Term* P2) {
    struct Term* P3 = NULL;
    struct Term* temp1 = P1;
    struct Term* temp2 = P2;
    
    while (temp1 != NULL && temp2 != NULL) {
        // If the exponent of the first polynomial term is greater
        if (temp1->exponent > temp2->exponent) {
            P3 = insertTerm(P3, temp1->coefficient, temp1->exponent);
            temp1 = temp1->next;
        }
        // If the exponent of the second polynomial term is greater
        else if (temp1->exponent < temp2->exponent) {
            P3 = insertTerm(P3, temp2->coefficient, temp2->exponent);
            temp2 = temp2->next;
        }
        // If both exponents are equal
        else {
            int sumCoeff = temp1->coefficient + temp2->coefficient;
            if (sumCoeff != 0) {  // Only add the term if the sum of coefficients is non-zero
                P3 = insertTerm(P3, sumCoeff, temp1->exponent);
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    
    // Add any remaining terms from P1
    while (temp1 != NULL) {
        P3 = insertTerm(P3, temp1->coefficient, temp1->exponent);
        temp1 = temp1->next;
    }
    
    // Add any remaining terms from P2
    while (temp2 != NULL) {
        P3 = insertTerm(P3, temp2->coefficient, temp2->exponent);
        temp2 = temp2->next;
    }
    
    return P3;
}

// Function to display a polynomial
void displayPolynomial(struct Term* poly) {
    struct Term* temp = poly;
    while (temp != NULL) {
        printf("%dx^%d", temp->coefficient, temp->exponent);
        if (temp->next != NULL && temp->next->coefficient >= 0) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Term *P1 = NULL, *P2 = NULL, *P3 = NULL;
    int n1, n2, coeff, exp;
    
    // Read the number of terms in P1 and P2
    printf("Enter the number of terms in polynomial P1: ");
    scanf("%d", &n1);
    printf("Enter the terms for polynomial P1 (coefficient and exponent):\n");
    for (int i = 0; i < n1; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        P1 = insertTerm(P1, coeff, exp);
    }
    
    printf("Enter the number of terms in polynomial P2: ");
    scanf("%d", &n2);
    printf("Enter the terms for polynomial P2 (coefficient and exponent):\n");
    for (int i = 0; i < n2; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        P2 = insertTerm(P2, coeff, exp);
    }
    
    // Add the polynomials
    P3 = addPolynomials(P1, P2);
    
    // Display the result
    printf("Resultant Polynomial (P3): ");
    displayPolynomial(P3);
    
    return 0;
}
