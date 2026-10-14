// 9. Write a C program for simulating the Round robin CPU scheduling algorithm
// Platform: Linux + Windows

#include <stdio.h>

int main() {
    int n, ts, i, time = 0;
    int burst[10], need[10], start[10] = {0}, wait[10], turn[10], finish[10];
    float totalwait = 0, totalturn = 0, totalresp = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &burst[i]);
        need[i] = burst[i];
    }

    printf("Enter time slice: ");
    scanf("%d", &ts);

    while (1) {
        int done = 1;
        for (i = 0; i < n; i++) {
            if (need[i] > 0) {
                if (need[i] == burst[i]) start[i] = time; // First time the process gets CPU

                int exec = (need[i] > ts) ? ts : need[i];
                time += exec;
                need[i] -= exec;

                if (need[i] == 0) {
                    finish[i] = time;
                    wait[i] = finish[i] - burst[i];
                    turn[i] = finish[i];
                    totalwait += wait[i];
                    totalturn += turn[i];
                    totalresp += start[i];
                }
                done = 0;
            }
        }
        if (done) break;
    }

    printf("\nProcess  Burst  Start  Finish  Wait  Turnaround\n");
    for (i = 0; i < n; i++)
        printf("  P%d%9d%7d%8d%6d%10d\n", i + 1, burst[i], start[i], finish[i], wait[i], turn[i]);

    printf("\nAverage Waiting Time   : %.2f", totalwait / n);
    printf("\nAverage Turnaround Time: %.2f", totalturn / n);
    printf("\nAverage Response Time  : %.2f\n", totalresp / n);

    return 0;
}
