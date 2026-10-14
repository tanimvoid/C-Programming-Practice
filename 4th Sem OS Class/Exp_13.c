// 13. Write a program to implement Banker's algorithm for deadlock avoidance.
// Platform: Linux + Windows

#include <stdio.h>
int main() {
    int i, j, k, c = 0, f[5] = {}, a[3] = {3, 3, 2}, s[5];
    int al[5][3] = {{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}},
        mx[5][3] = {{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}},
        nd[5][3];

    for (i = 0; i < 5; i++) for (j = 0; j < 3; j++) nd[i][j] = mx[i][j] - al[i][j];

    while (c < 5) {
        for (i = 0; i < 5; i++) {
            if (!f[i]) {
                for (j = 0; j < 3 && nd[i][j] <= a[j]; j++);
                if (j == 3) {
                    for (k = 0; k < 3; k++) a[k] += al[i][k];
                    f[i] = 1; s[c++] = i;
                }
            }
        }
        if (c == 0) break; // No progress → unsafe
    }

    if (c == 5) {
        printf("Safe sequence: ");
        for (i = 0; i < 5; i++) printf("P%d ", s[i]);
    } else printf("Not safe.\n");
}
