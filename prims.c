#include <stdio.h>
#include <limits.h>

#define INF 99999

int minKey(int key[], int mstSet[], int n) {
    int min = INF, minIndex;

    for (int v = 0; v < n; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void primMST(int graph[20][20], int n) {
    int parent[n];
    int key[n];
    int mstSet[n];

    // Initialization
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    // Build MST
    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print MST
    printf("\nMinimum Spanning Tree (Prim's Algorithm):\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d  Weight: %d\n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {
    int n;
    int graph[20][20];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph, n);

    return 0;
}
