#include <stdio.h>
#include <limits.h>

#define INF 1e9 // Using a large value to represent infinity

void floydWarshall(int n, int matrix[n][n]) {
    int dist[n][n];

    // Initialize the distance matrix with input values
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1 && i != j) {
                dist[i][j] = INF;
            } else {
                dist[i][j] = matrix[i][j];
            }
        }
    }

    // Triple nested loop: k is the intermediate vertex
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Check if path through vertex k is shorter
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the final shortest distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) {
                printf("-1 ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int matrix[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    floydWarshall(n, matrix);

    return 0;
}
