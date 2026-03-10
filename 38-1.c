#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

typedef struct {
    Node *front, *rear;
    int count;
} Deque;

void initDeque(Deque* dq) {
    dq->front = dq->rear = NULL;
    dq->count = 0;
}

int isEmpty(Deque* dq) {
    return dq->count == 0;
}

void push_front(Deque* dq, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = dq->front;
    newNode->prev = NULL;

    if (isEmpty(dq)) dq->rear = newNode;
    else dq->front->prev = newNode;
    
    dq->front = newNode;
    dq->count++;
}

void push_back(Deque* dq, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->prev = dq->rear;
    newNode->next = NULL;

    if (isEmpty(dq)) dq->front = newNode;
    else dq->rear->next = newNode;

    dq->rear = newNode;
    dq->count++;
}

void pop_front(Deque* dq) {
    if (isEmpty(dq)) return;
    Node* temp = dq->front;
    dq->front = dq->front->next;
    
    if (dq->front == NULL) dq->rear = NULL;
    else dq->front->prev = NULL;
    
    free(temp);
    dq->count--;
}

void pop_back(Deque* dq) {
    if (isEmpty(dq)) return;
    Node* temp = dq->rear;
    dq->rear = dq->rear->prev;
    
    if (dq->rear == NULL) dq->front = NULL;
    else dq->rear->next = NULL;
    
    free(temp);
    dq->count--;
}

void display(Deque* dq) {
    Node* temp = dq->front;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Deque dq;
    initDeque(&dq);
    
    // Example Operations
    push_back(&dq, 10);
    push_back(&dq, 20);
    push_front(&dq, 5);
    push_back(&dq, 30);
    
    printf("Deque: ");
    display(&dq); // Output: 5 10 20 30
    
    pop_front(&dq);
    pop_back(&dq);
    
    printf("After Popping Front and Back: ");
    display(&dq); // Output: 10 20
    
    return 0;
}
