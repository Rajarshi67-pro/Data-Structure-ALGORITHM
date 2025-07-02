#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* create(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("FAILED TO CREATE NODE !!\n");
        exit(1);
    }
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

node* insert(node* root, int data) {
    if (root == NULL)
        return create(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

node* minValueNode(node* root) {
    node* current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

node* delete(node* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = delete(root->left, data);
    else if (data > root->data)
        root->right = delete(root->right, data);
    else {
        if (root->left == NULL) {
            node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }
        
        node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
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

void traverse(node* root, int order) {
    if (root == NULL) {
        printf("TREE IS EMPTY!\n");
        return;
    }
    
    switch (order) {
        case 1:
            printf("PREORDER TRAVERSAL: ");
            preorder(root);
            break;
        case 2:
            printf("INORDER TRAVERSAL: ");
            inorder(root);
            break;
        case 3:
            printf("POSTORDER TRAVERSAL: ");
            postorder(root);
            break;
        default:
            printf("INVALID TRAVERSAL TYPE!\n");
            return;
    }
    printf("\n");
}

int main() {
    node* root = NULL;
    int ch,ch1, data;

    while (ch != 5) {
        printf("MENU : 1. INSERT NODE 2. DELETE NODE 3. TRAVERSAL 4. EXIT\nCHOICE : ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
            	while(data != -1){
                printf("ENTER THE VALUE TO INSERT ( -1 TO EXIT ): ");
                scanf("%d", &data);
                if (data != -1 ){
                root = insert(root, data);
                }}
                break;
            case 2:
                printf("ENTER THE VALUE TO DELETE: ");
                scanf("%d", &data);
                root = delete(root, data);
                break;
            case 3:
                ch1 = 0;
                while(ch1 != 4){
    		    printf("TRAVERSAL : 1. PREORDER TRAVERSAL 2. INORDER TRAVERSAL 3. POSTORDER TRAVERSAL 4. GO TO MAIN MENU\nCHOICE :");
    		    scanf("%d",&ch1);
                if(ch1 != 4){
                traverse(root, ch1);
                }
                }
                break;
            case 4:
            	printf("....EXITING....\n");
            	ch = 5;
            	break;
            default:
                printf("INVALID CHOICE !\n");
                break;
        }
    }

    return 0;
}
 
