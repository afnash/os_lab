#include<stdio.h>

int main() {
    int fsize, pages[100], i, j, k, pgsize, pf = 0, hit = 0, miss = 0;
    int m[100], last_used[100]; // Frame array and last used timestamps

    printf("Enter size of string: ");
    scanf("%d", &pgsize);

    printf("\nEnter the string: ");
    for (i = 0; i < pgsize; i++) {
        scanf("%d", &pages[i]);
    }

    printf("\nEnter frame size: ");
    scanf("%d", &fsize);

    // Initialize the frame array and last used timestamps
    for (i = 0; i < fsize; i++) {
        m[i] = -1;
        last_used[i] = -1;
    }

    printf("\nPage Replacement Algorithm (LRU):\n");

    // LRU Page Replacement Algorithm
    for (i = 0; i < pgsize; i++) {
        int found = 0;

        // Check if the page is already in the frame (hit)
        for (j = 0; j < fsize; j++) {
            if (m[j] == pages[i]) {
                found = 1; // Page hit
                hit++;
                last_used[j] = i; // Update the last used timestamp
                break;
            }
        }

        // If the page is not in the frame (miss)
        if (!found) {
            int replace_index = -1, least_recently_used = pgsize;

            // Find the least recently used page
            for (j = 0; j < fsize; j++) {
                if (m[j] == -1) {
                    replace_index = j; // Empty frame found
                    break;
                }

                if (last_used[j] < least_recently_used) {
                    least_recently_used = last_used[j];
                    replace_index = j;
                }
            }

            // Replace the page
            m[replace_index] = pages[i];
            last_used[replace_index] = i; // Update the last used timestamp
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