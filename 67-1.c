#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n; // Number of vertices

void push(int v) {
    stack[++top] = v;
}

int pop() {
    return stack[top--];
}

void dfs(int v) {
    visited[v] = 1;
    
    for (int i = 0; i < n; i++) {
        // If there is an edge and the vertex is not visited
        if (adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }
    
    // Push to stack after all neighbors are visited
    push(v);
}

void topologicalSort() {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    
    printf("Topological Ordering: ");
    while (top != -1) {
        printf("%d ", pop());
    }
    printf("\n");
}

int main() {
    int edges, u, v;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    // Initialize adjacency matrix to 0
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            adj[i][j] = 0;

    printf("Enter edges (format: source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }
    
    topologicalSort();
    
    return 0;
}
