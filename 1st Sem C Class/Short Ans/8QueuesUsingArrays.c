#include <stdio.h>
#define MAX 100
int queue[MAX], front = -1, rear = -1;
void enqueue(int value) {
    if (rear < MAX - 1) queue[++rear] = value;
    if (front == -1) front = 0;
}
int dequeue() {
    return (front <= rear) ? queue[front++] : -1;
}
void display() {
    for (int i = front; i <= rear; i++) printf("%d ", queue[i]);
    printf("\n");
}
int main() {
    enqueue(10);
    enqueue(20);
    display();
    dequeue();
    display();
    return 0;
}
