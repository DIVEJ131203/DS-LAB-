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
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

Node* insertFront(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }

    newNode->next = head;
    newNode->prev = head->prev;
    head->prev->next = newNode;
    head->prev = newNode;
    return newNode;
}

Node* deleteNode(Node* head, int key) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return head;
    }

    Node* current = head;
    Node* toDelete = NULL;

    do {
        if (current->data == key) {
            toDelete = current;
            break;
        }
        current = current->next;
    } while (current != head);

    if (toDelete == NULL) {
        printf("Element not found. Deletion failed.\n");
        return head;
    }

    if (toDelete->next == toDelete) {
        // Single node in the list
        free(toDelete);
        return NULL;
    }

    toDelete->prev->next = toDelete->next;
    toDelete->next->prev = toDelete->prev;

    if (toDelete == head) {
        head = toDelete->next;
    }

    free(toDelete);
    return head;
}

void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* current = head;
    do {
        printf("%d <-> ", current->data);
        current = current->next;
    } while (current != head);
    printf("...\n");
}

int main() {
    Node* head = NULL;
    int choice, data, key;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element at the front\n");
        printf("2. Delete an element\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert at the front: ");
                scanf("%d", &data);
                head = insertFront(head, data);
                break;

            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &key);
                head = deleteNode(head, key);
                break;

            case 3:
                printf("Doubly Linked Circular List: ");
                displayList(head);
                break;

            case 4:
                // Free the memory to avoid memory leaks
                while (head != NULL) {
                    Node* temp = head;
                    head = head->next;
                    if (temp->next == temp) {
                        free(temp);
                        break;
                    }
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
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
