#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* infixTopostfix(char* infix);

int main() {
    
    char ch[100];
    printf("ENTER INFIX :");
    scanf("%s",ch);
    printf("POSTFIX EXPRESSION : %s",infixTopostfix(ch));

return 0;
}

struct stack{
    int size;
    int top;
    char *arr;
};

int top(struct stack *ptr){
    return ptr->arr[ptr->top];
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
void push(struct stack *ptr,char data){
    if(isFull(ptr)){
        printf("STACK OVERFLOWED\n");
    }
    ptr->top++;
    ptr->arr[ptr->top] = data;
}

char pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("STACK UNDERFLOW!\n");
        return -1;
    }

    char data = ptr->arr[ptr->top];
    ptr->top--;
    return data;   
}

int precedence(char ch){
    if(ch == '*' || ch == '/'){
        return 3;
    }
    else if(ch == '+' || ch == '-'){
        return 2;
    }
    else{
        return 0;
    }
}

int isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
        return 1;
    }
    else{
        return 0;
    }
}

char* infixTopostfix(char* infix){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size=100;
    s->top=-1;
    s->arr=(char*)malloc(s->size*sizeof(char));
    char *postfix = (char*)malloc((strlen(infix)+1)*sizeof(char));
    int i = 0,j = 0;
    while(infix[i]!= '\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else{
            if(precedence(infix[i]) > precedence(top(s))){
                push(s,infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(s);
                j++;
            }
        }
    }
    while(!isEmpty(s)){
        postfix[j] = pop(s);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}