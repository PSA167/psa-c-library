
#ifndef DDSA_PSA_H
#define DDSA_PSA_H

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Stack structure
typedef struct {
    Node* top;
    int size;
    int limit;
} Stack;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a stack
Stack* initStack(int limit) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    stack->top = NULL;
    stack->size = 0;
    stack->limit = limit;
    return stack;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    if (stack->size >= stack->limit) {
        printf("Stack overflow!\n");
        return;
    }
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack underflow!\n");
        exit(1);
    }
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return data;
}

// Function to peek at the top element of the stack
int peek(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        exit(1);
    }
    return stack->top->data;
}

void initialize() {
    Stack* stack = initStack(10);

    // Pushing elements onto the stack
    push(stack, 5);
    push(stack, 10);
    push(stack, 15);
    push(stack, 20);

    // Peeking at the top element
    printf("Top element of stack: %d\n", peek(stack));

    // Popping elements from the stack
    printf("Popped element: %d\n", pop(stack));
    printf("Popped element: %d\n", pop(stack));

    // Peeking at the top element again
    printf("Top element of stack after popping: %d\n", peek(stack));

    // Freeing memory
    free(stack);
}

#endif //DDSA_PSA_H
