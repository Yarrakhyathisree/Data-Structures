//implementation of binary search tree traversal (inorder,preorder,postorder)
//create and display
#include<stdio.h>
#include<stdlib.h>

typedef struct bst
{
	struct bst *left;
	int data;
	struct bst *right;
}node;

//create a node function
node* createnode(int value)
{
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=value;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

//inorder function
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\n",root->data);
		inorder(root->right);
	}
}

//preorder function
void preorder(node *root)
{
	if(root!=NULL)
	{
		printf("%d\n",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
//postorder function
void postorder(node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\n",root->data);
	}
}
//main function
int main()
{
	node *root=NULL;
	root=createnode(50);
	root->left=createnode(25);
	root->left->left=createnode(20);
	root->left->right=createnode(30);
	root->right=createnode(55);
	root->right->left=createnode(52);
	root->right->right=createnode(58);
	printf("inorder traversal:\n");
	inorder(root);
	printf("postorder traversal:\n");
	postorder(root);
	printf("preorder traversal:\n");
	preorder(root);
	
}
