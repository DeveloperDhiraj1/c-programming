#include <stdio.h>

int n, M;
int w[20], x[20];

void sumOfSubset(int i, int currentSum, int remainingSum) {
    if (currentSum == M) {
        printf("Subset: ");
        for (int k = 1; k <= n; k++) {
            if (x[k] == 1)
                printf("%d ", w[k]);
        }
        printf("\n");
        return;
    }

    if (i > n || currentSum + remainingSum < M)
        return;

    // Include w[i]
    x[i] = 1;
    sumOfSubset(i + 1, currentSum + w[i], remainingSum - w[i]);

    // Exclude w[i]
    x[i] = 0;
    sumOfSubset(i + 1, currentSum, remainingSum - w[i]);
}

int main() {
    int totalSum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
        totalSum += w[i];
    }

    printf("Enter target sum: ");
    scanf("%d", &M);

    printf("\nSubsets with sum = %d:\n", M);
    sumOfSubset(1, 0, totalSum);

    return 0;
}
