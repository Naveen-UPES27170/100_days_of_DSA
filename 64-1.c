#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return front == -1 || front > rear;
}

void bfs(int adj[MAX][MAX], int n, int startNode) {
    int visited[MAX] = {0}; // Initialize all nodes as unvisited

    visited[startNode] = 1;
    enqueue(startNode);

    printf("BFS Traversal: ");

    while (!isEmpty()) {
        int currentNode = dequeue();
        printf("%d ", currentNode);

        for (int i = 0; i < n; i++) {
            // If there is an edge and the neighbor hasn't been visited
            if (adj[currentNode][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

int main() {
    int n, s;
    int adj[MAX][MAX];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter Adjacency Matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter source node: ");
    scanf("%d", &s);

    bfs(adj, n, s);

    return 0;
}
