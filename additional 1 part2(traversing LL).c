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

Node* insertAtEnd(Node* head, int data) {
    if (head == NULL) {
        return createNode(data);
    }

    head->next = insertAtEnd(head->next, data);
    return head;
}

void traverseList(Node* current) {
    if (current == NULL) {
        return;
    }

    printf("%d -> ", current->data);
    traverseList(current->next);
}

int main() {
    Node* head = NULL;
    int n, data;

    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        head = insertAtEnd(head, data);
    }

    printf("Linked list: ");
    traverseList(head);
    printf("NULL\n");

    return 0;
}
