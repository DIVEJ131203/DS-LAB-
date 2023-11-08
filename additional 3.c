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

// Function to create a new binary tree node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to copy a binary tree
Node* copyTree(Node* source) {
    if (source == NULL) {
        return NULL; // Return NULL for an empty tree
    }

    // Create a new node with the same data
    Node* copy = createNode(source->data);

    // Recursively copy the left and right subtrees
    copy->left = copyTree(source->left);
    copy->right = copyTree(source->right);

    return copy;
}

// Function to print a binary tree using in-order traversal
void printBinaryTree(Node* root) {
    if (root == NULL) {
        return;
    }

    printBinaryTree(root->left);
    printf("%d ", root->data);
    printBinaryTree(root->right);
}

// Function to build a binary tree from user input
Node* buildBinaryTree() {
    int data;
    printf("Enter data (or -1 to indicate NULL): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL; // Indicates a NULL node
    }

    Node* root = createNode(data);

    printf("Enter left subtree of %d:\n", data);
    root->left = buildBinaryTree();

    printf("Enter right subtree of %d:\n", data);
    root->right = buildBinaryTree();

    return root;
}

int main() {
    printf("Enter the source binary tree:\n");
    Node* sourceTree = buildBinaryTree();

    // Copy the source tree to a new tree
    Node* copiedTree = copyTree(sourceTree);

    printf("Source Binary Tree (In-order traversal): ");
    printBinaryTree(sourceTree);
    printf("\n");

    printf("Copied Binary Tree (In-order traversal): ");
    printBinaryTree(copiedTree);
    printf("\n");

    // Free the allocated memory
    // You may want to implement a separate function to free the tree nodes properly
    free(sourceTree);
    free(copiedTree);

    return 0;
}
