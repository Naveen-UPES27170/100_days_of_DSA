#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 1000
#define INF INT_MAX

int graph[MAX][MAX];
int key[MAX];
bool inMST[MAX];

int findMinKey(int n) {
    int min = INF, min_index;
    for (int v = 1; v <= n; v++) {
        if (!inMST[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

int primMST(int n) {
    for (int i = 1; i <= n; i++) {
        key[i] = INF;
        inMST[i] = false;
    }

    key[1] = 0; // Starting from vertex 1
    int totalWeight = 0;

    for (int count = 0; count < n; count++) {
        int u = findMinKey(n);
        
        if (key[u] == INF) break; // Graph is disconnected

        inMST[u] = true;
        totalWeight += key[u];

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }
    return totalWeight;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Initialize graph with 0 (meaning no edge)
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        // Handle multiple edges between same nodes by keeping the minimum
        if (graph[u][v] == 0 || w < graph[u][v]) {
            graph[u][v] = w;
            graph[v][u] = w;
        }
    }

    printf("%d\n", primMST(n));

    return 0;
}
