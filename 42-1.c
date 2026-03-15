#include <stdio.h>
#include <stdlib.h>

// Queue Node
struct Node {
    int data;
    struct Node* next;
};

// Queue Structure
struct Queue {
    struct Node *front, *rear;
};

// Stack Structure
struct Stack {
    int top;
    int capacity;
    int* array;
};

// Helper to create Queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Helper to create Stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

void enqueue(struct Queue* q, int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(struct Queue* q) {
    if (q->front == NULL) return -1;
    struct Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return data;
}

void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

// Logic to reverse the queue
void reverseQueue(struct Queue* q, int n) {
    struct Stack* s = createStack(n);

    // Step 1: Queue -> Stack
    while (q->front != NULL) {
        push(s, dequeue(q));
    }

    // Step 2: Stack -> Queue
    while (s->top != -1) {
        enqueue(q, pop(s));
    }
}

void printQueue(struct Queue* q) {
    struct Node* temp = q->front;
    while (temp != NULL) {
        printf("%d%s", temp->data, temp->next ? " " : "");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, val;
    if (scanf("%d", &n) != 1) return 0;

    struct Queue* q = createQueue();
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(q, val);
    }

    reverseQueue(q, n);
    printQueue(q);

    return 0;
}
