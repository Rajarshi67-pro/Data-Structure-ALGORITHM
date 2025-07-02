#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    char data;
    struct node *left;
    struct node *right;
} node;

node *create(char data) {
    node *newnode = (node*)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("FAILED TO CREATE NODE !!\n");
        exit(1);
    }
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

void inorder(node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%c ", root->data); 
    inorder(root->right);
}

node *insert(node *root, char data) {
    if (root == NULL) return create(data);
    node *temp;
    node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        temp = queue[front++];
        if (temp->left == NULL) {
            temp->left = create(data);
            break;
        } else {
            queue[rear++] = temp->left;
        }
        if (temp->right == NULL) {
            temp->right = create(data);
            break;
        } else {
            queue[rear++] = temp->right;
        }
    }
    return root;
}

int main() {
    node *root = NULL;
    char data;
    printf("INSERT THE FULL EXPRESSION (@ FOR EXIT)\n");
    while (1) {
        printf("ENTER A CHARACTER (USE @ TO STOP): ");
        scanf(" %c", &data);
        if (data == '@') break;
        root = insert(root, data);
    }
    printf("INORDER TRAVERSAL: ");
    inorder(root);
    printf("\n");
    return 0;
}
