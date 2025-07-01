//Implement Doubly Linked List  and related operations like insertion, deletion, display, reverse and sort in C.

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}link;

link *create(int data){
    link *newnode = (link*)malloc(sizeof(link));
    if(newnode == NULL){
        printf("FAILED TO CREATE!\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next = newnode->prev = NULL;
    return newnode;
}

link *insert_first(link *head , int data){
    link *ptr = create(data);
    if (head == NULL) {
        return ptr;
    }
    ptr->next = head;
    head->prev = ptr;
    return ptr;
}

link *insert_any(link *head , int index , int data){
    if(index == 0) return insert_first(head, data);
    link *p = create(data);
    link *q = head;
    int i = 0;
    while(i != index-1 && q->next != NULL){
        q = q->next;
        i++;
    }
    if(i != index-1){
        printf("INDEX OUT OF BOUND\n");
        free(p);
        return head;
    }
    p->next = q->next;
    p->prev = q;
    if(q->next != NULL) q->next->prev = p;
    q->next = p;
    return head;
}

link *insert_last(link *head , int data){
    link *p = create(data);
    if (head == NULL) {
        return p;
    }
    link *q = head;
    while (q->next != NULL) {
        q = q->next;
    }
    q->next = p;
    p->prev = q;
    return head;
}

link *delete_first(link *head){
    if (head == NULL) return NULL;
    link *temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    free(temp);
    return head;
}

link *delete_any(link *head , int index){
    if(head == NULL){
        printf("HEAD = NULL\n");
        return NULL;
    }
    if(index == 0) {
        return delete_first(head);
    }
    link *p = head;
    int i = 0;
    while(i != index && p != NULL){
        p = p->next;
        i++;
    }
    if(p == NULL){
        printf("INDEX OUT OF BOUND!\n");
        return head;
    }
    if(p->prev != NULL) p->prev->next = p->next;
    if(p->next != NULL) p->next->prev = p->prev;
    free(p);
    return head;
}

link *delete_last(link *head){
    if(head == NULL){
        printf("HEAD = NULL\n");
        return NULL;
    }
    link *p = head;
    while(p->next != NULL){
        p = p->next;
    }
    if(p->prev != NULL){
        p->prev->next = NULL;
    } else {
        head = NULL;
    }
    free(p);
    return head;
}

link *delete_Value(link *head, int value){
    if (head == NULL) return NULL;
    link *p = head;
    while(p != NULL && p->data != value){
        p = p->next;
    }
    if(p == NULL){
        printf("VALUE NOT FOUND\n");
        return head;
    }
    if(p->prev != NULL) p->prev->next = p->next;
    if(p->next != NULL) p->next->prev = p->prev;
    if(p == head) head = p->next;
    free(p);
    return head;
}

void display(link *head){
    if(head == NULL){
        printf("NO ELEMENTS TO SHOW!\n");
        return;
    }
    link *temp = head;
    while (temp != NULL) {
        printf(" %d ->", temp->data);
        temp = temp->next;
    }
    printf(" NULL\n");
}

link *sort(link *head){
    if(head == NULL || head->next == NULL) return head;
    link *p, *q;
    int a, x;
    printf("SORT : 1. ASCENDING 2. DESCENDING : ");
    scanf("%d", &a);
    for(p = head; p->next != NULL; p = p->next){
        for(q = p->next; q != NULL; q = q->next){
            if((a == 1 && p->data > q->data) || (a == 2 && p->data < q->data)){
                x = p->data;
                p->data = q->data;
                q->data = x;
            }
        }
    }
    return head;
}

link *reverse(link *head){
    if(head == NULL || head->next == NULL) return head;
    link *current = head;
    link *temp = NULL;
    while(current != NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if(temp != NULL) head = temp->prev;
    return head;
}

int main(){
    int a, b, c, d, e, f, g, h, ch;
    link *head = NULL;
    while(ch != 6){
        printf("1. INSERTION 2. DELETION 3. DISPLAY 4. SORT 5. REVERSE 6. EXIT\nCHOICE : ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("INSERTION : 1. BEGINNING 2. AT ANY INDEX 3. END\nCHOICE : ");
                scanf("%d", &a);
                switch(a){
                    case 1:
                        printf("ENTER THE VALUE :");
                        scanf("%d", &b);
                        head = insert_first(head, b);
                        break;
                    case 2:
                        printf("ENTER THE VALUE :");
                        scanf("%d", &c);
                        printf("ENTER THE INDEX :");
                        scanf("%d", &d);
                        head = insert_any(head, d, c);
                        break;
                    case 3:
                        printf("ENTER THE VALUE :");
                        scanf("%d", &e);
                        head = insert_last(head, e);
                        break;
                    default:
                        printf("WRONG INPUT!\n");
                }
                display(head);
                break;
            case 2:
                printf("DELETION : 1. BEGINNING 2. AT ANY INDEX 3. END 4. BY VALUE\nCHOICE : ");
                scanf("%d", &f);
                switch(f){
                    case 1:
                        head = delete_first(head);
                        break;
                    case 2:
                        printf("ENTER THE INDEX :");
                        scanf("%d", &g);
                        head = delete_any(head, g);
                        break;
                    case 3:
                        head = delete_last(head);
                        break;
                    case 4:
                        display(head);
                        printf("ENTER THE VALUE :");
                        scanf("%d", &h);
                        head = delete_Value(head, h);
                        break;
                    default:
                        printf("WRONG INPUT!\n");
                }
                display(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                head = sort(head);
                display(head);
                break;
            case 5:
                head = reverse(head);
                display(head);
                break;
            case 6:
                ch = 6;
                break;
            default:
                printf("WRONG CHOICE!\n");
        }
    }
    return 0;
}
