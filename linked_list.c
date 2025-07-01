#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}link;

link *create(int data){
    link *newnode = (link*)malloc(sizeof(link));
    if(newnode == NULL){
        printf("FAILED TO CREATE!\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next=NULL;
    return newnode;
}

link *insert_first(link *head , int data){
    link *ptr = create(data);
    ptr->next = head;
    return ptr;
}

link *insert_any(link *head , int index , int data){
    if(index == 0)return insert_first(head,data);
    link *p = create(data);
    link *q = head;
    int i = 0;
    while(i != index-1 && q != NULL){
        q = q->next;
        i++;
    }
    if(q == NULL){
        printf("INDEX OUT OF BOUND\n");
        free(p);
        return head;
    }
    p->next = q->next;
    q->next = p;
    return head;
}

link *insert_last(link *head , int data){
    link * p = create(data);
    if (head==NULL)
    {
        return p;
    }
    link *q = head;
    while(q->next != NULL){
        q = q->next;
    }
    q->next = p;
    return head;
    
}

link *delete_first(link *head ){
    link *p = head;
    head = head->next;
    free(p);
    return head;
}

link *delete_any(link *head , int index){
    if(head == NULL){
        printf("HEAD = NULL\n");
        return NULL;
    }
    if(index == 0){
        
        return delete_first(head);
    }
    link *p = head;
    link *q = p->next;
    int i = 0;
    while(i != index-1 && p != NULL){
        p = p->next;
        q = q->next;
        i++;
    }
    if(p==NULL){
        printf("INDEX OUT OF BOUND!\n");
        return head;
    }
    p->next = q->next;
    free(q);
    return head;
}

link *delete_last(link *head ){
    if(head == NULL){
        printf("HEAD = NULL\n");
        return NULL;
    }
    if(head->next == NULL){
        free(head);
        return NULL;
    }
    link *p = head;
    link *q = p->next;

    while(q->next != NULL){
        q = q->next;
        p=p->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct node *delete_Value(struct node *head,int value) {
    struct node *p = head;
    struct node *q = head->next;
    while(q->data != value){
        p = p->next;
        q = q->next;
    }
    p->next=q->next;
    free(q);
    return head;
        
}

void display(link *head){
    if(head == NULL){
        printf("NO ELEMENTS TO SHOW!\n");
        return;
    }
    while(head !=NULL){
        printf("%d -> ",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

link *sort(link *head){
    if(head == NULL || head->next == NULL) return head;
    link *p,*q;
    int a,x;
    printf("SORT : 1. ASCENDING 2. DESCENDING : ");
    scanf("%d",&a);
    for(p = head ; p != NULL ; p=p->next){
        for(q = p->next ; q != NULL ; q=q->next){
            if(a==1){
            if(p->data > q->data){
                x = p->data;
                p->data = q->data;
                q->data = x;
             }
            }
            if(a==2){
            if(p->data < q->data){
                x = q->data;
                q->data = p->data;
                p->data = x;
             }
            }
        }
    }
    return head;
}

link *reverse(link *head){
    link *prev = NULL;
    link *current = head;
    link * next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}


int main(){

    int a,b,c,d,e,f,g,h,i,ch;
    link *head = NULL;
    while(ch != 6){
    printf("1. INSERTION 2. DELETION 3. DISPLAY 4. SORT 5. REVERSE 6. EXIT\nCHOICE : ");
    scanf("%d",&ch);
    switch(ch){
        case 1:
                printf("INSERTION : 1. BEGINNING 2. AT ANY INDEX 3. END\nCHOICE : ");
                scanf("%d",&a);
                switch(a){
                    case 1:
                        printf("ENTER THE VALUE :");
                        scanf("%d",&b);
                        head = insert_first(head,b);
                        break;
                    case 2:
                        printf("ENTER THE VALUE :");
                        scanf("%d",&c);
                        printf("ENTER THE INDEX :");
                        scanf("%d",&d);
                        head = insert_any(head,d,c);
                        break;
                    case 3:
                        printf("ENTER THE VALUE :");
                        scanf("%d",&e);
                        head = insert_last(head,e);
                        break;
                    default:
                        printf("WRONG INPUT!\n");
                }
                display(head);
                break;
        case 2:
                printf("DELETION : 1. BEGINNING 2. AT ANY INDEX 3. END 4. BY VALUE\nCHOICE : ");
                scanf("%d",&f);
                switch(f){
                    case 1:
                        head = delete_first(head);
                        break;
                    case 2:
                        printf("ENTER THE INDEX :");
                        scanf("%d",&g);
                        head = delete_any(head,g);
                        break;
                    case 3:
                        head = delete_last(head);
                        break;
                    case 4:
                        display(head);
                        printf("ENTER THE VALUE :");
                        scanf("%d",&h);
                        head = delete_Value(head,h);
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