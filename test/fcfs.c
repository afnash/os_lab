#include<stdio.h>
int main(){
    int p[10], at[10], bt[10], ct[10], tat[10], wt[10], i, j, temp, gantt[100], gantt_index = 0;
    float awt = 0, atat = 0;
    int n;
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    printf("Enter %d process IDs: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    printf("Enter %d arrival times and burst times: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &at[i], &bt[i]);
    }

    // Sort processes by arrival time (AT)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                // Swap process IDs
                temp = p[j + 1];
                p[j + 1] = p[j];
                p[j] = temp;

                // Swap arrival times
                temp = at[j + 1];
                at[j + 1] = at[j];
                at[j] = temp;

                // Swap burst times
                temp = bt[j + 1];
                bt[j + 1] = bt[j];
                bt[j] = temp;
            }
        }
    }

    // Calculate completion times (CT)
    ct[0] = at[0] + bt[0];
    gantt[gantt_index++] = p[0]; // Add first process to Gantt chart
    for (i = 1; i < n; i++) {
        int idle_time = 0;
        if (ct[i - 1] < at[i]) {
            idle_time = at[i] - ct[i - 1]; // CPU is idle
        }
        ct[i] = ct[i - 1] + bt[i] + idle_time;
        gantt[gantt_index++] = p[i]; // Add process to Gantt chart
    }

    // Calculate turnaround times (TAT) and waiting times (WT)
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        atat += tat[i];
        awt += wt[i];
    }

    atat /= n; // Average turnaround time
    awt /= n;  // Average waiting time

    // Print results
    printf("\nPID \t AT \t BT \t CT \t TAT \t WT");
    printf("\n--------------------------------------");
    for (i = 0; i < n; i++) {
        printf("\nP%d \t %d \t %d \t %d \t %d \t %d", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\n\nAverage TAT: %.2f", atat);
    printf("\nAverage WT: %.2f", awt);

    // Print Gantt chart
    printf("\n\nGANTT Chart:\n|");
    for (i = 0; i < gantt_index; i++) {
        printf(" P%d |", gantt[i]);
    }
    printf("\n0");
    for (i = 0; i < gantt_index; i++) {
        printf(" %d", ct[i]); // Print completion times in Gantt chart
    }
    printf("\n");

    return 0;
}