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

Node* mergeLists(Node* list1, Node* list2) {
    Node dummy; // Create a dummy node to simplify edge cases
    Node* tail = &dummy;
    int m = 0, n = 0;

    // Calculate the lengths of list1 and list2
    Node* temp = list1;
    while (temp != NULL) {
        m++;
        temp = temp->next;
    }

    temp = list2;
    while (temp != NULL) {
        n++;
        temp = temp->next;
    }

    int smaller = (m <= n) ? m : n;

    for (int i = 0; i < smaller; i++) {
        tail->next = list1;
        list1 = list1->next;
        tail = tail->next;

        tail->next = list2;
        list2 = list2->next;
        tail = tail->next;
    }

    // Append any remaining nodes from the longer list
    if (m <= n) {
        tail->next = list2;
    } else {
        tail->next = list1;
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
    Node* list1 = createNode(1);
    list1->next = createNode(3);
    list1->next->next = createNode(5);

    Node* list2 = createNode(2);
    list2->next = createNode(4);

    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    Node* list3 = mergeLists(list1, list2);

    printf("Merged List 3: ");
    printList(list3);

    // Free the memory to avoid memory leaks
    while (list3 != NULL) {
        Node* temp = list3;
        list3 = list3->next;
        free(temp);
    }

    return 0;
}
