/*
    Date: November 06, 2024
    Name: MD. SAMIUR RAHMAN TANIM
    Topic: Program to Implement Stacks Using Linked Lists
*/

// Algorithm:
/*
STEP 1: Define a Node structure for stack elements.
STEP 2: Implement push, pop, and display functions.
STEP 3: Use the main function to test stack operations.
STEP 4: End the program.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

void push(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) return -1;
    int data = top->data;
    Node* temp = top;
    top = top->next;
    free(temp);
    return data;
}

void display() {
    Node* temp = top;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    return 0;
}
