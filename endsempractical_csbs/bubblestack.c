#include<stdio.h>
#include<stdlib.h>

struct Stack {
    int data[100];
    int top;

};
void init(struct Stack* s){
    s->top = -1;
}
void push(struct Stack* s,int val){
    s->data[++(s->top)]= val ;
}
int pop(struct Stack* s) {
    return s->data[(s->top)--];
}
void swap(int* a,int* b){
    struct Stack s;
    init(&s);

    push(&s,*a);
      *a = *b;
      *b = pop(&s);
}
void bubbleSort(int arr[],int n){
    for(int i=0; i<n-1;i++){
        for(int j=0; j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
void printArray(int arr[], int n) {
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);
    printArray(arr, n);

    return 0;
}