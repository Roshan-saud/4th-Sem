#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, m;  // n = number of processes, m = number of resource types
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    int allocation[n][m];
    int max[n][m];
    int available[m];
    int need[n][m];

    printf("Enter Allocation matrix (each row for a process):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);

    printf("Enter Max matrix (each row for a process):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available resources vector:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &available[i]);

    // Calculate Need matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];

    bool finish[n];
    for (int i = 0; i < n; i++)
        finish[i] = false;

    int safeSeq[n];
    int count = 0;

    while (count < n) {
        bool found = false;
        for (int p = 0; p < n; p++) {
            if (!finish[p]) {
                bool canAllocate = true;
                for (int r = 0; r < m; r++) {
                    if (need[p][r] > available[r]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    for (int r = 0; r < m; r++)
                        available[r] += allocation[p][r];

                    safeSeq[count++] = p;
                    finish[p] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            printf("System is NOT in safe state (Deadlock possible)\n");
            return 0;
        }
    }

    printf("System is in safe state.\nSafe sequence is: ");
    for (int i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");

    return 0;
}





