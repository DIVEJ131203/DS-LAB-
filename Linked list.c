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

Node* insertBefore(Node* head, int existingElement, int newElement) {
    Node* newNode = createNode(newElement);
    if (head == NULL) {
        return newNode;
    }

    if (head->data == existingElement) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    while (current->next != NULL && current->next->data != existingElement) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("%d not found in the list.\n", existingElement);
    } else {
        newNode->next = current->next;
        current->next = newNode;
    }

    return head;
}

Node* insertAfter(Node* head, int existingElement, int newElement) {
    Node* newNode = createNode(newElement);
    if (head == NULL) {
        return newNode;
    }

    Node* current = head;
    while (current != NULL && current->data != existingElement) {
        current = current->next;
    }

    if (current == NULL) {
        printf("%d not found in the list.\n", existingElement);
    } else {
        newNode->next = current->next;
        current->next = newNode;
    }

    return head;
}

Node* deleteElement(Node* head, int element) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    if (head->data == element) {
        Node* temp = head;
        head = head->next;
        free(temp);
    } else {
        Node* current = head;
        while (current->next != NULL && current->next->data != element) {
            current = current->next;
        }

        if (current->next == NULL) {
            printf("%d not found in the list.\n", element);
        } else {
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
    }

    return head;
}

void traverseList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    while (current != NULL) {
        Node* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

Node* sortList(Node* head) {
    if (head == NULL) {
        return head;
    }

    int swapped;
    Node* ptr1;
    Node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    return head;
}

Node* deleteAlternateNodes(Node* head) {
    if (head == NULL) {
        return head;
    }

    Node* current = head;
    while (current != NULL && current->next != NULL) {
        Node* temp = current->next;
        current->next = temp->next;
        free(temp);
        current = current->next;
    }

    return head;
}

Node* insertInSortedList(Node* head, int element) {
    Node* newNode = createNode(element);
    if (head == NULL || head->data >= element) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    while (current->next != NULL && current->next->data < element) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}

int main() {
    Node* head = NULL;
    int choice, existingElement, newElement, element;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert before an element\n");
        printf("2. Insert after an element\n");
        printf("3. Delete an element\n");
        printf("4. Traverse the list\n");
        printf("5. Reverse the list\n");
        printf("6. Sort the list\n");
        printf("7. Delete every alternate node\n");
        printf("8. Insert in sorted list\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the existing element: ");
                scanf("%d", &existingElement);
                printf("Enter the new element: ");
                scanf("%d", &newElement);
                head = insertBefore(head, existingElement, newElement);
                break;

            case 2:
                printf("Enter the existing element: ");
                scanf("%d", &existingElement);
                printf("Enter the new element: ");
                scanf("%d", &newElement);
                head = insertAfter(head, existingElement, newElement);
                break;

            case 3:
                printf("Enter the element to delete: ");
                scanf("%d", &element);
                head = deleteElement(head, element);
                break;

            case 4:
                traverseList(head);
                break;

            case 5:
                head = reverseList(head);
                break;

            case 6:
                head = sortList(head);
                break;

            case 7:
                head = deleteAlternateNodes(head);
                break;

            case 8:
                printf("Enter the element to insert in the sorted list: ");
                scanf("%d", &element);
                head = insertInSortedList(head, element);
                break;

            case 9:
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
