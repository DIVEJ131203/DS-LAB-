#include <stdio.h>
#include <stdlib.h>

// Define a structure for a term in a polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
    struct Term* prev;
};

typedef struct Term Term;

// Define a structure for the header node
struct Header {
    Term* term;
};

typedef struct Header Header;

Header* createHeader() {
    Header* newHeader = (Header*)malloc(sizeof(Header));
    newHeader->term = NULL;
    return newHeader;
}

Term* createTerm(int coefficient, int exponent) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    newTerm->prev = NULL;
    return newTerm;
}

// Function to insert a term into a polynomial linked list
void insertTerm(Header* header, int coefficient, int exponent) {
    Term* newTerm = createTerm(coefficient, exponent);

    if (header->term == NULL) {
        header->term = newTerm;
        newTerm->next = newTerm;
        newTerm->prev = newTerm;
    } else {
        Term* current = header->term;
        while (current->next != header->term) {
            current = current->next;
        }
        current->next = newTerm;
        newTerm->prev = current;
        newTerm->next = header->term;
        header->term->prev = newTerm;
    }
}

// Function to display a polynomial
void displayPolynomial(Header* header) {
    if (header->term == NULL) {
        printf("0\n");
        return;
    }

    Term* current = header->term;
    do {
        printf("%dx^%d ", current->coefficient, current->exponent);
        if (current->next != header->term) {
            printf("+ ");
        }
        current = current->next;
    } while (current != header->term);
    printf("\n");
}

// Function to add two polynomials
Header* addPolynomials(Header* poly1, Header* poly2) {
    Header* result = createHeader();

    Term* term1 = poly1->term;
    do {
        insertTerm(result, term1->coefficient, term1->exponent);
        term1 = term1->next;
    } while (term1 != poly1->term);

    Term* term2 = poly2->term;
    do {
        insertTerm(result, term2->coefficient, term2->exponent);
        term2 = term2->next;
    } while (term2 != poly2->term);

    return result;
}

int main() {
    Header* poly1 = createHeader();
    Header* poly2 = createHeader();

    int coefficient, exponent;
    int n, m;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n);

    printf("Enter the terms for the first polynomial (coefficient exponent):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(poly1, coefficient, exponent);
    }

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &m);

    printf("Enter the terms for the second polynomial (coefficient exponent):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(poly2, coefficient, exponent);
    }

    printf("First Polynomial: ");
    displayPolynomial(poly1);

    printf("Second Polynomial: ");
    displayPolynomial(poly2);

    Header* result = addPolynomials(poly1, poly2);

    printf("Resultant Polynomial (Sum of the two polynomials): ");
    displayPolynomial(result);

    // Free the memory to avoid memory leaks
    Term* term1 = poly1->term;
    do {
        Term* temp = term1;
        term1 = term1->next;
        free(temp);
    } while (term1 != poly1->term);

    Term* term2 = poly2->term;
    do {
        Term* temp = term2;
        term2 = term2->next;
        free(temp);
    } while (term2 != poly2->term);

    Term* termResult = result->term;
    do {
        Term* temp = termResult;
        termResult = termResult->next;
        free(temp);
    } while (termResult != result->term);

    free(poly1);
    free(poly2);
    free(result);

    return 0;
}

