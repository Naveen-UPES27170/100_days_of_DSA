#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY -1

typedef struct {
    int size;
    int* table;
} HashTable;

// Initialize the hash table with -1 (EMPTY)
HashTable* createTable(int m) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->size = m;
    ht->table = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        ht->table[i] = EMPTY;
    }
    return ht;
}

void insert(HashTable* ht, int key) {
    int m = ht->size;
    int h_prime = key % m;
    
    for (int i = 0; i < m; i++) {
        int index = (h_prime + i * i) % m;
        if (ht->table[index] == EMPTY) {
            ht->table[index] = key;
            return;
        }
    }
}

void search(HashTable* ht, int key) {
    int m = ht->size;
    int h_prime = key % m;
    
    for (int i = 0; i < m; i++) {
        int index = (h_prime + i * i) % m;
        if (ht->table[index] == key) {
            printf("FOUND\n");
            return;
        }
        if (ht->table[index] == EMPTY) {
            break; // Stop if we hit an empty slot
        }
    }
    printf("NOT FOUND\n");
}

int main() {
    int m, num_ops;
    if (scanf("%d %d", &m, &num_ops) != 2) return 0;

    HashTable* ht = createTable(m);

    for (int i = 0; i < num_ops; i++) {
        char op[10];
        int val;
        scanf("%s %d", op, &val);

        if (strcmp(op, "INSERT") == 0) {
            insert(ht, val);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(ht, val);
        }
    }

    // Clean up memory
    free(ht->table);
    free(ht);
    return 0;
}
