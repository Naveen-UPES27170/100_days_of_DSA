#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
int n; // Number of vertices

bool isCyclePresent(int curr, int parent) {
    visited[curr] = true;

    for (int i = 0; i < n; i++) {
        // Check if there is an edge to vertex i
        if (adj[curr][i]) {
            // If neighbor is not visited, recurse
            if (!visited[i]) {
                if (isCyclePresent(i, curr))
                    return true;
            }
            // If neighbor is visited and NOT the parent, cycle found
            else if (i != parent) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int e; // Number of edges
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    // Initialize adjacency matrix
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // Undirected
    }

    bool hasCycle = false;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (isCyclePresent(i, -1)) {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle) printf("YES\n");
    else printf("NO\n");

    return 0;
}
