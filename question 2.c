#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

typedef struct Node Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to concatenate two doubly linked lists X1 and X2
Node* concatenateLists(Node* X1, Node* X2) {
    if (X1 == NULL) {
        return X2;
    }

    if (X2 == NULL) {
        return X1;
    }

    Node* current = X1;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = X2;
    X2->prev = current;

    return X1;
}

// Function to traverse and print the doubly linked list
void traverseList(Node* head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Create the first doubly linked list (X1)
    Node* X1 = createNode(1);
    X1->next = createNode(2);
    X1->next->prev = X1;
    X1->next->next = createNode(3);
    X1->next->next->prev = X1->next;

    // Create the second doubly linked list (X2)
    Node* X2 = createNode(4);
    X2->next = createNode(5);
    X2->next->prev = X2;
    X2->next->next = createNode(6);
    X2->next->next->prev = X2->next;

    printf("Doubly Linked List X1: ");
    traverseList(X1);
    printf("Doubly Linked List X2: ");
    traverseList(X2);

    // Concatenate X2 to X1
    X1 = concatenateLists(X1, X2);

    printf("Concatenated List X1: ");
    traverseList(X1);

    // Free the memory to avoid memory leaks
    while (X1 != NULL) {
        Node* temp = X1;
        X1 = X1->next;
        free(temp);
    }

    return 0;
}
