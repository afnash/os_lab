#include<stdio.h>

int main() {
    int p[10], at[10], bt[10], ct[10], tat[10], wt[10], rt[10], completed_flag[10], i, j, n, temp;
    int tq, curr = 0, comp = 0, gantt[100], gantt_index = 0;
    float atat = 0, awt = 0;

    printf("Enter no. of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Pid, AT and BT of process %d: ", i + 1);
        scanf("%d %d %d", &p[i], &at[i], &bt[i]);
        completed_flag[i] = 0;
        rt[i] = bt[i]; // Remaining time is initially the burst time
    }

    printf("\nEnter time quantum: ");
    scanf("%d", &tq);

    // Sort processes by arrival time (AT)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                // Swap AT
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                // Swap BT
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap PIDs
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Initialize current time to the arrival time of the first process
    if (at[0] > curr) {
        curr = at[0];
    }

    printf("Current time: %d\n", curr);

    // Round Robin Scheduling
    while (comp < n) {
        int executed = 0;

        for (i = 0; i < n; i++) {
            if (at[i] <= curr && !completed_flag[i]) {
                if (rt[i] > tq) {
                    curr += tq;
                    rt[i] -= tq;
                } else {
                    curr += rt[i];
                    rt[i] = 0;
                    ct[i] = curr; // Completion time
                    tat[i] = ct[i] - at[i]; // Turnaround time
                    wt[i] = tat[i] - bt[i]; // Waiting time
                    atat += tat[i];
                    awt += wt[i];
                    completed_flag[i] = 1;
                    comp++;
                }
                gantt[gantt_index++] = p[i]; // Add process to Gantt chart
                executed = 1;
            }
        }

        if (!executed) {
            curr++; // Increment time if no process is executed
        }
    }

    // Calculate averages
    atat /= n;
    awt /= n;

    // Print results
    printf("\nPid \t AT \t BT \t CT \t TAT \t WT");
    for (i = 0; i < n; i++) {
        printf("\n%d \t %d \t %d \t %d \t %d \t %d", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
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
        printf(" %d", ct[gantt[i] - 1]); // Print completion times in Gantt chart
    }
    printf("\n");

    return 0;
}