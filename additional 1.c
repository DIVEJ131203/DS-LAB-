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

Node* insertRear(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;

    return head;
}

void traverseList(Node* head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to compute the union of two doubly linked lists
Node* unionLists(Node* list1, Node* list2) {
    Node* result = NULL;
    Node* current1 = list1;
    Node* current2 = list2;

    while (current1 != NULL) {
        result = insertRear(result, current1->data);
        current1 = current1->next;
    }

    while (current2 != NULL) {
        int data = current2->data;
        Node* temp = result;
        int found = 0;

        while (temp != NULL) {
            if (temp->data == data) {
                found = 1;
                break;
            }
            temp = temp->next;
        }

        if (!found) {
            result = insertRear(result, data);
        }

        current2 = current2->next;
    }

    return result;
}

// Function to compute the intersection of two doubly linked lists
Node* intersectionLists(Node* list1, Node* list2) {
    Node* result = NULL;
    Node* current1 = list1;

    while (current1 != NULL) {
        int data = current1->data;
        Node* current2 = list2;
        int found = 0;

        while (current2 != NULL) {
            if (current2->data == data) {
                found = 1;
                break;
            }
            current2 = current2->next;
        }

        if (found) {
            result = insertRear(result, data);
        }

        current1 = current1->next;
    }

    return result;
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;
    int n, m, data;

    printf("Enter the number of elements for List 1: ");
    scanf("%d", &n);
    printf("Enter the elements for List 1:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        list1 = insertRear(list1, data);
    }

    printf("Enter the number of elements for List 2: ");
    scanf("%d", &m);
    printf("Enter the elements for List 2:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &data);
        list2 = insertRear(list2, data);
    }

    printf("Doubly Linked List 1: ");
    traverseList(list1);
    printf("Doubly Linked List 2: ");
    traverseList(list2);

    // Compute the union of list1 and list2
    Node* unionResult = unionLists(list1, list2);

    printf("Union of List 1 and List 2: ");
    traverseList(unionResult);

    // Compute the intersection of list1 and list2
    Node* intersectionResult = intersectionLists(list1, list2);

    printf("Intersection of List 1 and List 2: ");
    traverseList(intersectionResult);

    // Free the memory to avoid memory leaks
    while (list1 != NULL) {
        Node* temp = list1;
        list1 = list1->next;
        free(temp);
    }

    while (list2 != NULL) {
        Node* temp = list2;
        list2 = list2->next;
        free(temp);
    }

    while (unionResult != NULL) {
        Node* temp = unionResult;
        unionResult = unionResult->next;
        free(temp);
    }

    while (intersectionResult != NULL) {
        Node* temp = intersectionResult;
        intersectionResult = intersectionResult->next;
        free(temp);
    }

    return 0;
}
