#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr){
    if (ptr->top == -1){
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr){
    if (ptr->top == ptr->size - 1){
        return 1;
    }
    return 0;
}

void push(struct stack *ptr,int value){
    if(isFull(ptr)){
        printf("STACK OVERFLOW!\n");
        return;
    }
    else{
        ptr -> top++;
        ptr->arr[ptr->top]=value;
        printf("%d INSERTED SUCCESSFULLY!\n",value);
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("STACK UNDERFLOW!\n");
        return -1;
    }
    else{
        int value = ptr->arr[ptr->top];
        ptr -> top--;
        return value;
    }
}

int main()
{   
    int a,b,c,d,value,i;
    struct stack *s = (struct stack *) malloc (sizeof(struct stack));
    printf("ENTER THE SIZE OF STACK WANT TO CREATE = ");
    scanf("%d",&a);
    s->size = a;
    s->top=-1;
    s->arr = (int *) malloc (s->size*(sizeof(int)));
    printf("STACK CREATED SUCCESSFULLY! (SIZE = %d)",s->size);

    do{
    printf("\n......MENU.....\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\n= ");
    scanf("%d",&b);
    switch(b){
        
        case (1):
            printf("ENTER THE ELEMENT TO BE INSERTED AT %d =",s->top+1);
            scanf("%d",&c);
            push(s,c);
            break;

        case (2):
           value = pop(s);
           printf("POPPED ELEMENT = %d\n",value);
            break;

        case (3):
            for ( i=0;i<=s->top;i++){
                printf("ELEMENT AT %d IS = %d\n",i,s->arr[i]);
            }
            break;

        case (4):
            b = 0;
            
    
    }
    d++;
    }while(b != 0);

return 0;
}