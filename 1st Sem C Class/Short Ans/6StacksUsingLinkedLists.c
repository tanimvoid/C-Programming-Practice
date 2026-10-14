#include <stdio.h>
#include <stdlib.h>
struct Node { int d; struct Node* n; };
struct Node* push(struct Node* t, int v) {
    struct Node* p = malloc(sizeof(struct Node)); p->d = v; p->n = t;
    return p;
}
struct Node* pop(struct Node* t) { return t ? t->n : NULL; }
void display(struct Node* t) { while (t) { printf("%d ", t->d); t = t->n; } }
int main() { struct Node* s = NULL; s = push(s, 10); display(s); }
