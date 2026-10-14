// 10. Write a C program for simulating the Priority CPU scheduling algorithm
// Platform: Linux + Windows

#include <stdio.h>

int main() {
    int n, i, j, burst[10], pri[10], start[10], wait[10], finish[10], temp;
    float totalwait = 0, totalturn = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Burst time and priority of P%d: ", i + 1);
        scanf("%d %d", &burst[i], &pri[i]);
    }

    // Sort by priority (higher number = higher priority)
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (pri[i] < pri[j]) {
                temp = pri[i]; pri[i] = pri[j]; pri[j] = temp;
                temp = burst[i]; burst[i] = burst[j]; burst[j] = temp;
            }

    start[0] = wait[0] = 0;
    finish[0] = burst[0];
    for (i = 1; i < n; i++) {
        start[i] = finish[i - 1];
        wait[i] = start[i];
        finish[i] = start[i] + burst[i];
    }

    printf("\nP  Burst  Priority  Start  Wait  Finish\n");
    for (i = 0; i < n; i++) {
        printf("P%d%7d%9d%7d%6d%8d\n", i + 1, burst[i], pri[i], start[i], wait[i], finish[i]);
        totalwait += wait[i];
        totalturn += finish[i];
    }

    printf("\nAverage Waiting Time   = %.2f", totalwait / n);
    printf("\nAverage Turnaround Time= %.2f\n", totalturn / n);

    return 0;
}
