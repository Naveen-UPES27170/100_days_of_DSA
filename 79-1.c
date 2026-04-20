#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100
#define INF INT_MAX

void dijkstra(int n, int adj[MAX][MAX], int src) {
    int dist[MAX];
    bool visited[MAX];

    // Initialize distances and visited array
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        // Find the vertex with the minimum distance from the set of non-visited vertices
        int min = INF, u;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                u = v;
            }
        }

        // Mark the picked vertex as processed
        visited[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && adj[u][v] && dist[u] != INF 
                && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    // Print the calculated shortest distances
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
    printf("\n");
}

int main() {
    int n, m, u, v, w, source;
    int adj[MAX][MAX] = {0};

    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w; // Assuming undirected graph based on sample
    }

    scanf("%d", &source);

    dijkstra(n, adj, source);

    return 0;
}
