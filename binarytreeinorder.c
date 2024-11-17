//implementation of binary tree using linked list 
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	struct node *left;
	int data;
	struct node *right;
}node;

//create node function that allocate memory and assign data
node *createnode(int value)
{
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=value;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

//inorder function to print the node
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\n",root->data);
		inorder(root->right);
	}
}

//main function
int main()
{
	node *root=NULL;
	root=createnode(10);
	root->left=createnode(20);
	root->right=createnode(30);
	root->left->left=createnode(40);
	root->left->right=createnode(50);
	root->right->left=createnode(60);
	root->right->right=createnode(70);
	printf("Inorder traversal of the tree\n");
	inorder(root);
	return 0;
}
	
	
