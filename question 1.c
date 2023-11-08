#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to perform in-order traversal (Iterative)
void inOrderIterative(Node* root) {
    if (root == NULL) return;

    Node* current = root;
    Node* stack[100]; // Array to simulate a stack
    int top = -1;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

// Function to perform post-order traversal (Iterative)
void postOrderIterative(Node* root) {
    if (root == NULL) return;

    Node* current = root;
    Node* stack[100]; // Array to simulate a stack
    int top = -1;
    Node* lastVisited = NULL;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top];

        if (current->right == NULL || current->right == lastVisited) {
            printf("%d ", current->data);
            lastVisited = current;
            top--;
            current = NULL;
        } else {
            current = current->right;
        }
    }
}

// Function to perform pre-order traversal (Iterative)
void preOrderIterative(Node* root) {
    if (root == NULL) return;

    Node* stack[100]; // Array to simulate a stack
    int top = -1;

    stack[++top] = root;
    while (top != -1) {
        Node* current = stack[top--];
        printf("%d ", current->data);

        if (current->right != NULL) {
            stack[++top] = current->right;
        }
        if (current->left != NULL) {
            stack[++top] = current->left;
        }
    }
}

// Function to print the parent of the given element
bool printParent(Node* root, int element) {
    if (root == NULL) return false;

    Node* parent = NULL;
    Node* current = root;

    while (current != NULL) {
        if (current->data == element) {
            if (parent != NULL) {
                printf("Parent of %d is %d\n", element, parent->data);
            } else {
                printf("%d is the root node, it has no parent.\n", element);
            }
            return true;
        }

        parent = current;

        if (element < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    printf("Element %d not found in the tree.\n", element);
    return false;
}

// Function to print the depth of the tree
int getDepth(Node* root) {
    if (root == NULL) return 0;

    int leftDepth = getDepth(root->left);
    int rightDepth = getDepth(root->right);

    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

// Function to print the ancestors of a given element
bool printAncestors(Node* root, int element) {
    if (root == NULL) return false;

    if (root->data == element) {
        return true;
    }

    if (printAncestors(root->left, element) || printAncestors(root->right, element)) {
        printf("%d ", root->data);
        return true;
    }

    return false;
}

// Function to count the number of leaf nodes in a binary tree
int countLeafNodes(Node* root) {
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    Node* root = NULL;
    int choice;
    int data;
    int element;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. In-order Traversal (Iterative)\n");
        printf("3. Post-order Traversal (Iterative)\n");
        printf("4. Pre-order Traversal (Iterative)\n");
        printf("5. Print Parent of Element\n");
        printf("6. Print Depth of Tree\n");
        printf("7. Print Ancestors of Element\n");
        printf("8. Count Leaf Nodes\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data for the new node: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;

            case 2:
                printf("In-order Traversal: ");
                inOrderIterative(root);
                printf("\n");
                break;

            case 3:
                printf("Post-order Traversal: ");
                postOrderIterative(root);
                printf("\n");
                break;

            case 4:
                printf("Pre-order Traversal: ");
                preOrderIterative(root);
                printf("\n");
                break;

            case 5:
                printf("Enter the element to find its parent: ");
                scanf("%d", &element);
                printParent(root, element);
                break;

            case 6:
                printf("Depth of the tree: %d\n", getDepth(root));
                break;

            case 7:
                printf("Enter the element to find its ancestors: ");
                scanf("%d", &element);
                printf("Ancestors of %d: ", element);
                if (!printAncestors(root, element)) {
                    printf("Element not found in the tree.\n");
                }
                printf("\n");
                break;

            case 8:
                printf("Number of Leaf Nodes: %d\n", countLeafNodes(root));
                break;

            case 9:
                // Free the allocated memory
                // You may want to implement a separate function to free the tree nodes properly
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

