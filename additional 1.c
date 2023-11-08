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

// Function to check if two binary trees are equal
bool areTreesEqual(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true; // Both trees are empty and therefore equal
    }

    if (root1 == NULL || root2 == NULL) {
        return false; // One tree is empty, and the other is not
    }

    if (root1->data != root2->data) {
        return false; // Nodes have different values
    }

    // Recursively check the left and right subtrees
    return areTreesEqual(root1->left, root2->left) && areTreesEqual(root1->right, root2->right);
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
    printf("Enter the first binary tree:\n");
    Node* root1 = buildBinaryTree();

    printf("Enter the second binary tree:\n");
    Node* root2 = buildBinaryTree();

    // Check if the two trees are equal
    if (areTreesEqual(root1, root2)) {
        printf("The two trees are equal.\n");
    } else {
        printf("The two trees are not equal.\n");
    }

    // Free the allocated memory
    // You may want to implement a separate function to free the tree nodes properly
    free(root1);
    free(root2);

    return 0;
}
