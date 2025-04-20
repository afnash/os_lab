#include<stdio.h>

int main() {
    int fsize, pages[100], i, j, k, pgsize, pf = 0, hit = 0, miss = 0;
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

    printf("\nPage Replacement Algorithm (Optimal):\n");

    // Optimal Page Replacement Algorithm
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
            int replace_index = -1, farthest = -1;

            // Find the page to replace
            for (j = 0; j < fsize; j++) {
                if (m[j] == -1) {
                    replace_index = j; // Empty frame found
                    break;
                }

                // Check how far in the future the page is used
                int next_use = -1;
                for (k = i + 1; k < pgsize; k++) {
                    if (m[j] == pages[k]) {
                        next_use = k;
                        break;
                    }
                }

                // If the page is not used in the future, replace it
                if (next_use == -1) {
                    replace_index = j;
                    break;
                }

                // Otherwise, find the page used farthest in the future
                if (next_use > farthest) {
                    farthest = next_use;
                    replace_index = j;
                }
            }

            // Replace the page
            m[replace_index] = pages[i];
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