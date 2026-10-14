#include <stdio.h>
#define MAX 100
int stack[MAX], top = -1;
void push(int value) {
    if (top < MAX - 1) stack[++top] = value;
}
int pop() {
    return (top >= 0) ? stack[top--] : -1;
}
void display() {
    for (int i = top; i >= 0; i--) printf("%d ", stack[i]);
    printf("\n");
}
int main() {
    push(10);
    push(20);
    display();
    pop();
    display();
    return 0;
}
