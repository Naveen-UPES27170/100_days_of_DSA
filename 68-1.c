#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void kahnAlgorithm(int n, int adj[MAX][MAX]) {
    int in_degree[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    int topo_order[MAX], count = 0;

    // 1. Calculate in-degree of each vertex
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                in_degree[j]++;
            }
        }
    }

    // 2. Enqueue all vertices with in-degree 0
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // 3. Process the queue
    while (front < rear) {
        int u = queue[front++];
        topo_order[count++] = u;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1) {
                in_degree[v]--; // "Remove" edge (u, v)
                
                if (in_degree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    // 4. Output the result
    if (count < n) {
        printf("Error: The graph contains a cycle. Topological sort not possible.\n");
    } else {
        printf("Topological Sort: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", topo_order[i]);
        }
        printf("\n");
    }
}

int main() {
    int n, edges, u, v;
    int adj[MAX][MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (format: source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    kahnAlgorithm(n, adj);

    return 0;
}
