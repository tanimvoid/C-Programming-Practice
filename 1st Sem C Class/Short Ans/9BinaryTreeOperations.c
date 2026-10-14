#include <stdio.h>
#include <stdlib.h>
struct Node { int d; struct Node *l, *r; };
struct Node* ins(struct Node* r, int v) {
    if (!r) { r = malloc(sizeof(struct Node)); r->d = v; r->l = r->r = NULL; }
    else if (v < r->d) r->l = ins(r->l, v);
    else r->r = ins(r->r, v);
    return r;
}
void in(struct Node* r) { if (r) { in(r->l); printf("%d ", r->d); in(r->r); } }
int main() { struct Node* r = NULL; r = ins(r, 10); in(r); }
