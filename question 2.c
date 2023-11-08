#include <stdio.h>
#include <stdlib.h>

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

// Function to create a binary tree recursively
Node* createBinaryTree() {
    int data;
    printf("Enter data (or -1 to indicate NULL): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL; // Indicates a NULL node
    }

    Node* root = createNode(data);

    printf("Enter left subtree of %d:\n", data);
    root->left = createBinaryTree();

    printf("Enter right subtree of %d:\n", data);
    root->right = createBinaryTree();

    return root;
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

int main() {
    Node* root = createBinaryTree();

    printf("Binary Tree (In-order traversal): ");
    printBinaryTree(root);
    printf("\n");

    return 0;
}
