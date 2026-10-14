// 14. Write a program to implement first fit, best fit and worst fit algorithm for memory management.
// Platform: Linux + Windows

#include <stdio.h>
int b[] = {100, 500, 200, 300, 600}, p[] = {212, 417, 112, 426, 100};

void fit(int mode) {
    int i, j, k, a[5] = {-1,-1,-1,-1,-1}, blk[5];
    for (i = 0; i < 5; i++) blk[i] = b[i];
    for (i = 0; i < 5; i++) {
        int idx = -1;
        for (j = 0; j < 5; j++)
            if (blk[j] >= p[i] && 
               (idx == -1 || (mode == 1 && blk[j] < blk[idx]) || 
                             (mode == 2 && blk[j] > blk[idx]) || 
                             (mode == 0)))
                idx = j;
        if (idx != -1) blk[idx] -= p[i], a[i] = idx + 1;
    }
    char *n[] = {"First", "Best", "Worst"};
    printf("\n%s Fit:\n", n[mode]);
    for (i = 0; i < 5; i++)
        printf("P%d (%d) -> %s\n", i+1, p[i], a[i] == -1 ? "Not Allocated" : "Block");
    for (i = 0; i < 5; i++)
        if (a[i] != -1) printf("P%d in Block %d\n", i+1, a[i]);
}

int main() {
    fit(0); fit(1); fit(2);
}
