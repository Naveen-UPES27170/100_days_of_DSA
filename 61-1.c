#include <stdio.h>
#include <stdlib.h>

void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m, isDirected;
    
    // Read number of vertices and edges
    if (scanf("%d %d", &n, &m) != 2) return 0;
    
    // Ask or assume if the graph is directed (0 for undirected, 1 for directed)
    // For this example, let's assume undirected as per standard matrix problems
    isDirected = 0; 

    // Dynamically allocate n x n matrix
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)calloc(n, sizeof(int)); // calloc initializes to 0
    }

    // Read m edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        // Adjust for 0-based indexing if input is 1-based
        // matrix[u-1][v-1] = 1;
        
        matrix[u][v] = 1;
        if (!isDirected) {
            matrix[v][u] = 1;
        }
    }

    // Output the matrix
    printMatrix(matrix, n);

    // Free memory
    for (int i = 0; i < n; i++) free(matrix[i]);
    free(matrix);

    return 0;
}
