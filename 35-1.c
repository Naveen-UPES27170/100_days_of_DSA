#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Define the Queue structure to keep track of Front and Rear
struct Queue {
    struct Node *front, *rear;
};

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue: Add an element to the rear
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // If queue is empty, new node is both front and rear
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    // Add the new node at the end and update rear
    q->rear->next = newNode;
    q->rear = newNode;
}

// Display the queue from front to rear
void display(struct Queue* q) {
    struct Node* temp = q->front;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, value;
    struct Queue* q = createQueue();

    // Read number of elements
    if (scanf("%d", &n) != 1) return 0;

    // Read n integers and enqueue them
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(q, value);
    }

    // Output the queue
    display(q);

    return 0;
}
