/*
    Date: November 06, 2024
    Name: MD. SAMIUR RAHMAN TANIM
    Topic: Program to Implement Queues Using Arrays
*/

// Algorithm:
/*
STEP 1: Define an array for queue and initialize front and rear pointers.
STEP 2: Implement enqueue, dequeue, and display functions.
STEP 3: Use the main function to test queue operations.
STEP 4: End the program.
*/

#include <stdio.h>

#define MAX 5
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int data) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = data;
}

int dequeue() {
    if (front == -1) return -1;
    int data = queue[front++];
    if (front > rear) front = rear = -1;
    return data;
}

void display() {
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}
