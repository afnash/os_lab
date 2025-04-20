#include <stdio.h>
#include <limits.h> // For INT_MAX

int main() {
    int n, i, current_time = 0, completed = 0;
    float tot_tat = 0, tot_wt = 0, avgtat, avgwt;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n], pid[n], completed_flag[n], remaining_time[n];
    int gantt[100], gantt_index = 0; // Gantt chart array

    // Input process details
    for (i = 0; i < n; i++) {
        printf("Enter pid, arrival time, and burst time: ");
        scanf("%d %d %d", &pid[i], &at[i], &bt[i]);
        completed_flag[i] = 0;
        remaining_time[i] = bt[i];
    }

    // SRJF Scheduling
    while (completed < n) {
        int min_bt = INT_MAX, index = -1;

        // Find the process with the shortest remaining time
        for (i = 0; i < n; i++) {
            if (at[i] <= current_time && !completed_flag[i] && remaining_time[i] < min_bt) {
                min_bt = remaining_time[i];
                index = i;
            }
        }

        if (index == -1) {
            // No process is ready to execute, increment time
            current_time++;
        } else {
            // Execute the process for 1 unit of time
            gantt[gantt_index++] = pid[index]; // Add process to Gantt chart
            remaining_time[index]--;
            current_time++;

            // If the process is completed
            if (remaining_time[index] == 0) {
                ct[index] = current_time; // Completion time
                tat[index] = ct[index] - at[index]; // Turnaround time
                wt[index] = tat[index] - bt[index]; // Waiting time
                tot_tat += tat[index];
                tot_wt += wt[index];
                completed_flag[index] = 1;
                completed++;
            }
        }
    }

    // Calculate averages
    avgtat = tot_tat / n;
    avgwt = tot_wt / n;

    // Print results
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\nAverage TAT: %.2f", avgtat);
    printf("\nAverage WT: %.2f", avgwt);

    // Print Gantt chart
    printf("\n\nGANTT CHART:\n|");
    for (i = 0; i < gantt_index; i++) {
        printf(" P%d |", gantt[i]);
    }
    printf("\n0");
    for (i = 0; i < gantt_index; i++) {
        printf(" %d", current_time - gantt_index + i + 1); // Print timeline
    }
    printf("\n");

    return 0;
}