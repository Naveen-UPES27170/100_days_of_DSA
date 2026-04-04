#include <stdio.h>

#define MAX 100

int visited[MAX];
int c[MAX];      // array to store DFS traversal
int idx = 0;     // index for array c

void dfs(int v, int adj[MAX][MAX], int n) {
    visited[v] = 1;
    c[idx++] = v;   // store traversal

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i, adj, n);
        }
    }
}

int main() {
    int n, adj[MAX][MAX], s;

    // Input number of vertices
    scanf("%d", &n);

    // Input adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Input starting vertex
    scanf("%d", &s);

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Perform DFS
    dfs(s, adj, n);

    // Output DFS traversal
    for (int i = 0; i < idx; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}
