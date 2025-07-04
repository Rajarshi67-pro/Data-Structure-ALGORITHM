#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right ;
};
struct Node* newNode(int data){
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data ;
    node->left = node->right = NULL ;
    return node;
}
int levelDiff(struct Node* root) {
    if (root == NULL) return 0;

    struct Node* queue[100];   
    int front = 0, rear = 0;

    queue[rear++] = root;
    int level = 1;             
      int oddSum = 0, evenSum = 0;

while(front < rear) {
    int levelcount = rear - front ;
    
    while(levelcount--) {
        struct Node* temp = queue[front++];
        if(level %2 == 1)
            oddSum +=temp->data;
        else
            evenSum += temp->data;

        if (temp->left)
            queue[rear++] = temp->left;
        if (temp->right)
            queue[rear++] = temp->right;
                                
    }
    level++;
}
return oddSum - evenSum;
}
int main() {
     struct Node* root = newNode(40);
    root->left = newNode(25);
    root->right = newNode(35);
    root->left->left = newNode(30);
    root->left->right = newNode(50);
    root->right->left = newNode(45);
    root->right->right = newNode(60);

    int diff = levelDiff(root);
    printf("Difference between odd and even level sums: %d\n",diff);
    return 0 ;
}

