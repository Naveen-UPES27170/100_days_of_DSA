#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

// Adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];
int nodes_reached = 0;

// Function to add an edge to the adjacency list
void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// DFS Traversal
void DFS(int v) {
    visited[v] = 1;
    nodes_reached++;
    
    struct Node* temp = adj[v];
    while (temp) {
        int neighbor = temp->vertex;
        if (!visited[neighbor]) {
            DFS(neighbor);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Initialize adjacency list and visited array
    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    // Read m edges (Undirected Graph)
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }

    // Start DFS from the first node (if nodes exist)
    if (n > 0) {
        DFS(1);
    }

    // If the number of nodes reached by DFS equals total nodes n
    if (nodes_reached == n) {
        printf("CONNECTED\n");
    } else {
        printf("NOT CONNECTED\n");
    }

    return 0;
}
