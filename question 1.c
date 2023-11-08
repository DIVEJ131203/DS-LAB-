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

Node* deleteRear(Node* head) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return head;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->prev->next = NULL;
    free(current);

    return head;
}

Node* insertPosition(Node* head, int data, int position) {
    Node* newNode = createNode(data);

    if (position <= 0) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    Node* current = head;
    for (int i = 1; i < position && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position. Element not inserted.\n");
        free(newNode);
        return head;
    }

    newNode->prev = current->prev;
    newNode->next = current;
    if (current->prev != NULL) {
        current->prev->next = newNode;
    }
    current->prev = newNode;

    if (position == 1) {
        return newNode;
    } else {
        return head;
    }
}

Node* deletePosition(Node* head, int position) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return head;
    }

    Node* current = head;
    for (int i = 1; i < position && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position. Element not deleted.\n");
        return head;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    if (position == 1) {
        head = current->next;
    }

    free(current);
    return head;
}

Node* insertAfter(Node* head, int target, int data) {
    Node* newNode = createNode(data);

    if (head == NULL) {
        return newNode;
    }

    Node* current = head;
    while (current != NULL) {
        if (current->data == target) {
            newNode->prev = current;
            newNode->next = current->next;
            if (current->next != NULL) {
                current->next->prev = newNode;
            }
            current->next = newNode;
            return head;
        }
        current = current->next;
    }

    printf("Element not found. Insertion failed.\n");
    free(newNode);
    return head;
}

Node* insertBefore(Node* head, int target, int data) {
    Node* newNode = createNode(data);

    if (head == NULL) {
        return newNode;
    }

    if (head->data == target) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    Node* current = head;
    while (current != NULL) {
        if (current->data == target) {
            newNode->prev = current->prev;
            newNode->next = current;
            current->prev->next = newNode;
            current->prev = newNode;
            return head;
        }
        current = current->next;
    }

    printf("Element not found. Insertion failed.\n");
    free(newNode);
    return head;
}

void traverseList(Node* head) {
    Node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

Node* reverseList(Node* head) {
    Node* current = head;
    Node* temp = NULL;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        head = temp->prev;
    }

    return head;
}

Node* concatenateLists(Node* list1, Node* list2) {
    if (list1 == NULL) {
        return list2;
    }

    if (list2 == NULL) {
        return list1;
    }

    Node* current = list1;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = list2;
    list2->prev = current;

    return list1;
}

int main() {
    Node* head = NULL;
    int choice, data, position, target;
    Node* list2 = NULL;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element at the rear end of the list\n");
        printf("2. Delete an element from the rear end of the list\n");
        printf("3. Insert an element at a given position of the list\n");
        printf("4. Delete an element from a given position of the list\n");
        printf("5. Insert an element after another element\n");
        printf("6. Insert an element before another element\n");
        printf("7. Traverse the list\n");
        printf("8. Reverse the list\n");
        printf("9. Concatenate two lists\n");
        printf("10. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert at the rear end: ");
                scanf("%d", &data);
                head = insertRear(head, data);
                break;

            case 2:
                head = deleteRear(head);
                break;

            case 3:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                head = insertPosition(head, data, position);
                break;

            case 4:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                head = deletePosition(head, position);
                break;

            case 5:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the target element: ");
                scanf("%d", &target);
                head = insertAfter(head, target, data);
                break;

            case 6:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the target element: ");
                scanf("%d", &target);
                head = insertBefore(head, target, data);
                break;

            case 7:
                traverseList(head);
                break;

            case 8:
                head = reverseList(head);
                break;

            case 9:
                list2 = createNode(11);
                list2->next = createNode(12);
                list2->next->next = createNode(13);

                printf("List 1: ");
                traverseList(head);
                printf("List 2: ");
                traverseList(list2);

                head = concatenateLists(head, list2);

                printf("Concatenated List: ");
                traverseList(head);

                // Free the memory to avoid memory leaks
                while (list2 != NULL) {
                    Node* temp = list2;
                    list2 = list2->next;
                    free(temp);
                }
                break;

            case 10:
                // Free the memory to avoid memory leaks
                while (head != NULL) {
                    Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
