#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *create(int data){
	node *newnode = (node*)malloc(sizeof(node));
	if (newnode == NULL){
		printf("FAILED TO CREATE NODE !!\n");
		exit(1);
	}
	newnode->data = data;
	newnode->left = newnode->right = NULL;
	return newnode;
}

void preorder(node *root){
	if(root == NULL)return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(node *root){
	if(root == NULL)return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

void postorder(node *root){
	if(root == NULL)return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}


node *insert(node *root , int data){
	if(root == NULL)return create(data);
	node *temp;
	node *queue[100];
	int front = 0,rear = 0;
	queue[rear++] = root;
	while(front < rear ){
		temp = queue[front++];
		if(temp->left == NULL){
			temp->left = create(data);
			break;
		}else{
			queue[rear++] = temp->left;
			}
		if(temp->right == NULL){
			temp->right = create(data);
			break;
		}else{
			queue[rear++] = temp->right;
			}
		}
		return root;
}

int main(){
	node *root = NULL;
	int ch , data;
	while(ch != 6 ){
		printf("MENU : 1. INSERT NODE 2. PREORDER TRAVERSAL 3. INORDER TRAVERSAL 4. POSTORDER TRAVERSAL 5. EXIT\nCHOICE :");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("ENTER THE VALUE TO INSERT :");
				scanf("%d",&data);
				root = insert(root,data);
				break;
			case 2:
				printf("PREORDER TRAVERSAL :");
				preorder(root);
				printf("\n");
				break;
			case 3:
				printf("INORDER TRAVERSAL :");
				inorder(root);
				printf("\n");
				break;
			case 4:
				printf("POSTORDER TRAVERSAL :");
				postorder(root);
				printf("\n");
				break;
			case 5:
				printf(".....EXITING.....\n");
				ch = 6;
				break;
			default:
				printf("INVALID CHOICE !\n");
				break;
			}
		}
	return 0;
}
		






