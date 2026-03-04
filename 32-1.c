#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Stack structure
struct Stack {
    int top;
    int items[MAX];
};

// Function to initialize stack
void initStack(struct Stack* s) {
    s->top = -1;
}

// Function to push element
void push(struct Stack* s, int val) {
    if (s->top == MAX - 1) {
        return; // Stack Overflow
    }
    s->items[++(s->top)] = val;
}

// Function to pop element
void pop(struct Stack* s) {
    if (s->top == -1) {
        return; // Stack Underflow
    }
    s->top--;
}

// Function to print stack from top to bottom
void printStack(struct Stack* s) {
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main() {
    struct Stack s;
    initStack(&s);

    int n, val, m;

    // Input total elements to push
    if (scanf("%d", &n) != 1) return 0;

    // Push n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(&s, val);
    }

    // Input number of pops
    if (scanf("%d", &m) != 1) return 0;

    // Perform m pops
    for (int i = 0; i < m; i++) {
        pop(&s);
    }

    // Output remaining elements
    printStack(&s);

    return 0;
}
