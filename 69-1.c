#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

typedef struct {
    int vertex;
    int weight;
} Node;

typedef struct {
    Node heap[MAX * MAX];
    int size;
} MinHeap;

// Basic Min-Heap Functions
void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap *pq, int v, int w) {
    pq->heap[pq->size++] = (Node){v, w};
    int i = pq->size - 1;
    while (i > 0 && pq->heap[i].weight < pq->heap[(i - 1) / 2].weight) {
        swap(&pq->heap[i], &pq->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Node pop(MinHeap *pq) {
    Node root = pq->heap[0];
    pq->heap[0] = pq->heap[--pq->size];
    int i = 0;
    while (i * 2 + 1 < pq->size) {
        int smallest = i * 2 + 1;
        if (smallest + 1 < pq->size && pq->heap[smallest + 1].weight < pq->heap[smallest].weight)
            smallest++;
        if (pq->heap[i].weight <= pq->heap[smallest].weight) break;
        swap(&pq->heap[i], &pq->heap[smallest]);
        i = smallest;
    }
    return root;
}

void dijkstra(int n, int adj[MAX][MAX], int src) {
    int dist[MAX];
    for (int i = 0; i < n; i++) dist[i] = INF;

    MinHeap pq = { .size = 0 };
    dist[src] = 0;
    push(&pq, src, 0);

    while (pq.size > 0) {
        Node current = pop(&pq);
        int u = current.vertex;

        if (current.weight > dist[u]) continue;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] != 0) { // If edge exists
                if (dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                    push(&pq, v, dist[v]);
                }
            }
        }
    }

    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++) {
        printf("Node %d: %d\n", i, dist[i]);
    }
}

int main() {
    int n, edges, u, v, w, src;
    int adj[MAX][MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter source, destination, and weight: ");
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w; // Directed graph
    }

    printf("Enter source node: ");
    scanf("%d", &src);

    dijkstra(n, adj, src);

    return 0;
}
