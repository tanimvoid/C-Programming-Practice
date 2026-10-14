/*
    Date: November 06, 2024
    Name: MD. SAMIUR RAHMAN TANIM
    Topic: Program to Implement Stacks Using Arrays
*/

// Algorithm:
/*
STEP 1: Define an array and a top index for the stack.
STEP 2: Implement push, pop, and display functions.
STEP 3: Use the main function to test stack operations.
STEP 4: End the program.
*/

#include <stdio.h>

#define MAX 5
int stack[MAX];
int top = -1;

void push(int data) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = data;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

void display() {
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
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
