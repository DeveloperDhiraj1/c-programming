// Online C compiler to run C program online
#include <stdio.h>
#define MAX 100

typedef struct {
    int size;
    int allocated;
} Block;

void internalFragmentation(Block memory[], int n, int processSize[], int m) {
    int totalFragmentation = 0;
    printf("\n[INTERNAL FRAGMENTATION]\n");
    for (int i = 0; i < m; i++) {
        int allocated = 0;
        for (int j = 0; j < n; j++) {
            if (!memory[j].allocated && memory[j].size >= processSize[i]) {
                memory[j].allocated = 1;
                allocated = 1;
                int frag = memory[j].size - processSize[i];
                totalFragmentation += frag;
                printf("Process %d of size %d allocated in block %d of size %d. Internal Fragmentation: %d\n",
                        i + 1, processSize[i], j + 1, memory[j].size, frag);
                break;
            }
        }
        if (!allocated)
            printf("Process %d of size %d cannot be allocated\n", i + 1, processSize[i]);
    }
    printf("Total Internal Fragmentation: %d\n", totalFragmentation);
}

void externalFragmentation(Block memory[], int n, int processSize[], int m) {
    int totalFree = 0;
    for (int i = 0; i < n; i++) {
        if (!memory[i].allocated)
            totalFree += memory[i].size;
    }

    printf("\n[EXTERNAL FRAGMENTATION]\n");
    for (int i = 0; i < m; i++) {
        int canFit = 0;
        for (int j = 0; j < n; j++) {
            if (!memory[j].allocated && memory[j].size >= processSize[i]) {
                canFit = 1;
                break;
            }
        }
        if (!canFit && processSize[i] <= totalFree)
            printf("Process %d of size %d cannot be allocated due to external fragmentation\n", i + 1, processSize[i]);
    }
}

int main() {
    int n, m;
    Block memory[MAX];
    int processSize[MAX];

    printf("Enter number of memory blocks: ");
    scanf("%d", &n);
    printf("Enter sizes of memory blocks:\n");
    for (int i = 0; i < n; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &memory[i].size);
        memory[i].allocated = 0;
    }

    printf("\nEnter number of processes: ");
    scanf("%d", &m);
    printf("Enter sizes of processes:\n");
    for (int i = 0; i < m; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    internalFragmentation(memory, n, processSize, m);
    externalFragmentation(memory, n, processSize, m);

    return 0;
}