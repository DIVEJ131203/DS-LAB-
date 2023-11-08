#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* mergeSortedLists(Node* X, Node* Y) {
    Node dummy; // Create a dummy node to simplify edge cases
    Node* tail = &dummy;

    while (X != NULL && Y != NULL) {
        if (X->data <= Y->data) {
            tail->next = X;
            X = X->next;
        } else {
            tail->next = Y;
            Y = Y->next;
        }
        tail = tail->next;
    }

    // Append any remaining nodes from X or Y
    if (X != NULL) {
        tail->next = X;
    } else {
        tail->next = Y;
    }

    return dummy.next; // The merged list starts from the next node of the dummy
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* X = createNode(1);
    X->next = createNode(9);
    X->next->next = createNode(17);

    Node* Y = createNode(2);
    Y->next = createNode(10);
    Y->next->next = createNode(14);

    printf("List X: ");
    printList(X);
    printf("List Y: ");
    printList(Y);

    Node* Z = mergeSortedLists(X, Y);

    printf("Merged List Z: ");
    printList(Z);

    // Free the memory to avoid memory leaks
    while (Z != NULL) {
        Node* temp = Z;
        Z = Z->next;
        free(temp);
    }

    return 0;
}
