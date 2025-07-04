#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next ;
};
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL ;
    return newNode; 
}
void printList(struct Node* head){
    struct Node*temp = head;
    printf("Linked List:");
    while(temp!=NULL){
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void insertAtend(struct Node** head,int data){
    struct Node* newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
        return;

    }
    struct Node* temp = *head ;
    while(temp->next!= NULL){
        temp = temp->next;

    }
    temp->next = newNode ;
}
int main(){
    struct Node* head = NULL;
    int items[] = {10,13,24,26};
    int n = sizeof(items)/sizeof(items[0]);

    for(int i =0;i<n;i++){
        insertAtend(&head, items[i]);

    }
    printList(head);
    return 0;
}
