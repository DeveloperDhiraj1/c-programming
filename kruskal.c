#include <stdio.h>

struct Edge {
    int src, dest, weight;
};

// Function to find parent (find-set)
int findParent(int parent[], int v) {
    if (parent[v] == v)
        return v;
    return findParent(parent, parent[v]);
}

// Union of two sets
void unionSet(int parent[], int x, int y) {
    int xset = findParent(parent, x);
    int yset = findParent(parent, y);
    parent[yset] = xset;
}

// Sort edges based on weight
void sortEdges(struct Edge edges[], int E) {
    struct Edge temp;
    for (int i = 0; i < E - 1; i++) {
        for (int j = i + 1; j < E; j++) {
            if (edges[i].weight > edges[j].weight) {
                temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }
}

void kruskal(struct Edge edges[], int V, int E) {
    struct Edge mst[V];  // To store MST edges
    int parent[V];

    // Initialize disjoint sets
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // Step 1: Sort edges by weight
    sortEdges(edges, E);

    int count = 0;  // number of edges included in MST
    int i = 0;      // index for sorted edges

    // Pick edges until MST has V-1 edges
    while (count < V - 1 && i < E) {
        struct Edge next = edges[i++];

        int x = findParent(parent, next.src);
        int y = findParent(parent, next.dest);

        if (x != y) {   // If adding edge does not cause cycle
            mst[count++] = next;
            unionSet(parent, x, y);
        }
    }

    // Print MST
    printf("\nMinimum Spanning Tree (Kruskal's Algorithm):\n");
    int totalWeight = 0;

    for (i = 0; i < count; i++) {
        printf("%d - %d   Weight: %d\n", mst[i].src, mst[i].dest, mst[i].weight);
        totalWeight += mst[i].weight;
    }

    printf("\nTotal Weight of MST = %d\n", totalWeight);
}

int main() {
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Edge edges[E];

    printf("Enter edges (src dest weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    kruskal(edges, V, E);

    return 0;
}
