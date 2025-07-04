#include <stdio.h>
#include <stdlib.h>

// Define structure of Node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to reverse a linked list
struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to merge two sorted linked lists
struct Node* merge(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL) tail->next = l1;
    else tail->next = l2;

    return dummy.next;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // First sorted linked list
    struct Node* list1 = newNode(1);
    list1->next = newNode(3);
    list1->next->next = newNode(5);

    // Second sorted linked list
    struct Node* list2 = newNode(2);
    list2->next = newNode(4);
    list2->next->next = newNode(6);

    printf("Original List 1: ");
    printList(list1);
    printf("Original List 2: ");
    printList(list2);

    // Reverse both lists
    list1 = reverse(list1);
    list2 = reverse(list2);

    printf("Reversed List 1: ");
    printList(list1);
    printf("Reversed List 2: ");
    printList(list2);

    // Merge reversed lists
    struct Node* merged = merge(list1, list2);

    printf("Merged List (from their end): ");
    printList(merged);

    return 0;
}