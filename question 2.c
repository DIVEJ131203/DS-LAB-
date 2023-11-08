#include <stdio.h>
#include <stdlib.h>

// Define a structure for a term in a polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

typedef struct Term Term;

Term* createTerm(int coefficient, int exponent) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert a term into a polynomial linked list
Term* insertTerm(Term* head, int coefficient, int exponent) {
    Term* newTerm = createTerm(coefficient, exponent);

    if (head == NULL) {
        return newTerm;
    }

    if (exponent > head->exponent) {
        newTerm->next = head;
        return newTerm;
    }

    if (exponent == head->exponent) {
        head->coefficient += coefficient;
        free(newTerm);
        return head;
    }

    Term* current = head;
    while (current->next != NULL && exponent < current->next->exponent) {
        current = current->next;
    }

    if (current->next != NULL && exponent == current->next->exponent) {
        current->next->coefficient += coefficient;
        free(newTerm);
    } else {
        newTerm->next = current->next;
        current->next = newTerm;
    }

    return head;
}

// Function to display a polynomial
void displayPolynomial(Term* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    while (head != NULL) {
        if (head->coefficient != 0) {
            printf("%dx^%d ", head->coefficient, head->exponent);
            if (head->next != NULL) {
                printf("+ ");
            }
        }
        head = head->next;
    }
    printf("\n");
}

// Function to add two polynomials
Term* addPolynomials(Term* poly1, Term* poly2) {
    Term* result = NULL;

    while (poly1 != NULL) {
        result = insertTerm(result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        result = insertTerm(result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }

    return result;
}

int main() {
    Term* poly1 = NULL;
    Term* poly2 = NULL;

    int coefficient, exponent;
    int n, m;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n);

    printf("Enter the terms for the first polynomial (coefficient exponent):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coefficient, &exponent);
        poly1 = insertTerm(poly1, coefficient, exponent);
    }

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &m);

    printf("Enter the terms for the second polynomial (coefficient exponent):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &coefficient, &exponent);
        poly2 = insertTerm(poly2, coefficient, exponent);
    }

    printf("First Polynomial: ");
    displayPolynomial(poly1);

    printf("Second Polynomial: ");
    displayPolynomial(poly2);

    Term* result = addPolynomials(poly1, poly2);

    printf("Resultant Polynomial (Sum of the two polynomials): ");
    displayPolynomial(result);

    // Free the memory to avoid memory leaks
    while (poly1 != NULL) {
        Term* temp = poly1;
        poly1 = poly1->next;
        free(temp);
    }

    while (poly2 != NULL) {
        Term* temp = poly2;
        poly2 = poly2->next;
        free(temp);
    }

    while (result != NULL) {
        Term* temp = result;
        result = result->next;
        free(temp);
    }

    return 0;
}
