//Write a menu driven C program to implement double ended queue using array.

#include <stdio.h>
#include <stdlib.h>
struct Queue
{
	int rear;
	int front;
	int size;
	int* que;
};
int front_enqueue(struct Queue* q)
{
	int val;
	if(((q->front==0)&&(q->rear==q->size-1))||(q->front==q->rear+1))
	{
		printf("Queue is full\n");
		return 0;
	}
	if(q->front==-1)
		q->front=q->rear=0;
	else if(q->front==0)
		q->front=q->size-1;
	else
		q->front--;
	printf("Enter element: ");
	scanf("%d",&val);
	q->que[q->front]=val;
}
int rear_enqueue(struct Queue* q)
{
	int val;
	if(((q->front==0)&&(q->rear==q->size-1))||(q->front==q->rear+1))
	{
		printf("Queue is full\n");
		return 0;
	}
	if(q->front==-1)
		q->front=q->rear=0;
	else if(q->rear==q->size-1)
		q->rear=0;
	
	else
		q->rear++;
	printf("Enter element: ");
	scanf("%d",&val);
	q->que[q->rear]=val;
}
int front_dequeue(struct Queue* q)
{
	if(q->front==-1)
	{
		printf("Queue is empty\n");
		return 0;
	}
	if(q->front==q->rear)
		q->front=q->rear=-1;
	else if(q->front==q->size-1)
		q->front=0;
	else
		q->front++;
	printf("Element dequeued\n");
}
int rear_dequeue(struct Queue* q)
{
	if(q->front==-1)
	{
		printf("Queue is empty\n");
		return 0;
	}
	if(q->front==q->rear)
		q->front=q->rear=-1;
	else if(q->rear==0)
		q->front=q->size-1;
	else
		q->rear--;
	printf("Element dequeued\n");
}
void display(struct Queue* q)
{
	if(q->front==-1)
	{
		printf("\nQueue is empty\n");
		return;
	}
	printf("\nPrinting the queue:\n");
	if(q->rear>=q->front)
	{
		for(int i=q->front;i<=q->rear;i++)
			printf("%d ",q->que[i]);
	}
	else
	{
		for(int i=q->front;i<q->size;i++)
			printf("%d ",q->que[i]);
		for(int i=0;i<=q->rear;i++)
			printf("%d ",q->que[i]);
	}
	printf("\n");
}
int main()
{
	int size,c;
	printf("Enter the size of the queue: ");
	scanf("%d",&size);
	struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
	q->size=size;
	q->front=-1;
	q->rear=0;
	q->que=(int*)malloc(q->size*sizeof(int));
	printf("\nEnter 1 to insert element from front\nEnter 2 to insert element from rear\nEnter 3 to delete element from front\nEnter 4 to delete element from rear\nEnter 5 to display\nEnter 6 to exit\n");
	while(1)
	{
		printf("Enter choice: ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				front_enqueue(q);
				break;
			case 2:
				rear_enqueue(q);
				break;
			case 3:
				front_dequeue(q);
				break;
			case 4:
				rear_dequeue(q);
				break;
			case 5:
				display(q);
				break;
			case 6:
				printf("Exiting...");
				exit(0);
			default:
				printf("Wrong Input");
		}
	}
	return 0;
}
