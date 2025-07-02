#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} HashItem;

typedef struct {
    HashItem *table;
    int size;
} HashTable;

HashTable* createHashTable(int size) {
    HashTable *hashTable = (HashTable *)malloc(sizeof(HashTable));
    hashTable->size = size;
    hashTable->table = (HashItem *)calloc(size, sizeof(HashItem));
    return hashTable;
}

int hashFunction(int key, int size) {
    return key % size;
}

void insert(HashTable *hashTable, int key, int value) {
    int index = hashFunction(key, hashTable->size);

    while (hashTable->table[index].key != 0) {
        index = (index + 1) % hashTable->size;
    }
    
    hashTable->table[index].key = key;
    hashTable->table[index].value = value;
}

int search(HashTable *hashTable, int key) {
    int index = hashFunction(key, hashTable->size);
    int start = index;

    while (hashTable->table[index].key != 0) {
        if (hashTable->table[index].key == key) {
            return hashTable->table[index].value;
        }
        index = (index + 1) % hashTable->size;
        
        if (index == start) {
            break;
        }
    }
    return -1;
}

void display(HashTable *hashTable) {
    printf("Hash Table:\n");
    for (int i = 0; i < hashTable->size; i++) {
        if (hashTable->table[i].key != 0) {
            printf("Index %d: Key = %d, Value = %d\n", i, hashTable->table[i].key, hashTable->table[i].value);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }
}

int main() {
    int size, choice, key, value;

    printf("Enter the size of the hash table: ");
    scanf("%d", &size);

    HashTable *hashTable = createHashTable(size);

    while (1) {
        printf("Menu: ");
        printf("1. Insert ");
        printf("2. Search ");
        printf("3. Display ");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key and value to insert: ");
                scanf("%d %d", &key, &value);
                insert(hashTable, key, value);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                value = search(hashTable, key);
                if (value != -1) {
                    printf("Value found: %d\n", value);
                } else {
                    printf("Key not found.\n");
                }
                break;

            case 3:
                display(hashTable);
                break;

            case 4:
                free(hashTable->table);
                free(hashTable);
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
