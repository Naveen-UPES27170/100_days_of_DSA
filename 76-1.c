#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

// Adjacency list using linked list nodes
struct Node {
    int dest;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];

// Function to add an edge
void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// DFS to visit all nodes in a component
void dfs(int u) {
    visited[u] = 1;
    struct Node* temp = adj[u];
    while (temp != NULL) {
        int v = temp->dest;
        if (!visited[v]) {
            dfs(v);
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

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u); // Undirected graph
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            // Found a new component
            count++;
            dfs(i);
        }
    }

    printf("%d\n", count);

    return 0;
}
