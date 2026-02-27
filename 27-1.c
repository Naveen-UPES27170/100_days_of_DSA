struct Node* getIntersectionNodeElegant(struct Node* head1, struct Node* head2) {
    if (head1 == NULL || head2 == NULL) return NULL;

    struct Node* a = head1;
    struct Node* b = head2;

    while (a != b) {
        a = (a == NULL) ? head2 : a->next;
        b = (b == NULL) ? head1 : b->next;
    }
    return a; 
}
