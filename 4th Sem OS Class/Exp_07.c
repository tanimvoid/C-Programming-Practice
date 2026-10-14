// 7. write a C program for simulating FCFS CPU Scheduling Algorithm
// Platform: Linux + Windows

#include <stdio.h>

int main() {
    int arrival[10], burst[10], start[10], finish[10], wait[10], turn[10];
    int i, n;
    float totalwait = 0.0, totalturn = 0.0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter process %d Arrival and Burst time: ", i + 1);
        scanf("%d %d", &arrival[i], &burst[i]);
    }

    for (i = 0; i < n; i++) {
        if (i == 0) {
            start[i] = arrival[i];
        } else {
            if (arrival[i] > finish[i - 1]) {
                // CPU idle, start at arrival time
                start[i] = arrival[i];
            } else {
                start[i] = finish[i - 1];
            }
        }
        finish[i] = start[i] + burst[i];
        wait[i] = start[i] - arrival[i];
        turn[i] = finish[i] - arrival[i];

        totalwait += wait[i];
        totalturn += turn[i];
    }

    float avgwait = totalwait / n;
    float avgturn = totalturn / n;

    printf("\nProcess  Arrival  Burst  Start  Finish  Wait  Turnaround\n");
    for (i = 0; i < n; i++) {
        printf("%6d %8d %6d %6d %7d %6d %11d\n", 
            i + 1, arrival[i], burst[i], start[i], finish[i], wait[i], turn[i]);
    }

    printf("\nAverage Waiting Time: %.2f", avgwait);
    printf("\nAverage Turnaround Time: %.2f\n", avgturn);

    return 0;
}
