#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct CircularQueue {
    struct Node *front, *rear;
};

// Function to add elements
void enqueue(struct CircularQueue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    
    if (q->front == NULL) {
        q->front = newNode;
    } else {
        q->rear->next = newNode;
    }
    
    q->rear = newNode;
    q->rear->next = q->front; // Make it circular
}

// Function to "dequeue" by shifting the front pointer m times
void shiftFront(struct CircularQueue* q, int m, int n) {
    if (n == 0) return;
    m = m % n; // Handle cases where m > n
    for (int i = 0; i < m; i++) {
        q->front = q->front->next;
        q->rear = q->rear->next;
    }
}

void display(struct CircularQueue* q, int n) {
    if (q->front == NULL) return;
    struct Node* temp = q->front;
    for (int i = 0; i < n; i++) {
        printf("%d", temp->data);
        if (i < n - 1) printf(" ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct CircularQueue q = {NULL, NULL};
    int n, m, val;

    // 1. Input n elements
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    // 2. Input m shifts (simulated dequeue)
    if (scanf("%d", &m) != 1) return 0;

    // 3. Perform the shift
    shiftFront(&q, m, n);

    // 4. Display result
    display(&q, n);

    return 0;
}
