#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int size;
    int front;
    int rear;
    int *Q;
}queue;

void create(queue *q) {
    int size;
    printf("ENTER THE SIZE OF QUEUE = ");
    scanf("%d", &size);
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int*)malloc(q->size * sizeof(int));
}

void enqueue(queue *q) {
    int value;
    printf("ENTER THE ELEMENT YOU WANT TO INSERT %d: ",q->rear+1);
    scanf("%d", &value);
    if ((q->rear + 1) % q->size == q->front){
        printf("QUEUE IS FULL!\n");
        return;
    }
        if (q->front == -1) q->front = 0;
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = value;
        printf("%d ADDED SUCCESSFULLY!\n", value);

}

void dequeue(queue *q) {
    if (q->front == -1) {
        printf("QUEUE IS EMPTY!\n");
        return;
    }
        int x = q->Q[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1;
        } else {
            q->front = (q->front + 1) % q->size;
        }
        printf("%d REMOVED SUCCESSFULLY!\n", x);
}

void display(queue *q) {
    if (q->front == -1) {
        printf("QUEUE IS EMPTY!\n");
        return;
    }
        int i = q->front;
        printf("ELEMENTS :");
        while (i != q->rear) {
            printf(" %d ", q->Q[i]);
            i = (i + 1) % q->size;
        }
        printf(" %d\n", q->Q[q->rear]);
}

int main() {
    int ch = 1;
    queue *q = (queue*)malloc(sizeof(queue));
    create(q);
    while (ch != 0) {
        printf("...................................   MENU   ..................................\n1. ENTER AN ELEMENT 2. DELETE AN ELEMENT 3. DISPLAY ELEMENTS 4. EXIT (0)\n: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                enqueue(q);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                ch = 0;
                break;
        }
    }
    free(q->Q);
    free(q);
    printf("ALLOCATED MEMORY FREE!\n");
    return 0;
}

