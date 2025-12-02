#include <stdio.h>

// Maximum function
int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int profit[], int weight[], int n, int W) {
    int dp[n + 1][W + 1];

    // Build DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {

            if (i == 0 || w == 0)
                dp[i][w] = 0;

            else if (weight[i - 1] > w)
                dp[i][w] = dp[i - 1][w];

            else
                dp[i][w] = max(
                    profit[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int profit[n], weight[n];

    printf("Enter profit and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d profit: ", i + 1);
        scanf("%d", &profit[i]);
        printf("Item %d weight: ", i + 1);
        scanf("%d", &weight[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    int result = knapsack(profit, weight, n, W);

    printf("\nMaximum Profit = %d\n", result);

    return 0;
}
