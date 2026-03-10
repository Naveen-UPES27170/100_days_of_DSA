#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX 1000

int pq[MAX];
int size = 0;

// Function to insert an element
void insert(int x) {
    if (size < MAX) {
        pq[size++] = x;
    }
}

// Function to find the index of the element with the highest priority (smallest value)
int getHighestPriorityIndex() {
    if (size == 0) return -1;
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to delete the highest priority element
void delete() {
    int index = getHighestPriorityIndex();
    if (index == -1) {
        printf("-1\n");
        return;
    }
    
    printf("%d\n", pq[index]);

    // Optimization: Swap with the last element instead of shifting everything
    pq[index] = pq[size - 1];
    size--;
}

// Function to peek at the highest priority element
void peek() {
    int index = getHighestPriorityIndex();
    if (index == -1) {
        printf("-1\n");
        return;
    }
    printf("%d\n", pq[index]);
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    char op[20];
    int val;

    for (int i = 0; i < N; i++) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "delete") == 0) {
            delete();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }

    return 0;
}
