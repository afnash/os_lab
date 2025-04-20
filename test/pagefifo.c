#include<stdio.h>

int main() {
    int fsize, pages[100], i, j, k, pgsize, pf = 0, hit = 0, miss = 0, count = 0;
    int m[100]; // Frame array

    printf("Enter size of string: ");
    scanf("%d", &pgsize);

    printf("\nEnter the string: ");
    for (i = 0; i < pgsize; i++) {
        scanf("%d", &pages[i]);
    }

    printf("\nEnter frame size: ");
    scanf("%d", &fsize);

    // Initialize the frame array to -1
    for (i = 0; i < fsize; i++) {
        m[i] = -1;
    }

    printf("\nPage Replacement Algorithm (FIFO):\n");

    // FIFO Page Replacement Algorithm
    for (i = 0; i < pgsize; i++) {
        int found = 0;

        // Check if the page is already in the frame (hit)
        for (j = 0; j < fsize; j++) {
            if (m[j] == pages[i]) {
                found = 1; // Page hit
                hit++;
                break;
            }
        }

        // If the page is not in the frame (miss)
        if (!found) {
            m[count] = pages[i]; // Replace the page using FIFO
            count = (count + 1) % fsize; // Update the FIFO index
            pf++; // Increment page fault count
            miss++;
        }

        // Print the current state of the frame
        printf("Page %d: ", pages[i]);
        for (k = 0; k < fsize; k++) {
            if (m[k] != -1) {
                printf("%d ", m[k]);
            } else {
                printf("- ");
            }
        }
        if (!found) {
            printf(" (Page Fault)");
        } else {
            printf(" (Hit)");
        }
        printf("\n");
    }

    // Calculate and display hit ratio and miss ratio
    float hit_ratio = (float)hit / pgsize;
    float miss_ratio = (float)miss / pgsize;

    printf("\nTotal Page Faults: %d", pf);
    printf("\nTotal Hits: %d", hit);
    printf("\nHit Ratio: %.2f", hit_ratio);
    printf("\nMiss Ratio: %.2f\n", miss_ratio);

    return 0;
}