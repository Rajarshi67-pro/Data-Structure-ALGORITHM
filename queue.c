#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int front;
    int rear;
    int *arr;
};

void create(struct queue *q,int size){
    q->size = size;
    q->front = q->rear = -1;
    q->arr = (int*)malloc(q->size*sizeof(int));
}

void enqueue(struct queue *q,int value){
    if (q->rear == q->size-1)
    {
        printf("QUEUE IF FULL !\n");
        return;
    }
    else
    {
        q->rear++;
        q->arr[q->rear]=value;
        printf("%d ADDED SUCCESSFULLY!\n",value);
    }
}

void dequeue(struct queue *q){
    if (q->front==q->rear)
    {
        printf("QUEUE IS EMPTY !\n");
        return;
    }
    
    else
    {
        q->front++;
        int x = q->arr[q->front];
        printf("%d REMOVED SUCCESSFULLY !\n",x);
    }  
}
void reset(struct queue *q){
    {
        printf("QUEUE IS FORMATTED !\n");
        q->front = q->rear = -1;
    }
}

void display(struct queue q){
    int i;
    if(q.front==-1 && q.rear==-1){
        printf("QUEUE IS EMPTY!\n");
    }
    for(i=q.front+1;i<=q.rear;i++){
        printf("ELEMENTS : %d ",q.arr[i]);
    }
    printf("\n");

}

int main()
{
    int a,b,ch;
    struct queue q;
    printf("ENTER THE SIZE OF QUEUE = ");
    scanf("%d",&a);
    create(&q,a);
    while(ch!=5){
        printf("...................................   MENU   ..................................\n1. ENTER AN ELEMENT 2. DELETE AN ELEMENT 3. DISPLAY ELEMENTS 4. RESET 5. EXIT\n: ");
        scanf("%d",&ch);
        switch(ch){
            case (1):
                printf("ENTER THE ELEMENT WANT TO INSERT AT %d :",q.rear+1);
                scanf("%d",&b);
                enqueue(&q,b);
                break;
            case (2):
                dequeue(&q);
                break;
            case (3):
                display(q);
                break;
            case (4):
                reset(&q);
                break;
            default:
                printf("WRONG INPUT!\n");
                break;
        }

    }
return 0;
}