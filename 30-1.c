#include <stdio.h>
#include <stdlib.h>

// Define the structure for a polynomial term
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(struct Node** head, int c, int e) {
    struct Node* newNode = createNode(c, e);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the polynomial in standard form
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        // Handle coefficient and x^exp
        if (temp->exp == 0) {
            printf("%d", temp->coeff);
        } else if (temp->exp == 1) {
            printf("%dx", temp->coeff);
        } else {
            printf("%dx^%d", temp->coeff, temp->exp);
        }

        // Handle the '+' sign between terms
        temp = temp->next;
        if (temp != NULL && temp->coeff >= 0) {
            printf(" + ");
        } else if (temp != NULL && temp->coeff < 0) {
            printf(" "); // For negative coeffs, the sign is handled by the int
        }
    }
    printf("\n");
}

int main() {
    struct Node* poly = NULL;
    int n, c, e;

    // Input number of terms
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        insertEnd(&poly, c, e);
    }

    // Output the formatted polynomial
    display(poly);

    return 0;
}
