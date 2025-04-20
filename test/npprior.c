#include <stdio.h>

int main()
{
    int p[10], at[10], bt[10], ct[10], wt[10], tat[10],pri[10], i, j, n, temp;
    float atat = 0, awt = 0;

    printf("Enter no. of processes: ");
    scanf("%d", &n);

    printf("Enter Pid, AT , BT and Priority of %d processes: \n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &p[i], &at[i], &bt[i],&pri[i]);
    }

    // Check if any process has at[i] == 0 and bring it to the front
    int found = 0;
    for (i = 0; i < n; i++)
    {
        if (at[i] == 0)
        {
            // Swap to bring process with at[i] == 0 to the front
            temp = at[0];
            at[0] = at[i];
            at[i] = temp;

            temp = bt[0];
            bt[0] = bt[i];
            bt[i] = temp;

            temp = p[0];
            p[0] = p[i];
            p[i] = temp;

            temp = pri[j];
            pri[j] = pri[j + 1];
            pri[j + 1] = temp;

            found = 1; // Mark that a process with at[i] == 0 was found
        }
    }

    // Sort processes based on burst time (bt[])
    // If a process with at[i] == 0 was found, start sorting from index 1
    // Otherwise, sort the entire array from index 0
    int start = found ? 1 : 0;
    for (i = start; i < n ; i++)
    {
        for (j = start; j < n - i; j++)
        {
            if (pri[j] < pri[j + 1])
            {
                // Swap pri
                temp = pri[j];
                pri[j] = pri[j + 1];
                pri[j + 1] = temp;
                //swap bt
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap AT
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                // Swap process IDs
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Calculate Completion Time (CT), Turnaround Time (TAT), and Waiting Time (WT)
    ct[0] = at[0] + bt[0]; // First process
    for (i = 1; i < n; i++)
    {
        if (ct[i - 1] < at[i])
        {
            ct[i] = at[i] + bt[i]; // If CPU is idle
        }
        else
        {
            ct[i] = ct[i - 1] + bt[i];
        }
    }

    for (i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i]; // Turnaround Time
        wt[i] = tat[i] - bt[i]; // Waiting Time
        atat += tat[i];
        awt += wt[i];
    }

    atat /= n; // Average Turnaround Time
    awt /= n;  // Average Waiting Time

    // Print results
    printf("\nPID \t AT \t BT \t CT \t TAT \t WT");
    printf("\n--------------------------------------");
    for (i = 0; i < n; i++)
    {
        printf("\nP%d \t %d \t %d \t %d \t %d \t %d", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\n\nAverage TAT = %f", atat);
    printf("\nAverage WT = %f\n", awt);

    return 0;
}