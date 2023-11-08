#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Stack Implementation using Linked List
struct Stack {
    Node* top;
};

typedef struct Stack Stack;

// Function to initialize a stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Queue Implementation using Linked List
struct Queue {
    Node* front;
    Node* rear;
};

typedef struct Queue Queue;

// Function to initialize a queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to enqueue an element into the queue
void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Function to dequeue an element from the queue
int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    int data = queue->front->data;
    Node* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

int main() {
    Stack* stack = createStack();
    Queue* queue = createQueue();

    // Push elements onto the stack
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    // Pop elements from the stack
    printf("Stack elements: ");
    while (stack->top != NULL) {
        printf("%d ", pop(stack));
    }
    printf("\n");

    // Enqueue elements into the queue
    enqueue(queue, 50);
    enqueue(queue, 60);
    enqueue(queue, 70);

    // Dequeue elements from the queue
    printf("Queue elements: ");
    while (queue->front != NULL) {
        printf("%d ", dequeue(queue));
    }
    printf("\n");

    // Free the memory to avoid memory leaks
    free(stack);
    free(queue);

    return 0;
}
