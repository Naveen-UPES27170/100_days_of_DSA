#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Function to return precedence of operators
int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

// Infix to Postfix function
void infixToPostfix(char* infix) {
    char stack[MAX];
    int top = -1;
    int i, j = 0;
    char postfix[MAX];

    for (i = 0; infix[i]; i++) {
        // If character is an operand, add it to output
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }
        // If character is '(', push to stack
        else if (infix[i] == '(') {
            stack[++top] = '(';
        }
        // If character is ')', pop until '(' is found
        else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            top--; // remove '('
        }
        // If character is an operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';
    printf("%s\n", postfix);
}

int main() {
    char infix[MAX];
    if (scanf("%s", infix) != 1) return 0;
    infixToPostfix(infix);
    return 0;
}
