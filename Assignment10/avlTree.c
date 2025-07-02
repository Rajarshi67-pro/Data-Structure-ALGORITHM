#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
    int height;
} node;

int height(node* N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

node* create(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("FAILED TO CREATE NODE !!\n");
        exit(1);
    }
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    newnode->height = 1;
    return newnode;
}

node* rightRotate(node* y) {
    node* x = y->left;
    node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

node* leftRotate(node* x) {
    node* y = x->right;
    node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(node* N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

node* insert(node* root, int data) {
    if (root == NULL)
        return create(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && data < root->left->data)
        return rightRotate(root);

    if (balance < -1 && data > root->right->data)
        return leftRotate(root);

    if (balance > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

node* minValueNode(node* root) {
    node* current = root;

    while (current->left != NULL)
        current = current->left;

    return current;
}

node* deleteNode(node* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            node* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;

            free(temp);
        } else {
            node* temp = minValueNode(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preorder(node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(node* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    node* root = NULL;
    int ch,ch1,data;

    while (ch != 5) {
        printf("MENU : 1. INSERT NODE 2. DELETE NODE 3. TRAVERSAL 4. EXIT\nCHOICE : ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
            	while(data != -1){
                printf("ENTER THE VALUE TO INSERT ( -1 TO EXIT ): ");
                scanf("%d", &data);
                if(data != -1){
                root = insert(root, data);
                }
                }
                break;
            case 2:
                printf("ENTER THE VALUE TO DELETE: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 3:
            	ch1 = 0;
            	while(ch1 != 4){
            	printf("TRAVERSAL : 1. PREORDER TRAVERSAL 2. INORDER TRAVERSAL 3. POSTORDER TRAVERSAL 4. EXIT\nCHOICE :");
            	scanf("%d",&ch1);
            switch(ch1){
            case 1:
                printf("PREORDER TRAVERSAL: ");
                preorder(root);
                printf("\n");
                break;
            case 2:
                printf("INORDER TRAVERSAL: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("POSTORDER TRAVERSAL: ");
                postorder(root);
                printf("\n");
                break;
            }
            }
            
            break;
            case 4:
                printf(".....EXITING.....\n");
                ch = 5;
                break;
            default:
                printf("INVALID CHOICE !\n");
                break;
        }
    }

    return 0;
}
