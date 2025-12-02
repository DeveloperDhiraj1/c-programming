#include <stdio.h>

#define INF 9999
#define MAX 20

void floydWarshall(int cost[MAX][MAX], int n) {
    int dist[MAX][MAX];
    int i, j, k;

    // Step 1: Initialize dist matrix
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            dist[i][j] = cost[i][j];
        }
    }

    // Step 2: Floyd-Warshall logic
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Step 3: Print final distances
    printf("\nAll-Pairs Shortest Path Matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int cost[MAX][MAX], n;
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency cost matrix (use 9999 for INF):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    floydWarshall(cost, n);

    return 0;
}
