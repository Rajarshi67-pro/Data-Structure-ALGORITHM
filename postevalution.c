#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr) {
    return ptr->top == -1;
}

int isFull(struct stack *ptr) {
    return ptr->top == ptr->size - 1;
}

void push(struct stack *ptr, int value) {
    if (isFull(ptr)) {
        printf("STACK OVERFLOW!\n");
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(struct stack *ptr) {
    if (isEmpty(ptr)) {
        printf("STACK UNDERFLOW!\n");
        return -1;
    } else {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int evaluatePostfix(char* exp, struct stack *s) {
    int i = 0;
    
    while (exp[i] != '\0') {
        if (exp[i] >= '0' && exp[i] <= '9') {
            push(s, exp[i] - '0');
        } else {
            int val1 = pop(s);
            int val2 = pop(s);
            switch (exp[i]) {
                case '+': push(s, val2 + val1); break;
                case '-': push(s, val2 - val1); break;
                case '*': push(s, val2 * val1); break;
                case '/': push(s, val2 / val1); break;
                default: printf("Invalid operator encountered: %c\n", exp[i]); return -1;
            }
        }
        i++;
    }
    return pop(s);
}

int main() {   
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (int *) malloc(s->size * sizeof(int));
    
    char exp[100];
    printf("ENTER THE POSTFIX EXPRESSION: ");
    scanf("%s", exp);
    
    int result = evaluatePostfix(exp, s);
    if (result != -1) {
        printf("Evaluation Result: %d\n", result);
    } else {
        printf("Error in evaluating the postfix expression.\n");
    }

    free(s->arr);
    free(s);

    return 0;
}